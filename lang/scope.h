#ifndef SCOPE_H
#define SCOPE_H

#include <exception>

template<typename Fn>
class scope_exit {
public:
    scope_exit(const Fn &fn) : m_fn(fn) {}
    scope_exit(const scope_exit&) = delete;
    scope_exit(scope_exit&&) = delete;
    scope_exit& operator=(scope_exit&) = delete;
    scope_exit& operator=(scope_exit&&) = delete;
    ~scope_exit() {
#ifdef DEBUG
        std::cout << (m_errc == std::uncaught_exceptions()
                          ? "~scope_exit() called normally\n"
                          : "~scope_exit() called during stack unwinding\n");
#endif
        m_fn();
    }

private:
    int m_errc{std::uncaught_exceptions()};
    Fn m_fn;
};

template<typename Fn>
class scope_success {
public:
    scope_success(const Fn &fn) : m_fn(fn) {}
    scope_success(const scope_success&) = delete;
    scope_success(scope_success&&) = delete;
    scope_success& operator=(scope_success&) = delete;
    scope_success& operator=(scope_success&&) = delete;
    ~scope_success() {
        if (m_errc >= std::uncaught_exceptions())
            m_fn();
    }

private:
    int m_errc{std::uncaught_exceptions()};
    Fn m_fn;
};

template<typename Fn>
class scope_failure {
public:
    scope_failure(const Fn &fn)  : m_fn(fn) {}
    scope_failure(const scope_failure&) = delete;
    scope_failure(scope_failure&&) = delete;
    scope_failure& operator=(scope_failure&) = delete;
    scope_failure& operator=(scope_failure&&) = delete;
    ~scope_failure() {
        if (m_errc < std::uncaught_exceptions())
            m_fn();
    }

private:
    int m_errc{std::uncaught_exceptions()};
    Fn m_fn;
};

#endif // SCOPE_H
