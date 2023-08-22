#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution143 {
public:
	void reorderList(ListNode* head) {				// 和234类似，
		if (head->next == nullptr)
		{
			return;
		}
		int pRight = 0, pMid = 0;
		ListNode* rear = head;
		while (rear != nullptr)
		{
			rear = rear->next;
			pRight++;
			if (pRight % 2 == 0)
			{
				pMid++;
			}
		}
		ListNode* nMid = head;
		if (pRight % 2 == 0)
		{
			for (int i = 0; i < pMid; i++)
			{
				nMid = nMid->next;
			}
			ListNode*ret = reverseList(nMid);
			ListNode* rear = head;
			mergeTwoLists(rear, ret);
			
			for (int i = 0; i < pRight; i++)
			{
				rear = rear->next;
			}
			rear->next = nullptr;
		}
		else
		{
			for (int i = 0; i < pMid + 1; i++)
			{
				nMid = nMid->next;
			}
			ListNode*ret = reverseList(nMid);
			ListNode* rear = head;			
			mergeTwoLists(rear, ret);
			
			for (int i = 0; i < pRight + 1; i++)
			{
				rear = rear->next;
			}
			rear->next = nullptr;
		}

	}
	//	206翻转链表的递归函数
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		ListNode*ret = reverseList(head->next);	// ret成了最右端的节点
		head->next->next = head;
		head->next = nullptr;
		return ret;

	}
	// 合并两个链表
	void mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* tmp1 = list1;
		ListNode* tmp2 = list2;
		while (list1 != nullptr &&list2 != nullptr)
		{
			tmp1 = list1->next;
			tmp2 = list2->next;

			list1->next = list2;
			list1 = tmp1;

			list2->next = list1;
			list2 = tmp2;
		}
		// 这个函数最大的疑点在于，list1明明都->到尾部了，
		// 为啥返回后,list1又回到了起点？
		/*if (fast != mid) {
			mid = reverse(mid);
			fast = head;
			while (fast&&mid)
			{
				t = fast;
				fast = fast->next;
				t->next = mid;
				t = mid;
				mid = mid->next;
				t->next = fast;
			}
			if (mid)t->next = mid;
		}*/
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
		reorderList(m_head1);
		cout << "the result is: " << endl;
		while (m_head1)
		{
			cout << m_head1->val << " ";
			m_head1 = m_head1->next;
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