#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution721k1 {
public:
	ListNode* swapNodes(ListNode* head, int k) {
		if (!head->next)
		{
			return head;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* p1 = head;
		ListNode* p2 = dummy;
		ListNode* p3 = dummy;
		int i = 1;
		for (; p1; p1 = p1->next)
		{
			if (i < k)
			{
				p2 = p2->next;
			}
			if (i > k)
			{
				p3 = p3->next;
			}
			i++;
		}
		// 这3种情况，容易忘了考虑
		if (p2 == p3)
		{
			return dummy->next;
		}
		if (p2->next == p3)
		{
			ListNode* q3 = p3->next;
			p3->next = q3->next;
			q3->next = p3;
			p2->next = q3;
			return dummy->next;
		}
		if (p3->next == p2)
		{
			ListNode* q2 = p2->next;
			p2->next = q2->next;
			q2->next = p2;
			p3->next = q2;
			return dummy->next;
		}
		// 通常情况
		ListNode* q2 = p2->next;
		ListNode* q3 = p3->next;
		p2->next = p2->next->next;
		q2->next = nullptr;
		p3->next = p3->next->next;
		q3->next = nullptr;

		q3->next = p2->next;
		p2->next = q3;
		q2->next = p3->next;
		p3->next = q2;

		return dummy->next;
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
		ListNode* res = swapNodes(Node1, m_K);
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