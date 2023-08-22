#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 组合问题
class Solution039 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> pat;
		sort(candidates.begin(), candidates.end()); // 需要排序
		backtrack(candidates, 0, target, 0, pat);
		return vec;
	}

	// 我真的服了，为什么我始终理解不了这个 startIndex呢？
	// 该值主要用来，防止倒序的结果再出现一遍，比如，[1,2,5]是一个解，
	// [5,1,2]，[1,5,2]同样也是解，使用startIndex就保证只有[1,2,5]是解，
	void backtrack(vector<int>& candidates, int sum, int target, int startIndex, vector<int> path)
	{
		if (target == sum)
		{
			vec.push_back(path);
			return;
		}

		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
		{
			sum += candidates[i];
			path.push_back(candidates[i]);
			backtrack(candidates, sum, target, i, path);
			sum -= candidates[i];			// 这一句也不好理解啊。
			path.pop_back();

		}
	}
};