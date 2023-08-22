#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyList.h"
using namespace std;

class Solution050 {
public:
	double myPow(double x, int n) {
		if (n == 0)
		{
			return 1;
		}
		double res;
		if ( n > 0)
		{
			if (n % 2 == 0)
			{
				res = myPow(x*x, n / 2);		// 等于两个子结果相乘比如，2的10次方， 等于两个2的5次方相乘
			}
			else
			{
				res = x * myPow(x * x, (n - 1) / 2);
			}
		}
		else
		{
			res = 1/x * myPow(1/x , -(n + 1));
		}
		return res;
		
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin >> m_x;
		cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_n;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		double res = myPow(m_x, m_n);
		cout << "the result is: " << endl;
		cout << res << " ";
			
		cout << endl;
	}

public:

	int m_n = 0;
	double m_x = 0.0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head1;
	ListNode* m_head2;

};