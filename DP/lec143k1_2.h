#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <sstream> 
#include <stack>
#include <cmath>


using namespace std;

class Solution143k1_2 {
public:

	// 记忆化搜索
	int longestCommonSubsequence3(string str1, string str2) {
		int n = str1.length();
		int m = str2.length();
		vector<vector<int>> dp(n+1, vector<int>(m+1));
		for (int i = 0; i < n + 1; i++)
		{
			for (int j = 0; j < m + 1; j++)
			{
				dp[i][j] = -1;
			}
		}
		return f3(str1, str2, n, m, dp);
	}

	// s1[前缀长度为len1]对应s2[前缀长度为len2]
	// 最长公共子序列长度
	int f3(string s1, string s2, int len1, int len2, vector<vector<int>>& dp) {
		if (len1 == 0 || len2 == 0) {
			return 0;
		}
		// 记忆化搜索多的
		if (dp[len1][len2] != -1) {
			return dp[len1][len2];
		}
		int ans;
		if (s1[len1 - 1] == s2[len2 - 1]) {
			ans = f3(s1, s2, len1 - 1, len2 - 1,dp) + 1;
		}
		else {
			ans = max(f3(s1, s2, len1 - 1, len2, dp), f3(s1, s2, len1, len2 - 1, dp));
		}
		dp[len1][len2] = ans;		// 记忆化搜索多的
		return ans;
	}

	//	输入函数
	// text1 = "abcde", text2 = "ace"
	// text1 = "abc", text2 = "abc"
	// text1 = "abc", text2 = "def"
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
		int  res = longestCommonSubsequence3(m_s1, m_s2);
		cout << "the result is: " << endl;
		cout << res << " " << endl;
	}

	vector<vector<int>> parse_2d_array(string input) {
		vector<vector<int>> array;
		vector<int> arr;
		stack<int> q;
		for (char c : input) {
			if (c == ',' && !q.empty())
			{
				int wei = 0;
				int sum = 0;
				while (!q.empty()) {
					int top = q.top();
					q.pop();
					sum += top * pow(10, wei);
					wei++;
				}
				arr.push_back(sum);
			}
			else if (c - '0' >= 0 && c - '0' <= 9) {
				int t = c - '0';
				q.push(t);
			}
			else if (c == ']' && !arr.empty()) {
				int wei = 0;
				int sum = 0;
				while (!q.empty()) {
					int top = q.top();
					q.pop();
					sum += top * pow(10, wei);
					wei++;
				}
				arr.push_back(sum);
				array.push_back(arr);
				arr.clear();
			}
		}
		return array;
	}

public:
	int m_N = 0;
	vector<int> m_A;
	string m_s1;
	string m_s2;
	vector<vector<int>> grid;
};