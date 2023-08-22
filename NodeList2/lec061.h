#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution061 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr)
		{
			return head;
		}
		if (head->next == nullptr)
		{
			return head;
		}

		int n = 1;
		ListNode* curr = head;
		while (curr->next != nullptr)
		{
			curr = curr->next;
			n++;
		}
		curr->next = head;
		for (int i = 0; i < n - k%n; i++)
		{
			curr = curr->next;
		}
		head = curr->next;
		curr->next = nullptr;
		return head;
	}

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		Node1 = CreateList();
		cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();
	}
	// 输出函数
	void CalcResult()
	{
		cout << "the result is: " << endl;
		ListNode* res = rotateRight(Node1, m_K);
		while (res)
		{
			cout << res->val << " ";
			res = res->next;
		}

		cout << endl;
	}

public:
	int m_N = 0;
	int m_K = 0;
	vector<int> m_List;
	ListNode * Node1;
	ListNode * Node2;

};