#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class SolutionPkg01 {
public:

    // 动态规划经典之01背包问题，
    // 容量为W的背包，从N个物品中选择放入背包，每个物品有价值和重量两种属性，如何才能使得背包装的东西价值最高？
    int knapasack(int W,int N, vector<int> wt, vector<int> val)
    {
        // base case
        vector<vector<int>> dp(N+1, vector<int>(W+1));

        for(int i = 1; i<= N; i++)
        {
            for(int j= 1; j<=W; j++)
            {
                if(j - wt[i-1] < 0)
                {
                    //这种情况表示该物品的重量，已经超出背包剩余的重量容量,
                    //无法装进去，跳过，不进行任何操作
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    //做选择：将当前物品装入背包或不装，择优
                    dp[i][j] = max(
                        //把第i个物品装进背包
                        dp[i-1][j-wt[i-1]] + val[i-1],
                        // 不装
                        dp[i-1][j]
                    );
                }
            }
        }
        return dp[N][W];
    }

    //	输入函数
	// wt={2,1,3};val={4,2,3}; N=3;W=4;
	void ShuRu()
	{
        cout << "please putin W value" << endl;
        cin >> m_W;
        cin.clear();
		cin.ignore();

		cout << "please putin N value" << endl;
        cin >> m_N;
		cin.clear();
		cin.ignore();

        cout << "please putin wt Array" << endl;
        int x;
        while (cin>>x)
        {
            m_wt.push_back(x);
        }
        
		cin.clear();
		cin.ignore();

        cout << "please putin val Array" << endl;
        while (cin>>x)
        {
            m_v.push_back(x);
        }
		cin.clear();
		cin.ignore();
	}
	// 输出函数
	void CalcResult()
	{
		int  res = knapasack(m_W, m_N, m_wt, m_v);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

public:

    int m_W = 0;
    int m_N = 0;
    vector<int> m_wt;
    vector<int> m_v;

};