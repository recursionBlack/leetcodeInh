#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution077 {
	//组合问题，数学中的Cnk
	vector<vector<int>> res;
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> pat;

		backtrack(1, n, k, pat);
		return res;
	}

	// curstar是当前起始参数，
	void backtrack(int curstar, int n, int k, vector<int> path)
	{
		if (k == path.size())
		{
			res.push_back(path);
			return;
		}
		
		// 这个题，神奇就神奇在i = curstar， 与backtrack函数的第一个参数上
		for (int i = curstar; i <= n; i++)
		{
			path.push_back(i);
			backtrack(i + 1, n, k, path);  // 
			path.pop_back();
		}
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin n" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();

		cout << "please putin k" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		vector<vector<int>> res = combine(m_N, m_K);
		for (auto s : res)
		{
				for (int c:s)
				{
					cout << c << " ";
				}
				cout << endl;
		}
	}

public:

	int m_N = 0;
	int m_K = 0;

};