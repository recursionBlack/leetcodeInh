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

class Solution143k1_4 {
public:
	// 严格位置依赖的动态规划 + 空间压缩
	int longestCommonSubsequence5(string str1, string str2) {
		string s1, s2;
		// 长的是s1，短的是s2
		if (str1.length() >= str2.length()) {
			s1 = str1;
			s2 = str2;
		}
		else {
			s1 = str2;
			s2 = str1;
		}
		// 
		int n = s1.length();
		int m = s2.length();
		vector<int> dp(m + 1);
		for (int len1 = 1; len1 <= n; len1++) {
			int leftUp = 0, backup;
			// 格子依赖于，左上角，左侧，和上侧，所以要定义一个leftUp存左上角的值。
			for (int len2 = 1; len2 <= m; len2++) {
				backup = dp[len2];
				if (s1[len1 - 1] == s2[len2 - 1]) {
					dp[len2] = 1 + leftUp;
				}
				else {
					dp[len2] = max(dp[len2], dp[len2 - 1]); // 上侧和左侧比大小
				}
				leftUp = backup;
			}
		}
		return dp[m];
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
		int  res = longestCommonSubsequence5(m_s1, m_s2);
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