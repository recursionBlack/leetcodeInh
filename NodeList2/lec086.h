#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution086 {
public:
	ListNode* partition(ListNode* head, int x) {
		if (!head)
		{
			return head;
		}
		if (!head->next)
		{
			return head;
		}
		
		ListNode* head2 = new ListNode(-101);
		// 如果不用递归的话，一般往往都要自建个头节点，否则题目给的头节点非常容易出错
		ListNode* head0 = new ListNode(-101);		
		head0->next = head;
		ListNode* r = head0;
		ListNode* p = head2;
		while (r->next)
		{
			if (r->next->val >= x)
			{
				p->next = r->next;
				p = p->next;
				if (r->next->next)
				{
					r->next = r->next->next;
					p->next = nullptr;
				}
				else
				{
					r->next = nullptr;
					p->next = nullptr;
				}
			}
			else
			{
				r = r->next;
			}
		}
		r->next = head2->next;
		return head0->next;
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
		ListNode* res = partition(Node1, m_K);
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