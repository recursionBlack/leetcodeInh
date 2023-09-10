#pragma once
#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution509_d {
public:
	// 动态规划第一题，斐波那契数列
	// 方法1，暴力递归解法
	int fib1(int n)
	{
		// base case
		if (n == 0 || n == 1) return n;
		// 递推关系
		return fib1(n - 1) + fib1(n - 2);
	}

	// 方法2，带备忘录的暴力递归
	int fib2(int n)
	{
		int *memo = new int[n+1]();		// 数组初始化的方法，一直用容器，都不知道数组咋初始化了
		return helper(memo, n);
	}
	int helper(int* a, int n)
	{
		// base case
		if (n == 0 || n == 1) return n;
		// 已经计算过了，就不用再计算
		if (a[n] !=0) return a[n];

		a[n] = helper(a, n - 1) + helper(a, n - 2);
		return a[n];
	}

	// 方法3，用迭代替换递归
	int fib3(int n)
	{
		if (n == 0) return 0;
		int* dp = new int[n + 1]();
		// base case
		dp[0] = 0; dp[1] = 1;
		// 状态转移
		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	// 方法4，由于只用到了两个值，所以只申请两个变量，不再使用数组，进一步节省空间
	int fib4(int n)
	{
		// base case
		if (n == 0 || n == 1) return n;

		// 递推关系
		int prev = 0; int curr = 1;
		for (int i = 2; i <= n; i++)
		{
			int sum = prev + curr;
			prev = curr;
			curr = sum;
		}
		return curr;
	}

	//	输入函数
	// n = 20, res = 6765
	void ShuRu()
	{
		cout << "please putin num list" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();
	}
	// 输出函数
	void CalcResult()
	{
		int  res = fib3(m_N);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

public:

	int m_N = 0;
};
