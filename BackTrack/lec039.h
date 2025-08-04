#include <vector>
#include <algorithm>

using namespace std;

// 组合问题
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> path;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end()); // 需要排序
		backtrack(candidates, target, 0, tmp, path);
		return path;
	}

	// 我真的服了，为什么我始终理解不了这个 begin呢？
	// 该值主要用来，防止倒序的结果再出现一遍，比如，[1,2,5]是一个解，
	// [5,1,2]，[1,5,2]同样也是解，使用begin就保证只有[1,2,5]是解，
	void backtrack(vector<int>& candidates, int target, size_t begin, vector<int>& tmp, vector<vector<int>>& path)
	{
		if (target < 0)
		{
			return;
		}
		if (target == 0)
		{
			path.push_back(tmp);
			return;
		}

		for (size_t index = begin; index < candidates.size(); index++)
		{
			tmp.push_back(candidates[index]);
			backtrack(candidates, target - candidates[index], index, tmp, path);
			tmp.pop_back();
		}
	}
};

/*
`startIndex`是回溯算法中避免组合重复的关键机制，它的核心作用是**控制每一层递归中选择元素的起始位置**，从而防止出现顺序不同但元素相同的重复组合。

### 具体工作原理：
假设`candidates = [2,3,6,7]`，`target = 7`（已排序）。

1. **第一层递归（startIndex=0）**：
   - 从索引0（元素2）开始选择：
     - 选2 → 进入第二层递归
     - 选3 → 进入第二层递归（但此时不会再回头选2，因为startIndex控制了起点）
     - 选6、7同理

2. **第二层递归（startIndex=i，i是上一层选择的元素索引）**：
   - 如果上一层选了2（索引0），本层startIndex=0：
     - 可以继续选2（允许重复使用元素）
     - 但不能选比2更早的元素（实际也没有更早的）
   - 如果上一层选了3（索引1），本层startIndex=1：
     - 可以选3、6、7
     - 但**不能再选2**（因为2的索引0 < startIndex=1）
     - 这就避免了出现`[3,2]`这种与`[2,3]`重复的组合

3. **关键逻辑**：
   - 每一层递归只能从`startIndex`及之后的元素中选择
   - 彻底杜绝了"回头选前面元素"的可能性
   - 配合数组排序，确保所有组合都是**非递减顺序**的，自然不会有重复

### 反例说明（如果没有startIndex）：
- 第一层选2，第二层选3 → 得到[2,3]
- 第一层选3，第二层选2 → 得到[3,2]
- 这两个组合元素相同但顺序不同，会被视为重复解

通过`startIndex`的限制，确保了**组合内部元素的相对顺序与原数组一致**，从根源上避免了重复组合的产生。

*/

// 打印二维向量
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j != result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// int main() {
//     Solution sol;

//     // 测试案例1：基础测试
//     cout << "测试案例1: candidates = [2,3,6,7], target = 7" << endl;
//     vector<int> c1 = {2,3,6,7};
//     auto res1 = sol.combinationSum(c1, 7);
//     cout << "预期结果: [[2,2,3],[7]]" << endl;
//     cout << "实际结果: ";
//     printResult(res1);
//     cout << endl;

//     // 测试案例2：单个元素
//     cout << "测试案例2: candidates = [3], target = 9" << endl;
//     vector<int> c2 = {3};
//     auto res2 = sol.combinationSum(c2, 9);
//     cout << "预期结果: [[3,3,3]]" << endl;
//     cout << "实际结果: ";
//     printResult(res2);
//     cout << endl;

//     // 测试案例3：无解决方案
//     cout << "测试案例3: candidates = [2,4], target = 5" << endl;
//     vector<int> c3 = {2,4};
//     auto res3 = sol.combinationSum(c3, 5);
//     cout << "预期结果: []" << endl;
//     cout << "实际结果: ";
//     printResult(res3);
//     cout << endl;

//     // 测试案例4：重复使用多个元素
//     cout << "测试案例4: candidates = [2,5], target = 10" << endl;
//     vector<int> c4 = {2,5};
//     auto res4 = sol.combinationSum(c4, 10);
//     cout << "预期结果: [[2,2,2,2,2],[5,5]]" << endl;
//     cout << "实际结果: ";
//     printResult(res4);
//     cout << endl;

//     return 0;
// }