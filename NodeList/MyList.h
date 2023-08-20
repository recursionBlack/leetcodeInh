#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* CreateList();
ListNode* DeleteNode(ListNode*);
ListNode* InsertNode(ListNode*);

ListNode* CreateList() {
	cout << "Input ListNode:" << endl;
	int Inputnum;
	ListNode* head, *nodetemp, *node;
	head = nullptr;
	nodetemp = nullptr;

	while (cin >> Inputnum)
	{
		node = new ListNode;
		node->val = Inputnum;
		if (head == nullptr) {
			head = node;
		}
		else {
			nodetemp->next = node;
		}
		nodetemp = node;
		nodetemp->next = nullptr;
	}
	cin.clear();
	cin.ignore();
	return head;
}

ListNode* DeleteNode(ListNode* head) {
	int locate;
	cout << "Input delete location: " << endl;
	cin >> locate;
	if (locate == 1) {
		head = head->next;
	}
	else {
		ListNode* temp;
		temp = head;
		for (int i = 1; i < locate - 1; i++) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
	return head;
}

ListNode* InsertNode(ListNode* head) {
	int locate;
	ListNode* insertnode = new ListNode;
	insertnode->next = nullptr;
	cout << "Input insert location: " << endl;
	cin >> locate;
	cout << "Input insert node: " << endl;
	cin >> insertnode->val;
	if (locate == 1) {
		insertnode->next = head;
		head = insertnode;
	}
	else {
		ListNode* temp;
		temp = head;
		for (int i = 1; i < locate - 1; i++) {
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "illegal location!" << endl;
			exit(0);
		}
		else if (temp->next == nullptr) {
			temp->next = insertnode;
		}
		else {
			insertnode->next = temp->next;
			temp->next = insertnode;
		}

	}
	return head;
}

