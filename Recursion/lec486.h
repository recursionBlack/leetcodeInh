#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution486 {
public:
	bool PredictTheWinner(vector<int>& nums) {
		if (nums.size() % 2 == 0)
		{
			return true;
		}

		int p1 = 0;
		int p2 = 0;
		int JI = 0;
		int OU = 0;
		if (nums.front() > nums.back())
		{
			p1 += nums.front();
			for (size_t i = 1; i < nums.size(); i++)
			{
				if (i % 2 == 0)
				{
					OU += nums[i];
				}
				else
				{
					JI += nums[i];
				}
			}
		}
		else
		{
			p1 += nums.back();
			for (size_t i = 0; i < nums.size() - 1; i++)
			{
				if (i % 2 == 0)
				{
					OU += nums[i];
				}
				else
				{
					JI += nums[i];
				}
			}
		}

		if (JI > OU)
		{
			return OU + p1 >= JI;
		}
		else
		{
			return p1 + JI >= OU;
		}

	}

	// 如果数组长度为偶数，那么p1选了奇数，p2只能选偶数，
	// p1选了偶数，p2也只能选奇数，只要p1能对比奇数数列和偶数数列的大小，
	// 那么p1就必赢。
	// 如果数组长度为奇数，则p1不一定会输，因为选择权虽然在p2手上，但p1一开始多选了一个数。

	//	输入函数
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		int tmp = 0;
		while (cin >> tmp)
		{
			m_List.push_back(tmp);
		}

		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		bool res = PredictTheWinner(m_List);
		cout << "the result is: " << endl;
		cout << res << " ";

		cout << endl;
	}

public:
	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;

};