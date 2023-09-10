#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution072 {
public:
    // 不用递归了，直接用方法3迭代
    int minDistance(string word1, string word2) {
        // base case
        int m = word1.length();
        int n = word2.length();
         // 定义二维数组
        vector<vector<int>> dp(m+1,vector<int>(n+1));  
        // base case
        // 边界状态初始化
        for (int i = 1; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j < n + 1; j++) {
            dp[0][j] = j;
        }

        //自底向上求解
        for(int i =1; i< m+1; i++)
        {
            for(int j =1;j < n+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = Pmin(
                        dp[i-1][j] + 1,
                        dp[i][j-1] + 1,
                        dp[i-1][j-1] + 1
                    );

                }
            }
        }

        // 存储整个word1和word2的最小编辑距离
        return dp[m][n];
    }

    int Pmin(int a, int b, int c)
    {
        return min(a, min(b,c));
    }

    // 我tm服了，直接背动态规划的板，比先想递归，再加备忘录，再改为迭代还简单。


    //	输入函数
	// word1 = horse, word2 = ros, res = 3
	void ShuRu()
	{
        cout << "please putin word1" << endl;
        cin >> m_s1;
        cin.clear();
		cin.ignore();

		cout << "please putin word2" << endl;
        cin >> m_s2;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		int  res = minDistance(m_s1, m_s2);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

public:

	int m_N = 0;
    vector<int> m_A;
    string m_s1;
    string m_s2;
};