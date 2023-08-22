#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SolutionJumpT {	
public:
	int JumpTimes(int n) {
		if (n == 1)
		{
			return 1;
		}
		if (n == 2)
		{
			return 2;
		}
		return JumpTimes(n - 2) + JumpTimes(n - 1);
	}

	// 递归经典例题，小青蛙跳台阶。
	// 小青蛙可以一次跳一个台阶，也可以一次跳两个台阶，
	// 请问如果有n个台阶，小青蛙一共有多少种跳法？

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
		int res = JumpTimes(m_Tark);
		cout << "the result is: " << endl;
		cout << res << " ";

		cout << endl;
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;

};