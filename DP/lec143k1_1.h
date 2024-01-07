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

class Solution143k1_1 {
public:

	// 为了避免很多边界讨论
	// 很多时候往往不用下标来定义尝试，而是用长度来定义尝试
	// 因为长度最短是0，而下标越界的话讨论起来就比较麻烦
	int longestCommonSubsequence2(string str1, string str2) {
		int n = str1.length();
		int m = str2.length();
		return f2(str1, str2, n, m);
	}

	// s1[前缀长度为len1]对应s2[前缀长度为len2]
	// 最长公共子序列长度
	int f2(string s1, string s2, int len1, int len2) {
		if (len1 == 0 || len2 == 0) {
			return 0;
		}
		int ans;
		if (s1[len1 - 1] == s2[len2 - 1]) {
			ans = f2(s1, s2, len1 - 1, len2 - 1) + 1;
		}
		else {
			ans = max(f2(s1, s2, len1 - 1, len2), f2(s1, s2, len1, len2 - 1));
		}
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
		int  res = longestCommonSubsequence2(m_s1, m_s2);
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