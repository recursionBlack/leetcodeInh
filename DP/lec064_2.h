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

class Solution064_2 {
public:

	// 带记忆化搜索的递归
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp;
		dp.resize(n, std::vector<int>(m));  // 定义为一个3x3的二维数组  
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				dp[i][j] = -1;
			}
		}
		return f2(grid, grid.size() - 1, grid[0].size() - 1, dp);
	}

	// 从(0,0)到(i,j)最小路径和
	// 一定每次只能向右或者向下
	int f2(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		int ans;
		if (i == 0 && j == 0) {
			ans = grid[0][0];
		}
		else {
			int up = 1024;
			int left = 1024;
			if (i - 1 >= 0) {
				up = f2(grid, i - 1, j, dp);
			}
			if (j - 1 >= 0) {
				left = f2(grid, i, j - 1, dp);
			}
			ans = grid[i][j] + min(up, left);
		}
		dp[i][j] = ans;
		return ans;
	}

	//	输入函数
	// word1 = horse, word2 = ros, res = 3
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
		grid = parse_2d_array(m_s1);
		int  res = minPathSum(grid);
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