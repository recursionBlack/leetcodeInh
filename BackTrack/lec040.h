#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 组合问题
class Solution040 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> pat;
		vector<bool> used(candidates.size(), false);
		backtrack(candidates, target, used, 0, 0, pat);
		return vec;

	}

	// 反正稀里糊涂的做出来了，used防止重复使用，starindex防倒序
	void backtrack(vector<int>& candidates, int target, vector<bool> used, int sum, int starindex, vector<int>path)
	{
		if (sum == target)
		{
			vec.push_back(path);
			return;
		}
		for (int i = starindex; i < candidates.size() && sum + candidates[i] <= target; i++)
		{
			if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1])
				continue;
			if (used[i])
				continue;

			sum += candidates[i];						
			path.push_back(candidates[i]);
			used[i] = true;
			backtrack(candidates, target, used, sum, i, path);
			used[i] = false;
			path.pop_back();
			sum -= candidates[i];					//上两个操作我都能理解，但这个我始终理解不了。
		}
	}
};