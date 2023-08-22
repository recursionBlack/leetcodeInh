#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class SolutionListTest {
public:
	void retLast(ListNode* list1) 
	{ 
		while (list1->next != nullptr) 
		{ 
			list1 = list1->next; 
		}    
	}
	/*chatgpt:这是因为函数retLast中只是对list1进行了遍历，但并没有将最后一个节点返回。
		如果你想要返回最后一个节点，应该将遍历到的最后一个节点返回，而不是只对list1进行操作。
		可以修改函数代码如下：
		ListNode* retLast(ListNode* list1) 
		{ 
			while (list1->next != nullptr)
			{ list1 = list1->next; }
			return list1;
		}
	这样，函数就会返回最后一个节点的指针了。*/
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
		retLast(m_head1);
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