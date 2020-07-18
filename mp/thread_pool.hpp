//
//  thread_pool.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/4.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef thread_pool_hpp
#define thread_pool_hpp

#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <queue>

namespace multiprocessing {
<<<<<<< HEAD
template<typename T>
class concurrent_queue {
public:
    concurrent_queue() {}
    concurrent_queue(const concurrent_queue &) = delete;
    concurrent_queue &operator=(const concurrent_queue &) = delete;

    void push(const T &val) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(val);
    }
    void push(T &&val) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_queue.push(std::move(val));
    }
    bool empty() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }
    bool pop(T &val) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_queue.empty())
            return false;
        val = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }

private:
    mutable std::mutex m_mutex;
    std::queue<T> m_queue;
};

class thread_pool {
    using size_type = std::vector<std::thread>::size_type;
    using lock_type = std::unique_lock<std::mutex>;

public:
    thread_pool(size_type nworker = std::thread::hardware_concurrency())
=======
	template <typename T>
	class concurrent_queue {
	public:
		concurrent_queue() {}
        concurrent_queue(const concurrent_queue& rhs) {
            std::lock_guard<std::mutex> lock(rhs.m_mutex);
            m_queue = rhs.m_queue;
        }
		concurrent_queue& operator=(const concurrent_queue&) = delete;
		
		void push(T val) {
			std::lock_guard<std::mutex> lock(m_mutex);
			m_queue.push(std::move(val));
            m_cond_v.notify_one();
		}
        void pop(T& val) {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_cond_v.wait(lock, [this] { return !m_queue.empty(); });
			val = std::move(m_queue.front());
            m_queue.pop();
        }
        std::shared_ptr<T> pop() {
            std::unique_lock<std::mutex> lock(m_mutex);
            m_cond_v.wait(lock, [this] { return !m_queue.empty(); });
			auto ptr = std::make_shared(std::move(m_queue.front()));
            m_queue.pop();
            return ptr;
        }
        bool try_pop(T& val) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_queue.empty()) return false;
			val = std::move(m_queue.front());
            m_queue.pop();
            return true;
        }
        std::shared_ptr<T> try_pop() {
            std::lock_guard<std::mutex> lock(m_mutex);
            if (m_queue.empty()) return {};
			auto ptr = std::make_shared(std::move(m_queue.front()));
            m_queue.pop();
            return ptr;
        }
		bool empty() const {
			std::lock_guard<std::mutex> lock(m_mutex);
			return m_queue.empty();
		}
	private:
		mutable std::mutex m_mutex;
        std::condition_variable m_cond_v;
		std::queue<T> m_queue;
	};
	
	class thread_pool {
		using size_type = std::vector<std::thread>::size_type;
		using lock_type = std::unique_lock<std::mutex>;
	public:
		thread_pool(size_type nworker = std::thread::hardware_concurrency())
>>>>>>> ab703f00fc1e1002e956538795856139bd1ae5e4
        : m_tasks(), m_mutex(), m_cond_v(), m_workers(), m_cmd(command::run)
    {
        if (0 == nworker)
            nworker = std::thread::hardware_concurrency();
        m_workers.reserve(nworker);
        try {
            for (size_type i = 0; i < nworker; ++i)
                m_workers.emplace_back(&thread_pool::_exec, this);
        } catch (...) {
            join();
            throw;
        }
    }
    thread_pool(const thread_pool &) = delete;
    thread_pool(thread_pool &&) = delete;
    thread_pool &operator=(const thread_pool &) = delete;
    thread_pool &operator=(thread_pool &&) = delete;
    ~thread_pool() { join(); }

    size_type size() const { return m_workers.size(); }
    size_type capacity() const { return m_workers.capacity(); }

    void pause() {
        {
            lock_type lock(m_mutex);
            m_cmd = command::pause;
        }
        m_cond_v.notify_all();
    }
    void resume() {
        {
            lock_type lock(m_mutex);
            m_cmd = command::run;
        }
        m_cond_v.notify_all();
    }
    void stop() {
        {
            lock_type lock(m_mutex);
            m_cmd = command::stop;
        }
        m_cond_v.notify_all();
    }
    void abort() {
        {
            lock_type lock(m_mutex);
            m_cmd = command::abort;
        }
        m_cond_v.notify_all();
        join();
    }
    void join() {
        {
            lock_type lock(m_mutex);
            if (m_cmd == command::run || m_cmd == command::pause)
                m_cmd = command::stop;
        }
        m_cond_v.notify_all();
        std::for_each(m_workers.begin(), m_workers.end(), std::mem_fn(&std::thread::join));
        {
            lock_type lock(m_mutex);
            m_workers.clear();
        }
    }

    template<typename Fn, typename... Args>
    auto emplace(Fn &&f, Args &&... args) -> std::future<std::result_of_t<Fn(Args...)>>
    {
        using result_type = std::result_of_t<Fn(Args...)>;
        auto taskp = std::make_shared<std::packaged_task<result_type()>>(
            std::bind(std::forward<Fn>(f), std::forward<Args>(args)...));
        std::future<result_type> future = taskp->get_future();
        {
            lock_type lock(m_mutex);
            if (m_cmd != command::run) {
                throw std::runtime_error("submit on a not running thread pool");
            }
            m_tasks.emplace([taskp] { (*taskp)(); });
        }
        m_cond_v.notify_one();
        return future;
    }

private:
    void _exec() {
        for (;;) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(m_mutex);
                m_cond_v.wait(lock, [this]() -> bool {
                    return m_cmd != command::run || !m_tasks.empty();
                });
                switch (m_cmd) {
                case command::run:
                    break;
                case command::pause:
                    continue;
                case command::abort:
                    return;
                case command::stop:
                    if (m_tasks.empty())
                        return;
                    break;
                }
                if (m_cmd != command::run && m_tasks.empty())
                    return;
                task = std::move(m_tasks.front());
                m_tasks.pop();
            }
            task();
        }
    }

private:
    std::queue<std::function<void()>> m_tasks;
    std::mutex m_mutex;
    std::condition_variable m_cond_v;
    std::vector<std::thread> m_workers;
    enum class command { run, pause, stop, abort } m_cmd;
};
} // namespace multiprocessing

#endif /* thread_pool_hpp */
