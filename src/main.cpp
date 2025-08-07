#include <iostream>
#include "lec078.h"

using namespace std;

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    
    // 函数输出
    vector<vector<int>> result = sol.subsets(nums);
    
    // 打印信息
    cout << "测试输入: nums = [1,2,3]" << endl;
    cout << "预期输出（所有子集）: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]" << endl;
    cout << "实际输出:" << endl;
    printSubsets(result);

    return 0;
}