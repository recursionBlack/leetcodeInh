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

class Solution516_1 {
public:
	// 最长回文子序列问题可以转化成最长公共子序列问题
	// 不过这里讲述区间动态规划的思路
	// 区间dp还会有单独的视频做详细讲述
	int longestPalindromeSubseq1(string str) {
		int n = str.length();
		return f1(str, 0, n - 1);
	}

	// s[l...r]最长回文子序列长度
	// l <= r
	int f1(string s, int l, int r) {
		if (l == r) {
			return 1;
		}
		if (l + 1 == r) {
			return s[l] == s[r] ? 2 : 1;
		}
		if (s[l] == s[r]) {
			return 2 + f1(s, l + 1, r - 1);
		}
		else {
			return max(f1(s, l + 1, r), f1(s, l, r - 1));
		}
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


	}
	// 输出函数
	void CalcResult()
	{
		int  res = longestPalindromeSubseq1(m_s1);
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