#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// 组合问题
class Solution216 {
	vector<vector<int>> res;
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> pat;
		backtrack(1, n, k, pat);
		return res;
	}

	void backtrack(int starindex, int n, int k, vector<int> path)
	{
		// 一次做出来，但没有剪枝，把所有k个数组合全求出来了，然后再用sum==n进行筛选，
		// 所以内存只比5%的用户高，结果筛选和提前剪枝相比，更容易理解，但要用掉更多内存
		// 看别人的题解，把sum作为backtrack的参数，在for循环里剪枝，
		// 如果sum已经大于n了，那就没必要继续续接path了，
		if (path.size() == k)
		{
			int sum = 0;
			for (int i : path)
			{
				sum += i;
			}
			if (sum == n)
				res.push_back(path);
			return;
		}

		// 做回溯题的话，不要想着如何一次写出剪枝后的结果，而是先用暴力解法，
		// 把所有组合表示出来，然后再进行剪枝，
		for (int i = starindex; i <= 9; i++)
		{
			path.push_back(i);
			backtrack(i + 1, n, k, path);
			path.pop_back();
		}
	}
};