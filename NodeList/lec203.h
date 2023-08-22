#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution203 {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (!head)
		{
			return head;
		}
		head->next = removeElements(head->next, val);
		if (head->val == val)
		{
			head = head->next;
		}
		return head;

	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		m_head1 = CreateList();
		cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_Tark;

	}
	// 输出函数
	void CalcResult()
	{
		ListNode* res = removeElements(m_head1, m_Tark);
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
	ListNode* m_head1;
	ListNode* m_head2;

};