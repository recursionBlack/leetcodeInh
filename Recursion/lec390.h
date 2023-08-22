#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution390 {
public:
	//int lastRemaining(int n) {
	//	ListNode* head = CreateList2(n);
	//	if (head->next == nullptr)
	//	{
	//		return head->val;
	//	}
	//	while (head && head->next)
	//	{
	//		head = remove(head);
	//		ListNode* tmp = head;
	//		head = reverseList(tmp);
	//	}
	//
	//	return head->val;
	//}

	//ListNode* CreateList2(int n)
	//{
	//	ListNode* head = new ListNode(1);
	//	if (n == 1)
	//	{
	//		return head;
	//	}
	//	ListNode* rear = head;
	//	for (size_t i = 2; i < n + 1; i++)
	//	{
	//		ListNode* tmp = new ListNode(i);
	//		rear->next = tmp;
	//		rear = tmp;
	//	}
	//	return head;
	//}

	//ListNode* reverseList(ListNode* head) {
	//	if (head == NULL || head->next == NULL) {
	//		return head;
	//	}
	//	//	nb啊，我真是服了，为啥这么简单的问题，我就是想不明白呢？
	//	ListNode* ret = reverseList(head->next);			// 递归递归，先递后归，f(n-1)就是自上而下的分解操作，
	//	head->next->next = head;													// 自底向上的合并操作。
	//	head->next = NULL;											// 对于递归，往往只考虑递到链表结束后，反推回来时的最尾部两个元素
	//	return ret;

	//}
	//ListNode* remove(ListNode* head) {
	//	if (head->next == nullptr)
	//	{
	//		return head;
	//	}
	//	ListNode* tmp = head->next;
	//	head->next = nullptr;
	//	head = tmp;						// 把头节点移动到第二位
	//	while (tmp && tmp->next)
	//	{
	//		tmp->next = tmp->next->next;
	//		tmp = tmp->next;
	//	}
	//	return head;
	//}
	//  用链表的方式实现，发现当数值很大时，时间复杂度就会巨大无比
	// 所以采用栈的方式实现，看了一下堆栈，发现没有这道题，看了评论区，
	// 发现是道数学题，连容器都用不到。
	int lastRemaining(int n) 
	{
		return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
	
		//假如输入为 n，我们使用 f(n) 表示 从左到右(forward) 的最终结果，即最右侧的值，
		//使用 b(n)表示 从右到左(backward) 的最终结果，即最左侧的值。则：

			/*当 n = 1 时，存在 f(n) = 1, b(n) = 1
			对于任意 n，存在 f(n) + b(n) = n + 1
			对于 n > 2 的情况下，f(n) = 2 * b(n / 2)
			所以：f(n) = 2 * (n / 2 + 1 - f(n / 2))*/
		// 这道题的数学规律太重了，对数据结构和算法本身的考察没有多少。

	}

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin >> m_Tark;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		int res = lastRemaining(m_Tark);
		cout << "the result is: " << endl;		
		cout << res << " ";
		
		cout << endl;
	}

public:

	int m_Tark = 0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head1;
	ListNode* m_head2;

};