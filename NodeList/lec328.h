#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution328 {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode* ou = digui(head);

		ListNode*ji = head;
		while(ji && ji->next)
		{
			ji = ji->next;
		}

		ji->next = ou;
		return head;
	}
	ListNode* digui(ListNode* head)
	{
		if (!head || !head->next)
		{
			return nullptr;
		}

		ListNode*  tmp = head->next;
		head->next = head->next->next;
		tmp->next = digui(head->next);
		return tmp;
	}
	// 开心，自己做出的第一道递归题
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
		ListNode* res = oddEvenList(Node1);
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