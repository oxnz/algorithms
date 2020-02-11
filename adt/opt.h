#ifndef OPT_H
#define OPT_H

#include <memory>

namespace m {

template<typename T>
class optional {
public:
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    optional() : m_ptr() {}
    optional(T v) : m_ptr(std::make_unique<T>(v)) {}

    bool empty() const { return nullptr == m_ptr; }

    reference value() { return *m_ptr; }
    const_reference value() const { return *m_ptr; }
    explicit operator bool() const noexcept { return !empty(); }
    bool operator!() const noexcept { return empty(); }
    bool operator==(const optional& o) { return m_ptr == o.m_ptr; }
    bool operator!=(const optional& o) { return !(*this == o); }

private:
    std::unique_ptr<value_type> m_ptr;
};

} // namespace m

#endif // OPT_H
