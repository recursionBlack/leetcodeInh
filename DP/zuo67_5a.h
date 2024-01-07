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

class SolutionZ67_5a {
public:
	// ���仯�����ĵݹ�
	// nΪ�ڵ�����mΪ���߶�
	// ������ж����ֲ�ͬ�Ķ���������ڵ����Ϊn�����ĸ߶Ȳ�����m�ķ���
	int NodenHeightNotLargerThanm2(int n, int m) {
		vector<vector<int>> dp(MAXN, vector<int>(MAXN));
		for (int i = 0; i < MAXN; i++)
		{
			for (int j = 0; j < MAXN; j++)
			{
				dp[i][j] = -1;
			}
		}
		return f2(n,m,dp);
	}

	int f2(int n, int m, vector<vector<int>>& dp) {
		if (n == 0) {
			return 1;
		}
		// n > 0
		if (m == 0) {
			return 0;
		}
		if (dp[n][m] != -1) {
			return (int)dp[n][m];
		}
		long ans = 0;
		// n���㣬ͷռ��1��
		for (int k = 0; k < n; k++) {
			// һ��n���ڵ㣬ͷ�ڵ��Ѿ�ռ����1������
			// �������ռ��k������ô������ռ��n-k-1��
			// ���ǿתΪlong���ͺ�mod������Ϊ��ֵ�ϴ󣬿��ܳ������ͷ�Χ���ʽ���ȡ�ࡣ
			ans = (ans + ((long)f2(k, m - 1, dp) * f2(n - k - 1, m - 1, dp)) % MOD) % MOD;
		}
		dp[n][m] = ans;
		return (int)ans;
	}

	//	���뺯��
	// n = 4, m=3,res = 6;
	// n = 3, m=3,res = 5;
	void ShuRu()
	{
		cout << "please putin word1" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();

		cout << "please putin word2" << endl;
		cin >> m_M;
		cin.clear();
		cin.ignore();

	}
	// �������
	void CalcResult()
	{
		int  res = NodenHeightNotLargerThanm2(m_N, m_M);
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
	int m_M = 0;
	vector<int> m_A;
	string m_s1;
	string m_s2;
	vector<vector<int>> grid;
	int MAXN = 51;
	int MOD = 1000000007;
};