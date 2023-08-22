#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution017 {
	//组合问题
public:
	string tmp = " ";
	vector<string> board = { "", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ans;

	void dfs(int pos, string digits) {
		if (pos == digits.size()) {
			ans.push_back(tmp);
			return;
		}
		int num = digits[pos] - 'a'; //表示按到了键盘上的第几个键
		for (int i = 0; i < board[num].size(); i++) {
			// 没有任何筛选条件，所以算是最简单的回溯题了，
			tmp.push_back(board[num][i]);
			dfs(pos + 1, digits);  //递归下一层
			tmp.pop_back();      //回溯
		}
	}

	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		dfs(0, digits);
		return ans;
	}

	//	输入函数
	void ShuRu()
	{
		cout << "please putin str list" << endl;
		char c;
		while (cin >> c)
		{
			inputnums.push_back(c);
		}
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		vector<string> res = letterCombinations(inputnums);
		for (auto s:res)
		{
			cout << s << " " << endl;

		}
	}

public:

	int m_N = 0;
	int m_K = 0;

	string inputnums;

};