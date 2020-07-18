//
//  ipv4_addr.hpp
//  lang
//
//  Created by Max Zhang on 2020/2/15.
//

#ifndef ipv4_addr_hpp
#define ipv4_addr_hpp

#include <sstream>
#include <string>

namespace m {
class ipv4_addr {
public:
    inline static uint32_t ANY = 0;
    inline static uint32_t NONE = 0xffffffff;
    inline static uint32_t LOOPBACK = 0x0100007f;

    ipv4_addr(uint32_t raw) : m_raw(raw) {}
    ipv4_addr() : ipv4_addr(0) {}
    ipv4_addr(const std::string& s) {
        uint32_t i = 0, w = 0, par = 0;
        for (auto c : s + '.') {
            if (c == '.') {
                if (w == 0 || w > 3 || i > 4 || par > 255) throw std::invalid_argument("invalid ip");
                m_vec[i++] = par;
                w = 0;
                par = 0;
            } else if (c >= '0' && c <= '9') {
                ++w;
                par = par*10 + c - '0';
            } else throw std::invalid_argument("invalid char");
        }
    }

    std::string str() const {
        std::ostringstream oss;
        oss << +m_vec[0] << '.' << +m_vec[1] << '.' << +m_vec[2] << '.' << +m_vec[3];
        return oss.str();
    }
private:
    union {
        uint32_t m_raw;
        uint8_t m_vec[4];
    };
};
}

#endif /* ipv4_addr_hpp */
