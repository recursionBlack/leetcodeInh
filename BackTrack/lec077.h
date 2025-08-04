#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
//组合问题，数学中的Cnk
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(n, k, 1, tmp, path);
		
		return path;
	}

	// begin是当前起始参数，
	void backtrack(int n, int k, int begin, vector<int>& tmp, vector<vector<int>>& path)
	{
		if (k == 0)
		{
			path.push_back(tmp);
			return;
		}
		
		// 这个题，神奇就神奇在i = begin， 与backtrack函数的第一个参数上
		for (size_t i = begin; i <= n; i++)
		{
			tmp.push_back(i);
			backtrack(n, k - 1, i + 1, tmp, path);
			tmp.pop_back();
		}
	}
};