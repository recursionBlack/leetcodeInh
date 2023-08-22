#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution342 {
public:
	bool isPowerOfFour(int n) {
		bool res;
		if (n == 0)return false;

		if (n % 4 == 0)
		{
			res = isPowerOfFour(n / 4);
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