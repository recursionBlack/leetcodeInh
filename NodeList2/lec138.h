#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
	Node(int _val, Node*p,Node*q) {
		val = _val;
		next = p;
		random = q;
	}
};


class Solution138 {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) {
			return nullptr;
		}
		//	第一次遍历，在原链表中穿插新链表。
		for (Node* node = head; node != nullptr; node = node->next->next) {
			Node* nodeNew = new Node(node->val);
			nodeNew->next = node->next;
			node->next = nodeNew;
		}
		// 第二次遍历，把原链表的随机指针赋给新链表
		for (Node* node = head; node != nullptr; node = node->next->next) {
			Node* nodeNew = node->next;
			nodeNew->random = (node->random != nullptr) ? node->random->next : nullptr;
		}
		Node* headNew = head->next;
		// 第三次遍历，把新链表从原链表中剥离出来
		for (Node* node = head; node != nullptr; node = node->next) {
			Node* nodeNew = node->next;
			node->next = node->next->next;
			nodeNew->next = (nodeNew->next != nullptr) ? nodeNew->next->next : nullptr;
		}
		return headNew;

	}
};