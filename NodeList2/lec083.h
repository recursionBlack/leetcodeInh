#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../NodeList/MyList.h"
using namespace std;

class Solution083 {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		if (head->next == nullptr)
		{
			return head;
		}
		ListNode* res = deleteDuplicates(head->next);
		if (res->val == head->val)
		{
			head->next = res->next;
		}
		return head;
	}
	// 居然能用递归解？ 笑死我了，链表想不明白
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
		ListNode* res = deleteDuplicates(Node1);
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