#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution725 {
public:
	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		int n = 1;
		vector<ListNode*> vec;
		ListNode *p = head;
		for ( ;p->next; p = p->next)
		{
			n++;
		}
		if (n < k)
		{
			for (int i = 0;i<k;i++)
			{
				if (i<n)
				{
					p = head;
					head = head->next;
					p->next = nullptr;
					vec.push_back(p);
				}
				else
				{
					vec.push_back(nullptr);
				}
			}
			return vec;
		}
		int num = n / k;
		int yu = n % k;
		p = head;
		ListNode* q = p;
		ListNode* r;
		int k1 = num;
		for (int i = 0; i < yu; i++)
		{
			while (k1--)
			{
				q = q->next;
			}
			if (!q->next)
			{
				vec.push_back(p);
				break;
			}
			r = q->next;
			q->next = nullptr;
			vec.push_back(p);
			p = r;
			q = p;
			k1 = num;
		}
		k1 = num -1;
		q = p;
		for (int i = 0; i < k - yu; i++)
		{
			while (k1--)
			{
				q = q->next;
			}
			if (!q->next)
			{
				vec.push_back(p);
				break;
			}
			r = q->next;
			q->next = nullptr;
			vec.push_back(p);
			p = r;
			q = p;
			k1 = num - 1;
		}
		return vec;
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
		vector<ListNode*> res = splitListToParts(Node1, m_K);
		for (int i=0;i<res.size();i++)
		{
			ListNode* p = res[i];
			while (p)
			{
				cout << p->val << " ";
				p = p->next;
			}
			cout << endl;
		}
	}

public:
	int m_N = 0;
	int m_K = 0;
	vector<int> m_List;
	ListNode * Node1;
	ListNode * Node2;

};