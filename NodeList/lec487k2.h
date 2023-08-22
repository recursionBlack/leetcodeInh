#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution487k2 {
public:
	ListNode* removeNodes(ListNode* node) {
		if (!node->next)
			return node;

		ListNode* tmp = removeNodes(node->next);

		if (tmp->val > node->val) {
			return tmp;
		}
		node->next = tmp;			//这一步我没有想出来，
		return node;
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
		ListNode* res = removeNodes(m_head1);
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