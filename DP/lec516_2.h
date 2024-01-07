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

class Solution516_2 {
public:
	// ������������������ת�������������������
	// �������ｲ�����䶯̬�滮��˼·
	// ����dp�����е�������Ƶ����ϸ����
	int longestPalindromeSubseq2(string str) {
		int n = str.length();
		vector<vector<int>> dp(n, vector<int>(n));
		return f2(str, 0, n - 1,dp);
	}

	// s[l...r]����������г���
	// l <= r
	int f2(string s, int l, int r, vector<vector<int>>& dp) {
		if (l == r) {
			return 1;
		}
		if (l + 1 == r) {
			return s[l] == s[r] ? 2 : 1;
		}
		if (dp[l][r]!=0) {
			return dp[l][r];
		}
		int ans;
		if (s[l] == s[r]) {
			ans = 2 + f2(s, l + 1, r - 1,dp);
		}
		else {
			ans = max(f2(s, l + 1, r, dp), f2(s, l, r - 1, dp));
		}
		dp[l][r] = ans;
		return ans;
	}

	//	���뺯��
	// text1 = "bbbab"
	// text1 = "cbbd"
	void ShuRu()
	{
		cout << "please putin word1" << endl;
		cin >> m_s1;
		cin.clear();
		cin.ignore();

	}
	// �������
	void CalcResult()
	{
		int  res = longestPalindromeSubseq2(m_s1);
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