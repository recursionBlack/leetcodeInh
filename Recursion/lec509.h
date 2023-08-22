#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution509 {
public:
	int fib(int n) {
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return 1;
		}
		int res = fib(n - 1) + fib(n - 2);

		return res;
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin >> m_Tark;

	}
	// 输出函数
	void CalcResult()
	{
		int res = fib(m_Tark);
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