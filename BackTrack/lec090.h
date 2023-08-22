#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 子集问题
class Solution090 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		vector<int> pat;
		backtrack(nums, used, 0, pat);
		return vec;
	}

	// 相比于78题，只多了个同层剪枝的操作
	void backtrack(vector<int>& nums, vector<bool> used, int starindex, vector<int> path)
	{
		vec.push_back(path);
		for (int i = starindex; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])     // 同层剪枝
				continue;
			path.push_back(nums[i]);
			used[i] = true;
			backtrack(nums, used, i + 1, path);
			used[i] = false;
			path.pop_back();
		}
	}
};
