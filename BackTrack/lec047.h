#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> path;
		vector<int> tmp;
		sort(nums.begin(), nums.end()); // 排序，使得相同的数在数组中是相邻的，方便nums[i]==nums[i-1]
		vector<bool> vis(nums.size(), false);

		backtrack(nums, vis, tmp, path);
		return path;
	}

	//第二个参数，是看看那些元素已经使用的标记数组，用途非常重要
	void backtrack(vector<int>& nums, vector<bool>& vis, vector<int>& tmp, vector<vector<int>>& path)
	{
		if (tmp.size() == nums.size())
		{
			path.push_back(tmp);
			return;
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
			// 剪枝，非常重要   这俩剪枝把我看麻了
			// nums[i]==nums[i-1]是用来剪枝，把同层和同枝剪枝都包含进去了，i>0是为了防止i<0
			// vis[i-1]=false是进一步将剪枝锁定为同层剪枝，与上一个条件结合实现了同层剪枝，
			if (i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == false)
				continue;

			// 为了确保nums[i]是没有选取过的数字
			if (vis[i] == true)
				continue;

			tmp.push_back(nums[i]);     // 选择
			vis[i] = true;
			backtrack(nums, vis, tmp, path);
			vis[i] = false;       		// 回溯
			tmp.pop_back();
		}
	}
};