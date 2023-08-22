#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int data):val(data), next(nullptr) {}
	ListNode(int data, ListNode* next) :val(data), next(next) {}
};

class SolutionYSF1
{
public:
	SolutionYSF1();
	~SolutionYSF1();
	void ysflb(int n, int k)
	{
		ListNode* head = new ListNode(0);
		ListNode* p = head;
		// 创建约瑟夫环
		for (size_t i = 1; i < n; i++)
		{
			ListNode* r = new ListNode();
			r->val = i;
			p->next = r;
			p = r;
		}
		p->next = head;
		p = head;

		ListNode* r = new ListNode();
		while (p->next != p)
		{
			for (size_t i = 1; i < k; i++)			// 这里i不能等于0
			{
				r = p;
				p = p->next;			// p所指的就是每次被删除掉的元素
			}
			cout << p->val << " ";
			r->next = p->next;
			p = p->next;
		}
		// 循环结束时，还剩下一个元素，这个元素也要打印出来
		cout << p->val << endl;

	}

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin >> m_Tark;
		cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();
	}
	// 输出函数
	void CalcResult()
	{
		cout << "the result is: " << endl;
		ysflb(m_Tark, m_K);

		cout << endl;
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;


};

SolutionYSF1::SolutionYSF1()
{
}

SolutionYSF1::~SolutionYSF1()
{
}

//chatgpt:在C++中，这两种方式都可以用来创建一个动态分配的ListNode对象的指针。但是，它们之间还是有一些微小的区别：
//
//ListNode* head = new ListNode; 分配了一个默认构造函数创建的对象，这意味着ListNode对象的成员变量将不会被初始化。这可能会导致一些意外的行为，因为成员变量的值是未定义的。
//
//ListNode* head = new ListNode(); 分配了一个值初始化的对象，即使ListNode类没有显式定义一个默认构造函数，也会使用编译器提供的默认值初始化构造函数来初始化成员变量。因此，这种方式更加安全，可以避免成员变量未定义的情况。
//
//总的来说，使用ListNode* head = new ListNode(); 方式更加安全，也是更好的选择。