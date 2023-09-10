#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"

using namespace std;
class Solution021 {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1)
		{
			return list2;
		}
		if (!list2)
		{
			return list1;
		}
		if (list1->val < list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}

	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		m_head1 = CreateList();

		cout << "please putin num list" << endl;
		m_head2 = CreateList();

	}
	// 输出函数
	void ChuShu()
	{
		ListNode* res = mergeTwoLists(m_head1, m_head2);
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