#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// 组合问题
class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(n, k, 1, tmp, path);

		return path;
	}

	void backtrack(int n, int k, int starindex, vector<int>& tmp, vector<vector<int>>& path)
	{
		if(n == 0 && k == 0){
			path.push_back(tmp);
		}

		for (size_t i = starindex; i < 9 + 1; i++)
		{
			if(i > n)
				break;
			tmp.push_back(i);
			backtrack(n - i, k - 1, i + 1, tmp, path);
			tmp.pop_back();
		}
	}
};