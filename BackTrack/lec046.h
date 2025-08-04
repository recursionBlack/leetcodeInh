#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
	
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.empty())
		{
			return { {} };
		}
		sort(nums.begin(), nums.end());
		int n = 0;
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(nums, n, tmp, path);

		return path;

	}
	void backtrack(vector<int>& nums, int n, vector<int>& tmp, vector<vector<int>>& path)
	{
		if (n == nums.size())
		{
			path.push_back(tmp);
			return;
		}
		for (size_t i = 0; i < nums.size(); i++)
		{
			// 该数字已经用过了, 就不再使用了
            if(find(tmp.begin(),tmp.end(), nums[i]) != tmp.end())
            {
                continue;
            }

			tmp.push_back(nums[i]);    // 做选择
			backtrack(nums, n + 1, tmp, path);         // dfs
			tmp.pop_back();            //取消选择，回溯算法与dfs区别的最重要标志，
		}
	}
};


// 打印二维向量
void printVector(const vector<vector<int>>& vec) {
    cout << "[" << endl;
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j];
            if (j != vec[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != vec.size() - 1) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

// int main() {
//     Solution sol;
//     vector<int> nums = {1, 2, 3};
    
//     // 函数输出
//     vector<vector<int>> result = sol.permute(nums);
    
//     // 打印信息
//     cout << "测试输入: nums = [1,2,3]" << endl;
// 	cout << "预期输出: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]" << endl;
//     cout << "实际输出:" << endl;
//     printVector(result);
    
//     return 0;
// }