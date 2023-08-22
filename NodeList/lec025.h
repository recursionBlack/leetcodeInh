#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution025 {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next)
		{
			return head;
		}

		ListNode* a = head;
		ListNode* b = head;

		for (int i = 0; i < k; i++)
		{
			if (b == nullptr)
			{
				return head;
			}
			b = b->next;
		}

		ListNode *newHead = reverse(a, b);
		a->next = reverseKGroup(b, k);
		return newHead;
	}

	ListNode* reverse(ListNode* a, ListNode* b)		// a是头，b是尾的next,返回的是新头
	{
		if (!a || !a->next)
		{
			return a;
		}

		ListNode *cur = a;
		ListNode *nex = a;
		ListNode *prev = new ListNode;

		while (cur != b)
		{
			nex = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nex;
		}
		
		return prev;
	}
	// 递归输出结果：输入1~9，k = 3;
	/*递1：a = 1, b = 4, nH = 3;
	递2：a = 4, b = 7, nH = 6;
	递3：a = 7, b = 0, nH = 9;
	归3：nH = 987;
	归2：nH = 654;
	归1：nH = 321;
	*/
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

	}
	// 输出函数
	void CalcResult()
	{
		ListNode* res = reverseKGroup(m_head1, m_Tark);
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