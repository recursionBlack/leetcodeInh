#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution491 {
	vector<vector<int>> vec;
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<int> pat;
		backtrack(nums, 0, pat);
		return vec;
	}

	// 该题难点在于，对于又重复元素，但又不能排序，该如何去重呢？
	// 能排序的去重可以通过used数组+nums[i]==nums[i-1]来判断，因为相同的元素经过排序后是相邻的，
	// 但本题是不能排序的，评论区采用了同层map来实现同层去重功能
	void backtrack(const vector<int>& nums, int startindex, vector<int> path)
	{
		//因为题目要求是返回至少两个元素，并且是递增子序列，所以条件是加入path路径的长度大于1即可
		//但是这里注意的是不能return，因为return了只能返回path.size==nums.length的最后一个集合
		if (path.size() > 1)
		{
			vec.push_back(path);
		}

		unordered_map<int, int> map;								// 为什么map放在这里，就能实现同层去重啊？
		for (int i = startindex; i < nums.size(); i++)
		{

			//保证递增
			if (path.size() > 0 && path.back() > nums[i])
				continue;
			//同层去重
			if (map[nums[i]] > 0)
				continue;
			map[nums[i]]++;
			path.push_back(nums[i]);
			backtrack(nums, i + 1, path);
			path.pop_back();
		}
	}

	//	输入函数
	void ShuRu()
	{
		//[4,6,7,7] 4 6 7 7
		//[4,4,3,2,1] 4 4 3 2 1
		cout << "please putin str list" << endl;
		int c;
		while (cin >> c)
		{
			M_nums.push_back(c);
		}
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		vector<vector<int>> res = findSubsequences(M_nums);
		for (auto s : res)
		{
			for (auto c:s)
			{
				cout << c << "  ";
			}
			cout << endl;
			cout << "###########" << endl;
		}
	}

public:

	int m_N = 0;
	int m_K = 0;

	string inputnums;
	vector<int>  M_nums;

};