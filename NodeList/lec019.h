#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"

using namespace std;

class Solution019 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* kong = new ListNode(-1);
		if (head == nullptr || n < 1)
		{
			cout << "please putin right num" << endl;
			ListNode* kong = new ListNode(-1);
			return kong;
		}
		int len = 0;
		m_rear = head;
		while (m_rear)
		{
			m_rear = m_rear->next;
			len++;
		}
		if (len < n)
		{
			cout << "please putin right num" << endl;
			return kong;
		}
		if (n == len)
		{
			head = head->next;
			return head;
		}
		m_rear = head;
		for (size_t i = 1; i < len - n; i++)
		{
			m_rear = m_rear->next;
		}
		m_rear->next = m_rear->next->next;
		
		return head;
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		m_head = CreateList();

		cout << "please putin num list" << endl;
		cin >> m_Tark;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		ListNode* res = removeNthFromEnd(m_head, m_Tark);
		cout << "the result is: " << endl;
		while (res)
		{
			cout << res->val << " ";
			res = res->next;
		}

		cout << endl;
	}

public:

	int m_Tark = 0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head;

};