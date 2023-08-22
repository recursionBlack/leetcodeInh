#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution148 {
public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		// 快慢指针，找出链表中间节点
		ListNode* p = head;
		ListNode* q = head;
		int n = 0;
		while(q->next)
		{
			q = q->next;
			if (n%2 == 0&& n != 0)
			{
				p = p->next;
			}
			n++;
		}
		//右边排序
		q = sortList(p->next);
		p->next = nullptr;
		//左边排序
		head = sortList(head);
		return mergeList(head, q);
	}
	ListNode* mergeList(ListNode* l, ListNode* r)
	{
		ListNode *dummyHead = new ListNode(-1);
		ListNode *p = dummyHead;

		while (l && r)
		{
			if (l->val <= r->val)
			{
				p->next = l;
				l = l->next;
			}
			else
			{
				p->next = r;
				r = r->next;
			}
			p = p->next;
		}
		if (l == nullptr)
		{
			p->next = r;
		}
		else
		{
			p->next = l;
		}

		return dummyHead->next;
	}
	// 经典的递归实现：归并排序，在链表时空间复杂度为o(1)，时间复杂度为O（n*log n);
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