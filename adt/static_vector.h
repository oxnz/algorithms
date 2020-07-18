#ifndef STATIC_VECTOR_H
#define STATIC_VECTOR_H

#include <memory>

namespace m {

template<typename T, size_t N>
class static_vector
{
public:
    using size_type = size_t;
    using value_type = T;
    using reference = value_type&;
    using const_reference =  const value_type&;
    using pointer = value_type*;
    using iterator = pointer;
    static_vector() {}
    ~static_vector() {
        while (!empty()) pop_back();
    }
    size_type size() const { return m_size; }
    size_type capacity() const { return N; }
    bool empty() const { return size() == 0; }

    iterator begin() { return &m_vec[0]; }
    iterator end() { return std::next(m_vec); }

    reference at(size_type i) { return const_cast<reference>(static_cast<const static_vector&>(*this).at(i)); }
    const_reference at(size_type i) const { if (!(i < m_size)) throw std::out_of_range(__PRETTY_FUNCTION__); return m_vec[i]; }
    reference operator[](size_type i) { return m_vec[i]; }
    const_reference operator[](size_type i) const { return m_vec[i]; }
    reference front() { return at(0); }
    const_reference front() const { return at(0); }
    reference back() { return at(m_size-1); }
    const_reference back() const { return at(m_size-1); }

    iterator push_back(const_reference v) {
        if (m_size == N) throw std::overflow_error("insufficient capacity");
        pointer p = std::addressof(m_vec[m_size]);
        m_allocator.construct(p, v);
        ++m_size;
        return p;
    }
    template <typename... Args>
    iterator emplace_back(Args... args) {
        if (m_size == N) throw std::overflow_error("insufficient capacity");
        pointer p = std::addressof(m_vec[m_size]);
        m_allocator.construct(p, std::forward<Args>(args)...);
        ++m_size;
        return p;
    }
    void pop_back() {
        if (empty()) throw std::underflow_error("empty");
        m_allocator.destroy(std::addressof(m_vec[m_size-1]));
        --m_size;
    }
private:
    std::allocator<value_type> m_allocator;
    size_type m_size{0};
    union {
        std::byte m_raw[sizeof (T)*N];
        value_type m_vec[N];
    };
};

}

#endif // STATIC_VECTOR_H
