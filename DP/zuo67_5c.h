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

class SolutionZ67_5c {
public:
	// n为节点数，m为最大高度
	// 计算出有多少种不同的二叉树满足节点个数为n且树的高度不超过m的方案
	// 严格位置依赖的动态规划 + 空间压缩技巧
	//dp[n][m]的格子的值，依赖于左侧列，从0到n-1行 格子的值，
	// 一维数组内存的是列数据，并且由于依赖没有正左和正上，每列还能从下往上更新，结果也在最左下角。
	int NodenHeightNotLargerThanm4(int n, int m) {
		vector<int> dp(MAXN);
		dp[0] = 1;
		for (int i = 1; i <= n; i++) {
			dp[i] = 0;
		}
		for (int j = 1; j <= m; j++) {
			// 根据依赖，一定要先枚举列
			for (int i = n; i >= 1; i--) {
				// 再枚举行，而且i不需要到达0，i>=1即可
				dp[i] = 0;
				for (int k = 0; k < i; k++) {
					// 枚举
					dp[i] = (dp[i] + dp[k] * dp[i - k - 1] % MOD) % MOD;
				}
			}
		}
		return (int)dp[n];
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
		int  res = NodenHeightNotLargerThanm4(m_N, m_M);
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