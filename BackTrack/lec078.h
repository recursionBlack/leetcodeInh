#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// 子集问题
class Solution078 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> pat;
		backtrack(nums, 0, pat);
		return vec;
	}

	// 这个题比较怪，时间复杂度为2^n，因为对于nums里的每一个数，都有两种选择，加如或者不加入
   // 每个数字都有两种选择，所以共有2^n种选择，那点在于，怎么表示不加入。
	void backtrack(const vector<int>& nums, int starindex, vector<int> path)
	{
		vec.push_back(path);				// 不加入，因为本轮递归的数字还没加进path里，
		for (int i = starindex; i < nums.size(); i++)
		{
			path.push_back(nums[i]);		// 加入
			backtrack(nums, i + 1, path);
			path.pop_back();
		}
	}
};