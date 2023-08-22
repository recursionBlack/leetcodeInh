#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution206 {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		//	nb啊，我真是服了，为啥这么简单的问题，我就是想不明白呢？
		ListNode* ret = reverseList(head->next);			// 递归递归，先递后归，f(n-1)就是自上而下的分解操作，
		head->next->next = head;													// 自底向上的合并操作。
		head->next = NULL;											// 对于递归，往往只考虑递到链表结束后，反推回来时的最尾部两个元素
		return ret;

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
		ListNode* res = reverseList(m_head1);
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