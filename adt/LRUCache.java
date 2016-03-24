/*
 * Filename:	LRUCache.java
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2015-09-04 11:48:02 CST]
 * Last-update:	2015-09-04 11:48:02 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

import java.util.Map;
import java.util.HashMap;

public class LRUCache {

	class Node {
		int key;
		int value;
		Node pre;
		Node nxt;

		public Node(int key, int value) {
			this.key = key;
			this.value = value;
		}
	}

	int capacity;
	Map<Integer, Node> map = new HashMap<Integer, Node>();
	Node head = null;
	Node tail = null;

    public LRUCache(int capacity) {
		this.capacity = capacity;
    }

	public int get(int key) {
		Node node = map.get(key);
		if (null == node) {
			return -1;
		} else {
			remove(node);
			setHead(node);
			return node.value;
		}
	}

	public void remove(Node node) {
		if (node.pre != null) {
			node.pre.nxt = node.nxt;
		} else {
			head = node.nxt;
		}
		if (node.nxt != null) {
			node.nxt.pre = node.pre;
		} else {
			tail = node.pre;
		}
	}

	public void setHead(Node node) {
		node.nxt = head;
		node.pre = null;

		if (head != null) {
			head.pre = node;
		}

		head = node;

		if (tail == null) {
			tail = head;
		}
	}

	public void set(int key, int value) {
		Node node = map.get(key);
		if (node == null) {
			node = new Node(key, value);
			if (map.size() > capacity) {
				map.remove(tail.key);
				remove(tail);
				setHead(node);
			} else {
				setHead(node);
			}
			map.put(key, node);
		} else {
			node.value = value;
			remove(node);
			setHead(node);
		}
	}

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}

