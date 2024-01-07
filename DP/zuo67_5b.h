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

class SolutionZ67_5b {
public:
	// n为节点数，m为最大高度
	// 计算出有多少种不同的二叉树满足节点个数为n且树的高度不超过m的方案
	// 严格位置依赖的动态规划
	//dp[n][m]的格子的值，依赖于左侧列，从0到n-1行 格子的值，
	int NodenHeightNotLargerThanm3(int n, int m) {
		vector<vector<int>> dp(MAXN, vector<int>(MAXN));
		for (int j = 0; j <= m; j++) {
			dp[0][j] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = 0;
				for (int k = 0; k < i; k++) {
					// 一共i个节点，头节点已经占用了1个名额
					// 如果左树占用k个，那么右树就占用i-k-1个
					dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % MOD) % MOD;
				}
			}
		}
		return (int)dp[n][m];
	}


	//	输入函数
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
	// 输出函数
	void CalcResult()
	{
		int  res = NodenHeightNotLargerThanm3(m_N, m_M);
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