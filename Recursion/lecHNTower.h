#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

class SolutionHNT {
public:
	void honnoi(int n, char A, char B, char C) {   // 盘子数量，起始位置，中间位置，目标位置
		if (n == 1)
		{
			cout << " 将圆盘" << n << "从 " << A << "移动到 " << C << endl;
			return;
		}
		honnoi(n - 1, A, C, B);
		cout << " 将圆盘" << n << "从 " << A << "移动到 " << C << endl;
		honnoi(n - 1, B, A, C);

	}

	/*经典问题，汉诺塔，问如果有一个n层高的汉诺塔，
	最少需要多少次才能挪完*/
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

		honnoi(m_Tark, 'A', 'B', 'C');
		cout << endl;
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;

};