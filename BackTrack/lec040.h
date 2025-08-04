#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 组合问题
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> path;
		vector<int> tmp;
		backtrack(candidates, target, 0, tmp, path);
		return path;

	}

	// 反正稀里糊涂的做出来了，starindex防倒序
	void backtrack(vector<int>& candidates, int target, int starindex, vector<int>& tmp, vector<vector<int>>& path)
	{
		if(target < 0){
			return;
		}
		if (target == 0)
		{
			path.push_back(tmp);
			return;
		}
		for (size_t index = starindex; index < candidates.size(); index++)
		{
			if (index > 0 && candidates[index] == candidates[index - 1])
				continue;
						
			tmp.push_back(candidates[index]);
			// 这里注意和39题的区别，39题同一个元素可以无限次使用，index要传index，这里一个元素只能用一次，所以是index + 1
			backtrack(candidates, target - candidates[index], index + 1, tmp, path);
			tmp.pop_back();
		}
	}
};


// 打印二维向量
void printResult(const vector<vector<int>>& result) {
    cout << "[" << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "  [";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j != result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i != result.size() - 1) {
            cout << ",";
        }
        cout << endl;
    }
    cout << "]" << endl;
}

// 检查两个二维向量是否相等（不考虑内部顺序）
bool isEqual(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    if (a.size() != b.size()) return false;
    
    vector<vector<int>> a_sorted = a;
    vector<vector<int>> b_sorted = b;
    
    // 排序每个子数组
    for (auto& vec : a_sorted) sort(vec.begin(), vec.end());
    for (auto& vec : b_sorted) sort(vec.begin(), vec.end());
    
    // 排序整个二维数组
    sort(a_sorted.begin(), a_sorted.end());
    sort(b_sorted.begin(), b_sorted.end());
    
    return a_sorted == b_sorted;
}

// int main() {
//     Solution sol;
    
//     // 测试案例：题目中给出的输入
//     vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
//     int target = 8;
//     vector<vector<int>> expected = {
//         {1, 1, 6},
//         {1, 2, 5},
//         {1, 7},
//         {2, 6}
//     };
    
//     cout << "测试输入: candidates = [10,1,2,7,6,1,5], target = 8" << endl;
//     cout << "预期输出:" << endl;
//     printResult(expected);
    
//     vector<vector<int>> result = sol.combinationSum2(candidates, target);
//     cout << "实际输出:" << endl;
//     printResult(result);
    
//     if (isEqual(result, expected)) {
//         cout << "测试通过!" << endl;
//     } else {
//         cout << "测试失败!" << endl;
//     }
    
//     return 0;
// }
