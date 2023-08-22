#include <vector>

using namespace std;

class Solution046 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return { {} };
		}
		vec.clear();
		int n = 0;
		vector<int> pat;
		backtrack(nums, n, pat);
		return vec;

	}
	void backtrack(vector<int>& nums, int n, vector<int> path)
	{
		if (n == nums.size())
		{
			vec.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (find(path.begin(), path.end(), nums[i]) != path.end())
				continue;
			path.push_back(nums[i]);    // 做选择
			backtrack(nums, n + 1, path);         // dfs
			path.pop_back();            //取消选择，回溯算法与dfs区别的最重要标志，
		}
	}
};