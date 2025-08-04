#include <vector>
#include <string>
#include <iostream>

using namespace std;

// 子集问题
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(nums, 0, tmp, path);
		return path;
	}

	// 这个题比较怪，时间复杂度为2^n，因为对于nums里的每一个数，都有两种选择，加如或者不加入
   // 每个数字都有两种选择，所以共有2^n种选择，那点在于，怎么表示不加入。
	void backtrack(const vector<int>& nums, int starindex, vector<int>& tmp, vector<vector<int>>& path)
	{
		path.push_back(tmp);				// 不加入，因为本轮递归的数字还没加进path里，
		for (size_t i = starindex; i < nums.size(); i++)
		{
			tmp.push_back(nums[i]);		// 加入
			backtrack(nums, i + 1, tmp, path);
			tmp.pop_back();
		}
	}
};

// 打印二维向量
void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[" << endl;
    for (size_t i = 0; i < subsets.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < subsets[i].size(); ++j) {
            cout << subsets[i][j];
            if (j != subsets[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != subsets.size() - 1) {
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
//     vector<vector<int>> result = sol.subsets(nums);
    
//     // 打印信息
//     cout << "测试输入: nums = [1,2,3]" << endl;
//     cout << "预期输出（所有子集）: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]" << endl;
//     cout << "实际输出:" << endl;
//     printSubsets(result);
    
//     return 0;
// }