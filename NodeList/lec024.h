#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution024 {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}

		ListNode* tmp = head->next;					// 新链表第一个位置
		head->next = swapPairs(tmp->next);		// 新链表第二个位置
		tmp->next = head;									// 

		return tmp;												// 返回链表的头节点

	}

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		m_head1 = CreateList();

	}
	// 输出函数
	void CalcResult()
	{
		ListNode* res = swapPairs(m_head1);
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

