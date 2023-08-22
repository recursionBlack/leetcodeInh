#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution147 {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head)
		{
			return head;
		}
		if (!head->next)
		{
			return head;
		}
		ListNode* head0 = new ListNode(-5001);
		head0->next = head;
		head = head0;

		ListNode *p, *q;
		while (head->next)
		{
			if (head->val <= head->next->val)
			{
				head = head->next;
			}
			else
			{
				// 摘出q节点 
				q = head->next;
				head->next = head->next->next;
				q->next = nullptr;

				// 注意，每次摘出的节点，要从头开始遍历，不要从head之后遍历
				p = head0;
				while (p->next)
				{
					if (q->val > p->val)
					{
						if (q->val > p->next->val)
						{
							p = p->next;
						}
						else
						{
							q->next = p->next;
							p->next = q;
							break;
						}
					}
				}
			}
		}
		return head0->next;
	}
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
		ListNode* res = insertionSortList(Node1);
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