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

class Solution329_2 {
public:
	// �����е������·��
	// ����һ�� m x n �������� matrix ���ҳ����� �����·�� �ĳ���
	// ����ÿ����Ԫ����������ϣ��£������ĸ������ƶ�
	// �� ���� �� �Խ��� �������ƶ����ƶ��� �߽��⣨���������ƣ�
	// �������� : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/
	int longestIncreasingPath2(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = max(ans, f2(grid, i, j, dp));
			}
		}
		return ans;
	}

	// ��(i,j)���������߳����೤�ĵ���·�������������
	int f2(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
		if (dp[i][j] != 0) {
			return dp[i][j];
		}
		int next = 0;
		// up
		if (i > 0 && grid[i][j] < grid[i - 1][j]) {
			next = max(next, f2(grid, i - 1, j, dp));
		}
		// down
		if (i + 1 < grid.size() && grid[i][j] < grid[i + 1][j]) {
			next = max(next, f2(grid, i + 1, j, dp));
		}
		// left
		if (j > 0 && grid[i][j] < grid[i][j - 1]) {
			next = max(next, f2(grid, i, j - 1, dp));
		}
		// right
		if (j + 1 < grid[0].size() && grid[i][j] < grid[i][j + 1]) {
			next = max(next, f2(grid, i, j + 1, dp));
		}
		dp[i][j] = next + 1;
		return next + 1;
	}

	//	���뺯��
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
		grid = parse_2d_array(m_s1);
		int  res = longestIncreasingPath2(grid);
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