#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class MyHashSet {
private:
	vector<list<int>> data;
	static const int base = 769;
	static int hash(int key) {
		return key % base;
	}
public:
	/** Initialize your data structure here. */
	MyHashSet() : data(base) {}

	void add(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				return;
			}
		}
		data[h].push_back(key);
	}

	void remove(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				data[h].erase(it);
				return;
			}
		}
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				return true;
			}
		}
		return false;
	}
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

//使用时，把该main函数粘到lecMain.cpp里
//int main()
//{
//	MyHashSet* obj = new MyHashSet();
//	obj->add(1);      // set = [1]
//	obj->add(2);      // set = [1, 2]
//	obj->contains(1); // 返回 True
//	obj->contains(3); // 返回 False ，（未找到）
//	obj->add(2);      // set = [1, 2]
//	obj->contains(2); // 返回 True
//	obj->remove(2);   // set = [1]
//	obj->contains(2); // 返回 False ，（已移除）
//	return 0;
//}
