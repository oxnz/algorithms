#ifndef URI_H
#define URI_H

#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <string_view>

namespace m {
/**
 * @brief The uri class
 * URI = scheme:[//authority]path[?query][#fragment]
 * authority = [userinfo@]host[:port]
 */
class uri {
    using param = std::pair<std::string, std::string>;
public:
    static std::string encode(const std::string_view s);
    static std::string decode(const std::string_view s);

    uri(const std::string& raw);
    uri(const std::string &scheme,
        const std::string &authority,
        const std::string &path,
        const std::string &query,
        const std::string &fragment)
        : m_scheme(scheme), m_authority(authority), m_path(path), m_query(query), m_fragment(fragment)
    {}

    void scheme(const std::string& scheme) { m_scheme = scheme; }
    std::string scheme() const { return m_scheme; }
    void authority(const std::string &s) { m_authority = s; }
    std::string authority() const { return m_authority.str(); }
    void path(const std::string& path) { m_path = path; }
    std::string path() const { return m_path; }
    void query(const std::string &s) { m_query = s; }
    std::string query() const { return m_query.str(); }
    void fragment(const std::string& fragment) { m_fragment = fragment; }
    std::string fragment() const { return m_fragment; }

    void userinfo(const std::string &userinfo) { m_authority.userinfo = userinfo; }
    std::string userinfo() const { return m_authority.userinfo; }
    void host(const std::string& host) { m_authority.host = host; }
    std::string host() const { return m_authority.host; }
    void port(uint16_t port) { m_authority.port = port; }
    uint16_t port() const { return m_authority.port; }
    std::vector<param> params() const { return m_query.params; }

    std::string str() const;

    friend std::ostream &operator<<(std::ostream &os, const uri &uri) { return os << uri.str(); }

private:
    std::string m_scheme;
    struct authority {
        authority() = default;
        authority(const std::string& s);
        std::string userinfo;
        std::string host;
        uint16_t port {0};
        std::string str() const;
    } m_authority;
    std::string m_path;
    struct query {
        query() = default;
        query(const std::string& s);
        std::string str() const;
        std::vector<param> params;
    } m_query;
    std::string m_fragment;
};
}

#endif // URI_H
