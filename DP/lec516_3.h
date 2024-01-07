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

class Solution516_3 {
public:
	// 严格位置依赖的动态规划
	//L>R的格子不用填，因为l<R,一半的格子不用填了。
	//并且根据左下方三个格子，最后目标获取最右上角的格子的值。从左下往右上填。
	int longestPalindromeSubseq3(string str) {
		int n = str.length();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int l = n - 1; l >= 0; l--) {
			dp[l][l] = 1;
			if (l + 1 < n) {
				dp[l][l + 1] = s[l] == s[l + 1] ? 2 : 1;
			}
			for (int r = l + 2; r < n; r++) {
				if (s[l] == s[r]) {
					dp[l][r] = 2 + dp[l + 1][r - 1];
				}
				else {
					dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
	

	//	输入函数
	// text1 = "bbbab"
	// text1 = "cbbd"
	void ShuRu()
	{
		cout << "please putin word1" << endl;
		cin >> m_s1;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		int  res = longestPalindromeSubseq3(m_s1);
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