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

class Solution143k1_3 {
public:
	// 严格位置依赖的动态规划
	int longestCommonSubsequence4(string s1, string s2) {
		int n = s1.length();
		int m = s2.length();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		//递归是从尾巴向前，但动规则是要从前往后，
		for (int len1 = 1; len1 <= n; len1++) {
			for (int len2 = 1; len2 <= m; len2++) {
				if (s1[len1 - 1] == s2[len2 - 1]) {
					dp[len1][len2] = 1 + dp[len1 - 1][len2 - 1];
				}
				else {
					dp[len1][len2] = max(dp[len1 - 1][len2], dp[len1][len2 - 1]);
				}
			}
		}
		return dp[n][m];
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
		int  res = longestCommonSubsequence4(m_s1, m_s2);
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