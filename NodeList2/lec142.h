#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution141 {
public:
	ListNode *detectCycle(ListNode *head) {
		if (!head || head->next)
		{
			return nullptr;
		}
		
		vector<ListNode*> l1;
		l1.push_back(head);
		ListNode *p = head->next;
		while (p->next)
		{
			for (int i = 0; i < l1.size(); i++)
			{
				if (l1.size() == 1)
				{

				}
				if (p == l1[i])
				{
					return p;
				}
			}
			l1.push_back(p);
			p = p->next;
		}

		return nullptr;
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
		cin.clear();
		cin.ignore();

		createCycle(m_head1, m_Tark);
	}
	void createCycle(ListNode *head, int pos)
	{
		if (!head || !head->next)
		{
			return;
		}
		if (pos < 0)
		{
			return;
		}
		ListNode *p = head;
		while (p->next)
		{
			p = p->next;
		}
		for (int i = 0; i < pos; i++)
		{
			if (head->next == nullptr)
			{
				return;
			}
			head = head->next;
		}
		p->next = head;
	}
	// 输出函数
	void CalcResult()
	{
		bool res = hasCycle(m_head1);
		cout << "the result is: " << endl;
		/*while (res)
		{
			cout << res->val << " ";
			res = res->next;
		}*/
		cout << res << " ";

		cout << endl;
	}

public:

	int m_Tark = 0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head1;
	ListNode* m_head2;

};