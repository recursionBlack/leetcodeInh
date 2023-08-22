#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int n) :val(n), next(nullptr) {}
	ListNode(int n, ListNode* p) :val(n), next(p) {}
};

class MyLinkedList {
public:
	MyLinkedList() {
		head = new ListNode(-1);
		size = 0;
	}

	int get(int index) {
		if (size == 0)
		{
			return -1;
		}
		if (index > size - 1 || index < 0)
		{
			cout << "false:index is too big!" << endl;
			return -1;
		}
		ListNode *cur = head->next;
		while (index--) { // 如果--index 就会陷入死循环
			cur = cur->next;
		}
		return cur->val;
	}

	void addAtHead(int val) {
		ListNode* p = new ListNode(val);
		p->next = head->next;
		head->next = p;
		size++;
	}

	void addAtTail(int val) {
		ListNode* p = new ListNode(val);
		ListNode* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = p;
		size++;
	}

	void addAtIndex(int index, int val) {
		if (index > size)
		{
			cout << "false:index is too big!" << endl;
			return;
		}
		ListNode* newNode = new ListNode(val);
		ListNode *cur = head;
		while (index--) {
			cur = cur->next;
		}
		newNode->next = cur->next;
		cur->next = newNode;
		size++;
	}

	void deleteAtIndex(int index) {
		if (index >= size || index < 0)
		{
			cout << "false:index is too big!" << endl;
			return;
		}

		ListNode* cur = head;
		while (index--) {
			cur = cur->next;
		}
		ListNode* tmp = cur->next;
		cur->next = cur->next->next;
		delete tmp;
		size--;
	}

public:
	ListNode* head;
	int size;
};


 //Your MyLinkedList object will be instantiated and called as such:
//int main()
//{
//	MyLinkedList* obj = new MyLinkedList();
//	//
//	//obj->addAtHead(7);
//	obj->addAtHead(4);
//	int param_1 = obj->get(1);
//	obj->addAtHead(1);
//	obj->addAtHead(5);
//	obj->deleteAtIndex(3);
//	obj->addAtHead(7);
//	int param_2 = obj->get(3);
//	int param_3 = obj->get(3);
//	int param_4 = obj->get(3);
//	obj->addAtHead(1);
//	obj->deleteAtIndex(4);
//	/*obj->addAtHead(2);
//	obj->addAtHead(7);
//	obj->addAtHead(3);
//	obj->addAtHead(2);
//	obj->addAtHead(5);
//	obj->addAtTail(5);
//	int param_1 = obj->get(5);
//	obj->deleteAtIndex(6);
//	obj->deleteAtIndex(4);*/
//	/*obj->addAtHead(4);
//	obj->addAtIndex(5, 0);
//	obj->addAtHead(6);*/
//}

 