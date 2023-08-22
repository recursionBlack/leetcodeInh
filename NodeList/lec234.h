#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution234 {
public:
	bool isPalindrome(ListNode* head) {
		//if (head->next == nullptr)
		//{
		//	return true;
		//}
		//ListNode* rear = head;
		//while (rear->next->next != nullptr)		// rear是倒数第二个节点
		//{
		//	rear = rear->next;
		//}
		//if (head == rear)		// 倒数两个
		//{
		//	return head->val == head->next->val;
		//}
		//else
		//{
		//	if (head->val == rear->next->val)
		//	{
		//		rear->next = nullptr;				// 两头都往内部缩进一个
		//		return isPalindrome(head->next);
		//	}
		//	else
		//	{
		//		return false;
		//	}
		//}		// 这个递归，当链表很大时，时间复杂度就会很大。


		if (head->next == nullptr)
		{
			return true;
		}
		int pRight = 1, pMid = 0;
		ListNode* rear = head;
		while (rear->next != nullptr)
		{
			rear = rear->next;
			pRight++;
			if (pRight %2 == 0)
			{
				pMid++;
			}
		}
		ListNode* nMid = head;
		if (pRight%2 == 0)
		{
			for (int i = 0; i < pMid; i++)
			{
				nMid = nMid->next;
			}
			ListNode*ret = reverseList(nMid);
			while (ret != nullptr)
			{
				if (ret->val == head->val)
				{
					ret = ret->next;
					head = head->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			for (int i = 0; i < pMid + 1; i++)
			{
				nMid = nMid->next;
			}
			ListNode*ret = reverseList(nMid);
			while (ret != nullptr)
			{
				if (ret->val == head->val)
				{
					ret = ret->next;
					head = head->next;
				}
				else
				{
					return false;
				}
			}
			return true;
		}

	}
	//	206翻转链表的递归函数
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode*ret = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
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
		bool res = isPalindrome(m_head1);
		cout << "the result is: " << endl;
		cout << res;
		cout << endl;
	}

public:

	int m_Tark = 0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head1;
	ListNode* m_head2;

};