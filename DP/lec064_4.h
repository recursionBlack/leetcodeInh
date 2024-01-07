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

class Solution064_4 {
public:
	// 严格位置依赖的动态规划+空间压缩技巧
	int minPathSum4(vector<vector<int>>& grid) {
		// 二维数组，最大的问题，就是别把行列搞混了，
		// 忘掉那个该死的笛卡尔坐标系吧，这里是二维数组，行纵列横，前纵后横。
		int n = grid.size();		// 行
		int m = grid[0].size();		// 列
		// 先让dp表，变成想象中的表的第0行的数据
		vector<int> dp(m);
		dp[0] = grid[0][0];
		for (int j = 1; j < m; j++) {
			dp[j] = dp[j - 1] + grid[0][j];
		}
		for (int i = 1; i < n; i++) {
			// i = 1，dp表变成想象中二维表的第1行的数据
			// i = 2，dp表变成想象中二维表的第2行的数据
			// i = 3，dp表变成想象中二维表的第3行的数据
			// ...
			// i = n-1，dp表变成想象中二维表的第n-1行的数据
			dp[0] += grid[i][0];
			for (int j = 1; j < m; j++) {
				dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
			}
		}
		return dp[m - 1];
	}

	//	输入函数
	// [[1,3,1],[1,5,1],[4,2,1]] 
	// res = 7;
	// [[1,2,3],[4,5,6]]
	// res = 12;
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
		int  res = minPathSum4(grid);
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