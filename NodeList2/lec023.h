#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <queue>
#include "../NodeList/MyList.h"
using namespace std;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;
		ListNode* dummyHead = new ListNode(0);
		ListNode* curr = dummyHead;
		// 这里用了优先级队列，不过我暂时还没学过优先级队列
		auto comp = [](ListNode* const &a, ListNode* const &b) {return a->val > b->val; };
		priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>  q(comp);
		// 在优先级队列里装了K个节点，每当有节点被取出时，再从lists里补上
		for (ListNode* list : lists)
		{
			if (!list)
			{
				continue;
			}
			else
			{
				q.push(list);
			}
		}
		
		while (!q.empty())
		{
			curr->next = q.top();
			curr = curr->next;
			q.pop();
			if (curr->next != nullptr)
			{
				q.push(curr->next);		// 这一步真是妙啊，
			}
			
		}
		return dummyHead->next;

	}

	// 由于不好调试，这里就不写输入输出函数了，
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		cout << "the result is: " << endl;

		cout << endl;
	}

public:

	int m_N = 0;
	int m_K = 0;
	vector<int> m_List;
	ListNode *m_Node1;
	ListNode *m_Node2;

};