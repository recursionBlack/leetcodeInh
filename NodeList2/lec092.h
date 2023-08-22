#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution092 {
public:
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (!head)
		{
			return head;
		}
		if (!head->next)
		{
			return head;
		}
		ListNode* head0 = new ListNode(-501);
		head0->next = head;

		ListNode* rear = head0;
		ListNode *pl, *pr, *plh;
		int x = 1;

		while (x < left)
		{
			x++;
			rear = rear->next;
		}
		pl = rear;
		rear = rear->next;
		plh = rear;
		while (x < right)
		{
			x++;
			rear = rear->next;
		}
		pr = rear->next;
		rear->next = nullptr;
		
		ListNode* res = reverse(plh);
		rear = res;
		while (rear->next)
		{
			rear = rear->next;
		}
		rear->next = pr;
		pl->next = res;

		return head0->next;
	}
	ListNode* reverse(ListNode* head)
	{
		if (!head)
		{
			return head;
		}
		if (!head->next)
		{
			return head;
		}
		ListNode* res = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;

		return res;
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		Node1 = CreateList();
		cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_N;
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
		ListNode* res = reverseBetween(Node1, m_N, m_K);
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