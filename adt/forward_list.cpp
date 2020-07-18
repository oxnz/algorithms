//
//  forward_list.cpp
//  adt
//
//  Created by Max Zhang on 2020/2/10.
//


#include <iostream>
#include <gtest/gtest.h>
#include "forward_list.h"
#include "adt.h"

using namespace std;

template <typename T>
ForwardListNode<T>* reverse(ForwardListNode<T> *head) {
    if (nullptr == head) return head;
    typedef ForwardListNode<T> Node;
    Node *pre = head;
    Node *p = pre->next;
    Node *nxt;
    while (nullptr != p) {
        nxt = p->next;
        p->next = pre;
        pre = p;
        p = nxt;
    }
    head->next = nullptr;
    return pre;
}

template <typename T>
void list_insert(ForwardListNode<T>& list, ForwardListNode<T>& node) {
    node.next = list.next;
    list.next = &node;
}

template <typename T>
void list_erase(ForwardListNode<T>& list, ForwardListNode<T>* p) {
}

int test_list() {
    ForwardListNode<int> list(0);
    ForwardListNode<int> nodes[10]{1,2,3,4,5,6,7,8,9,10};
    for (int i = 0; i < 10; ++i) {
        list_insert(list, nodes[i]);
    }

    echo(&list);
    ForwardListNode<int> *p = reverse(&list);
    echo(p);
    list_erase(list, &nodes[4]);
    list_erase(list, &nodes[6]);
    list_erase(list, &nodes[8]);
    echo(reverse(p));

    return 0;
}

template <typename T>
ForwardListNode<T>* reverse2(ForwardListNode<T>* head) {
    if (nullptr == head || nullptr == head->next) return head;
    ForwardListNode<T>* p = head->next;
    ForwardListNode<T>* next = p->next;
    p->next = head;
    head->next = reverse2(next);
    return p;
}

TEST(list, reverse2) {
    using Node = ForwardListNode<int>;
    Node nodes[5] {1, 2, 3, 4, 5};
    int expected[] {2, 1, 4, 3, 5};
    for (int i = 0; i < 4; ++i) {
        nodes[i].next = &nodes[i+1];
    }
    EXPECT_TRUE(nodes[1].next == &nodes[2]);
    EXPECT_TRUE(nodes[4].next == nullptr);
    Node *lst = reverse2<int>(&nodes[0]);
    int i = 0;
    for (Node* p = lst; p; p = p->next) {
        EXPECT_EQ(expected[i++], p->value);
    }
    EXPECT_EQ(i, 5);
    lst = nullptr;
    EXPECT_EQ(nullptr, reverse2<int>(lst));
}
