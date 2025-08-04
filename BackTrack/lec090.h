#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 子集问题2
class Solution {
	
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(nums, 0, tmp, path);
		return path;
	}

	// 相比于78题，只多了个同层剪枝的操作
	void backtrack(vector<int>& nums,  int starindex, vector<int>& tmp, vector<vector<int>>& path)
	{
		path.push_back(tmp);
		for (size_t i = starindex; i < nums.size(); i++)
		{
			if (i > starindex && nums[i] == nums[i - 1])     // 同层剪枝
				continue;
			tmp.push_back(nums[i]);
			backtrack(nums, i + 1, tmp, path);
			tmp.pop_back();
		}
	}
};
