//
//  parallel.hpp
//  Interview
//
//  Created by 云心逸 on 2019/1/3.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#ifndef parallel_hpp
#define parallel_hpp

#include <iostream>
#include <atomic>
#include <thread>

namespace mp {
	class spinlock_mutex {
		std::atomic_flag m_flag;
	public:
		spinlock_mutex() : m_flag(ATOMIC_FLAG_INIT) {}
		void lock() {
			while (m_flag.test_and_set(std::memory_order_acquire))
				;
		}
		void unlock() {
			m_flag.clear(std::memory_order_release);
		}
	};
}

#endif /* parallel_hpp */
