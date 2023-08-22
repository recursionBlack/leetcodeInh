#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution074k2 {
public:
	ListNode* reverseEvenLengthGroups(ListNode* head) {
		if (!head->next)
		{
			return head;
		}
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = head;		//当前组的头节点 ，反转后会变成组内尾节点
		ListNode* rear = cur;  // 当前组的末尾的next
		ListNode* pre = dummy; // 当前组的头的前一个节点，
		int count = 1;
		while (rear != nullptr)
		{
			// 每次循环开始时，rear = cur，所以先把rear后移count
			rear = cur;
			int k = count;
			while (k-- && rear != nullptr)
			{
				rear = rear->next;
			}
			if (rear == nullptr)
			{
				int n = 0;
				rear = cur;
				while (rear != nullptr)
				{
					rear = rear->next;
					n++;
				}
				count = n;
			}
			if (count % 2 == 0)
			{
				pre->next = reverse(cur, rear);
				if (rear != nullptr)
				{
					k = count;
					while (k--)
					{
						pre = pre->next;
					}
					pre->next = rear;
					cur = rear;
				}
			}
			else
			{
				if (rear == nullptr)
				{
					break;
				}
				k = count;
				while (k-- && cur != nullptr)
				{
					pre = pre->next;
					cur = cur->next;
				}
			}
			count++;
		}

		return dummy->next;
	}
	ListNode* reverse(ListNode* a, ListNode* b)			// a是头，b是尾的next,返回的是新头
	{
		if (!a || !a->next)
		{
			return a;
		}

		ListNode *cur = a;
		ListNode *nex = a;
		ListNode *prev = nullptr;

		while (cur != b)
		{
			nex = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nex;
		}
		return prev;
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
		ListNode* res = reverseEvenLengthGroups(Node1);
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