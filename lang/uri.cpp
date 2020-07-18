#include <gtest/gtest.h>
#include "uri.h"

std::string m::uri::encode(const std::string_view s) {
    std::ostringstream oss;
    oss << std::hex;
    for (unsigned char c : s) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')
                || c == '-' || c == '.' || c == '_' || c == '~')
            oss << (char)c;
        else oss << '%' << std::setfill('0') << std::setw(2) <<  (unsigned short)c;
    }
    return oss.str();
}

std::string m::uri::decode(const std::string_view s) {
    std::ostringstream oss;
    for (auto const *p = s.data(); *p;) {
        if (*p == '%') {
            if (*(p+1) == 0 || *(p+2) == 0) throw std::invalid_argument("invalid input");
            oss << static_cast<unsigned char>((p[1] >= 'a' ? p[1]-'a'+10 : p[1] - '0')*16 + (p[2] >= 'a' ? p[2]-'a'+10:p[2]-'0'));
            p += 3;
        } else oss << *p++;
    }
    return oss.str();
}

m::uri::uri(const std::string &raw) {
    std::string::size_type p0 = 0, p = raw.find(':');
    if (p == std::string::npos) throw std::invalid_argument("malformed uri: no scheme");
    m_scheme = raw.substr(p0, p);
    p0 = p+1;
    if (raw.find("//", p0) == p0) { // authority
        p0 += 2;
        p = raw.find('/', p0);
        auto s = raw.substr(p0, p-p0);
        if (p == std::string::npos && s.empty())
            throw std::invalid_argument("malformed uri: invalid authority");
        m_authority = s;
        p0 = p;
    }
    if ((p = raw.find('?', p0)) != std::string::npos) { // query
        m_path = raw.substr(p0, p-p0);
        p0 = p+1;
        if ((p = raw.find('#', p0)) != std::string::npos) {
            auto s = raw.substr(p0, p-p0);
            m_query = s;
            p0 = p;
        } else {
            query(raw.substr(p0));
        }
    }
    if ((p = raw.find('#', p0)) != std::string::npos) { // fragment
        if (m_path.empty()) m_path = raw.substr(p0, p-p0);
        m_fragment = raw.substr(p+1);
    }
    if (m_path.empty()) m_path = raw.substr(p0);
}

std::string m::uri::str() const {
    std::ostringstream oss;
    oss << m_scheme << ":";
    auto s = authority();
    if (!s.empty()) oss << "//" << s;
    oss << m_path;
    s = query();
    if (!s.empty()) oss << "?" << s;
    if (!m_fragment.empty()) oss << "#" << m_fragment;
    return oss.str();
}

m::uri::authority::authority(const std::string &s) {
    auto p0 = s.find('@');
    if (p0 != std::string::npos)
        userinfo = s.substr(0, p0++);
    else p0 = 0;
    auto p1 = s.find(':', p0);
    host = s.substr(p0, p1 - p0);
    if (p1 != std::string::npos)
        port = (uint16_t) std::stoi(s.substr(p1 + 1));
}

std::string m::uri::authority::str() const {
    std::ostringstream oss;
    if (!userinfo.empty())
        oss << userinfo << '@';
    oss << host;
    if (port)
        oss << ':' << port;
    return oss.str();
}

m::uri::query::query(const std::string &s) {
    if (s.empty()) return;
    std::istringstream iss(s+'&');
    std::string key, val;
    while (std::getline(iss, key, '=') && std::getline(iss, val, '&'))
        params.emplace_back(key, val);
}

std::string m::uri::query::str() const {
    if (params.empty()) return {};
    std::ostringstream oss;
    for (const auto& p : params)
        oss << '&' << p.first << '=' << p.second;
    return oss.str().substr(1);
}

TEST(uri, uri) {
    std::string scheme = "http";
    std::string authority = "www.eclipse.org";
    std::string path = "/info";
    std::string query = "first_name=max&last_name=z";
    std::string fragment = "main";
    std::string s = scheme + "://" + authority + path + "?" + query + "#" + fragment;
    m::uri uri(s);
    EXPECT_EQ(uri.scheme(), scheme);
    EXPECT_EQ(uri.authority(), authority);
    EXPECT_EQ(uri.path(), path);
    EXPECT_EQ(uri.query(), query);
    EXPECT_EQ(uri.fragment(), fragment);
    EXPECT_EQ(uri.str(), s);
}

TEST(uri, mailto) {
    std::string scheme = "mailto";
    std::string path = "admin@localhost";
    const std::string s = scheme + ':' + path;
    m::uri uri(s);
    EXPECT_EQ(uri.scheme(), scheme);
    EXPECT_TRUE(uri.authority().empty());
    EXPECT_EQ(uri.path(), path);
    EXPECT_TRUE(uri.query().empty());
    EXPECT_TRUE(uri.fragment().empty());
    EXPECT_EQ(uri.str(), s);
}

TEST(uri, authority) {
    m::uri uri("http://www.eclipse.org/info?first_name=max&last_name=z#main");
    EXPECT_TRUE(uri.userinfo().empty());
    EXPECT_EQ(uri.host(), "www.eclipse.org");
    EXPECT_EQ(uri.port(), 0);
}

TEST(uri, path) {
    m::uri uri("http://www.eclipse.org/info?first_name=max&last_name=z#main");
    EXPECT_EQ(uri.path(), "/info");
}

TEST(uri, query) {
    m::uri uri("http://www.eclipse.org/info?first_name=max&last_name=z#main");
    auto params = uri.params();
    EXPECT_EQ(params.size(), 2);
    auto p = std::pair<std::string, std::string>("first_name", "max");
    EXPECT_EQ(params.front(), p);
    p = {"last_name", "z"};
    EXPECT_EQ(params.back(), p);
}

TEST(uri, fragment) {
    m::uri uri("http://www.eclipse.org/info?first_name=max&last_name=z#main");
    EXPECT_EQ(uri.fragment(), "main");
}

TEST(uri, encode) {
    std::string s = "http://www.eclipse.org/info?first_name=max&last_name=z#main";
    EXPECT_EQ(m::uri::encode("\v"), "%0b");
    EXPECT_EQ(m::uri::encode("Ā"), "%c4%80");
    EXPECT_EQ(m::uri::encode("Ē"), "%c4%92");
    for (unsigned char i = 'a'; i <= 'z'; ++i) {
        s = std::string(1, i);
        EXPECT_EQ(m::uri::encode(s), s);
    }
}

TEST(uri, decode) {
    EXPECT_EQ(m::uri::decode("%0b"), "\v");
    EXPECT_EQ(m::uri::decode("%2b"), "+");
    std::string s = "http://www.eclipse.org/info?first_name=max&last_name=z#main";
    EXPECT_EQ(m::uri::decode(m::uri::encode(s)), s);
}
