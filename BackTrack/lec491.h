#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(nums, 0, tmp, path);
		return path;
	}

	// 该题难点在于，对于又重复元素，但又不能排序，该如何去重呢？
	// 能排序的去重可以通过used数组+nums[i]==nums[i-1]来判断，因为相同的元素经过排序后是相邻的，
	// 但本题是不能排序的，评论区采用了同层map来实现同层去重功能
	void backtrack(const vector<int>& nums, int startindex, vector<int>& tmp, vector<vector<int>>& path)
	{
		//因为题目要求是返回至少两个元素，并且是递增子序列，所以条件是加入path路径的长度大于1即可
		//但是这里注意的是不能return，因为return了只能返回path.size==nums.length的最后一个集合
		if (tmp.size() > 1)
		{
			path.push_back(tmp);
		}

		unordered_set<int> used_list;	// 同层去重, 不用加入dfs参数里
		for (int i = startindex; i < nums.size(); i++)
		{
			//保证递增
			if (tmp.size() > 0 && tmp.back() > nums[i])
				continue;		// continue, 不能是break
			//同层去重
			if (used_list.find(nums[i]) != used_list.end())
				continue;
			used_list.insert(nums[i]);
			tmp.push_back(nums[i]);
			backtrack(nums, i + 1, tmp, path);
			tmp.pop_back();
		}
	}
};