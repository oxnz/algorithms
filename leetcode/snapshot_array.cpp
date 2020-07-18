//
//  snapshot_array.cpp
//  leetcode
//
//  Created by Max Zhang on 2020/2/16.
//

#include "leetcode.hpp"

/**
 * @brief Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
class SnapshotArray {
public:
    SnapshotArray(int length) : m_size(length) {}
    
    uint64_t key(int snap_id, int index) const { return ((uint64_t)snap_id << 32) | index; }
    void set(int index, int val) {
        if (index < 0 || index >= m_size) throw std::out_of_range("invalid index");
        m_store[key(m_snap_id, index)] = val;
    }
    
    int snap() {
        return m_snap_id++;
    }
    
    int get(int index, int snap_id) {
        if (index < 0 || index >= m_size) throw std::out_of_range("invalid index");
        for (; snap_id >= 0; --snap_id) {
            auto p = m_store.find(key(snap_id, index));
            if (p != m_store.end()) return p->second;
        }
        return 0;
    }
private:
    int m_size;
    int m_snap_id{0};
    std::unordered_map<uint64_t, int> m_store;
};

TEST(snapshot_array, case_1) {
    SnapshotArray arr(3);
    arr.set(0, 5);
    EXPECT_EQ(arr.get(0, 0), 5);
    arr.snap();
    arr.set(0, 6);
    EXPECT_EQ(arr.get(0, 0), 5);
    arr.snap();
    EXPECT_EQ(arr.get(0, 1), 6);
}

TEST(snapshot_array, case_2) {
    SnapshotArray arr(2);
    arr.set(0, 12);
    EXPECT_EQ(arr.get(0, 0), 12);
    arr.snap();
    arr.snap();
    EXPECT_EQ(arr.get(1, 0), 0);
}
