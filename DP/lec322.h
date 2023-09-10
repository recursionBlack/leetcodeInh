#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution322 {
public:
    //  零钱兑换
    //  暴力递归解法
    
    //  状态：目标金额amount
    //  选择：coins数组中的面额
    //  函数的定义：凑出amount的面额，至少需要coinChange(coins，amount)枚硬币
    //  base case: amount == 0，需要0枚硬币，amount < 0时，不可能凑出来

    // coinChange([1,2,5],11)
    // = 1+ min(coinChange([1,2,5],10),coinChange([1,2,5],9),coinChange([1,2,5],6));

    int coinChange1(vector<int> coins, int amount)     
    {
        // base case
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        int res = 1024;
        for(int coin:coins)
        {
            // 计算子问题的结果
            int subProblem = coinChange1(coins, amount - coin);
            // 子问题没有则跳过
            if(subProblem == -1) continue;
            res = min(res, 1 + subProblem);
        }

        return res == 1024 ? -1 : res;
    }

    //------------------------------------------
    //备忘录
    unordered_map<int, int> memo;       
    // 方法2 自上而下，带备忘录的递归
    int coinChange2(vector<int> coins, int amount)     
    {
        // base case
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        //先遍历memo
        if(memo.find(amount)!=memo.end())
        {
            return memo.find(amount)->second;
        }

        int res = 1024;
        for(int coin:coins)
        {
            // 计算子问题的结果
            int subProblem = coinChange1(coins, amount - coin);
            // 子问题没有则跳过
            if(subProblem == -1) continue;
            res = min(res, 1 + subProblem);
        }

        memo[amount] = (res == 1024) ? -1 : res;

        return memo[amount];
    }

    //-----------------------------------------------------
    //方法3，自底向上的迭代算法
    unordered_map<int, int> dp;
    int coinChange3(vector<int> coins, int amount)     
    {
        int Max = amount + 1;
        // dp数组全初始化为最大值，amount + 1无法被取到
        vector<int> dp(amount + 1, Max);
        // base case
        dp[0] = 0;
         // 外层for循环遍历所有状态的取值
        for (int i = 1; i <= amount; ++i) 
        {
             // 内层for循环，在求所有选择的最小值
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                     //状态转移方程
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        // 看看金额 amount 能不能凑出来
        return dp[amount] > amount ? -1 : dp[amount];
    }


    //	输入函数
	// coins = [1,2,5] amount = 11
	void ShuRu()
	{
        cout << "please putin Array" << endl;
        int x;
        while(cin >> x)
        {
            m_A.push_back(x);
        }
        cin.clear();
		cin.ignore();

		cout << "please putin num list" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		int  res = coinChange3(m_A, m_N);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

public:

	int m_N = 0;
    vector<int> m_A;

};