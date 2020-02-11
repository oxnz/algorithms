#ifndef RAW_H
#define RAW_H

#include <memory>

namespace m {

template <typename T, typename Allocator=std::allocator<T>>
class raw {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
private:
    using __allocator_traits = std::allocator_traits<Allocator>;
    Allocator m_allocator;
    bool m_raw;
    std::byte m_store[sizeof (T)];
public:
    raw() : m_raw(true) {}
    raw(raw&) = delete;
    raw(raw&&) = delete;
    raw& operator=(raw&) = delete;
    raw& operator=(raw&&) = delete;
    ~raw() { clear(); }

    bool empty() const { return m_raw; }
    void clear() { if (!empty()) __allocator_traits::destroy(m_allocator, (pointer)std::addressof(m_store)); }
    pointer operator->() { return std::addressof(m_store); }
    reference operator*() { return *operator->(); }

    template <typename... Args>
    reference emplace(Args &&... args) noexcept(noexcept (value_type(std::forward<Args>(args)...))) {
        auto p = std::addressof(m_store);
        __allocator_traits::construct(p, std::forward<Args>(args)...);
        m_raw = false;
        return *p;
    }
};

}

#endif // RAW_H
