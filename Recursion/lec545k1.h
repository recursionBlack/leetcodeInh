#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "../Stack/MyStack.h"
using namespace std;

class Solution545k1{
public:
	char findKthBit(int n, int k) 
	{
		//递归终止条件：
		if (n == 1) return '0';
		//先计算Sn的长度。
		int len = (1 << n) - 1;
		//分成三个区域计算：
		//第一区域，k即为中点，那答案一定是‘1’。
		if (k == (len + 1) / 2) return '1';
		//第二区域，k在中点之前，那么答案就是Sn-1在k位置的字符：
		if (k < (len + 1) / 2) return findKthBit(n - 1, k);
		//第三区域，k在中点之后，对Sn-1先翻转（即reverse）中点之后的所有字符，再反转（即invert）比特：
		return findKthBit(n - 1, len + 1 - k) == '0' ? '1' : '0';

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
		char res = findKthBit(m_Tark, m_K);
		cout << "the result is: " << endl;
		cout << res<< " ";
		
		cout << endl;
	}

public:

	int m_Tark = 0;
	int m_K = 0;
	vector<int> m_List;
	ListNode* m_rear;
	ListNode* m_head1;
	ListNode* m_head2;

};