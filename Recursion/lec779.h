#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution779 {
public:
	int kthGrammar(int n, int k) {
		if (n == 1)
		{
			return 0;
		}
		int len = pow(2, n - 1) / 2;
		if (k <= len)
		{
			return kthGrammar(n - 1, k);
		}
		else
		{
			return kthGrammar(n - 1, k - len) == 0 ? 1 : 0;
		}
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
		int res = kthGrammar(m_Tark, m_K);
		cout << "the result is: " << endl;
		cout << res << " ";

		cout << endl;
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;

};