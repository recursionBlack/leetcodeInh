#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SolutionYSFdg
{
public:
	int ysfdg(int n, int k, int i)			// n个人的环，第k个人报数，第i个出局的人
	{
		if (i == 1)
		{
			return (n + k - 1)%n;
		}
		int res = (ysfdg(n - 1, k, i - 1) + k) % n;

		return res;
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
		for (int i = 1; i <= m_Tark; i++)
		{
			int res = ysfdg(m_Tark, m_K, i);
			cout << "第" << i << "个出环：" << res << " " << endl;
		}
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;

};