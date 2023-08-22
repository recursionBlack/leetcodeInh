#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution074k2 {
public:
	ListNode* reverseEvenLengthGroups(ListNode* head) {


	}
	ListNode* reverseList(ListNode* a, ListNode* b)			// a是头，b是尾的next,返回的是新头
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

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		m_head1 = CreateList();
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		ListNode* res = reverseEvenLengthGroups(m_head1);
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