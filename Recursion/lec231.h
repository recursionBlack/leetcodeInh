#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution231{
public:
	bool isPowerOfTwo(int n) {
		bool res;
		if (n == 0)return false;

		if (n % 2 == 0)
		{
			res = isPowerOfTwo(n / 2);
		}
		else
		{
			if (n == 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return res;

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
		bool res = isPowerOfTwo(m_Tark);
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
//	题目要求不用循环或递归，看到答案是1,位与运算n&(n-1)，
// 2,是否是整数范围内，最大的最大的 2的幂的约数，
