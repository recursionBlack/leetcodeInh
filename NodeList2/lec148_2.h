#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution148II {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode *dummy = new ListNode(-1);
		ListNode *p = head;
		ListNode *q;
		while (p->next && p->next->next)
		{
			if (p->next->val < head->val)
			{
				q = p->next;
				p->next = p->next->next;
				q->next = dummy->next;
				dummy->next = q;
			}
			else
			{
				p = p->next;
			}
		}
		if (p->next)
		{
			if (p->next->val < head->val)
			{
				q = p->next;
				p->next = nullptr;
				q->next = dummy->next;
				dummy->next = q;
			}
		}
		//断开head的左边，
		p = dummy;
		while (p->next)
		{
			if (p->next != head)
			{
				p = p->next;
			}
			else
			{
				break;
			}
		}
		p->next = nullptr;

		ListNode *l = sortList(dummy->next);
		ListNode *r = sortList(head->next);
		return quickSort(l, head, r);
	}
	ListNode* quickSort(ListNode* l, ListNode* h, ListNode* r)
	{
		if (!l)
		{
			h->next = r;
			return h;
		}
		ListNode* rear = l;
		while (rear->next)
		{
			rear = rear->next;
		}
		rear->next = h;
		if (!r)
		{
			return l;
		}
		else
		{
			h->next = r;
		}
		return l;
	}
	// 再用快速排序实现一遍，快速排序也是一种递归排序算法
	// 但可惜快速排序超时了。
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		Node1 = CreateList();
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		cout << "the result is: " << endl;
		ListNode* res = sortList(Node1);
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