#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

//分割问题
class Solution131 {
	vector<vector<string>> vec;
public:
	vector<vector<string>> partition(string s) {
		vector<string> pat;
		backtrack(s, 0, pat);
		return vec;
	}

	//分割问题好难想明白啊！！！ starindex居然是分割线的位置
	void backtrack(string s, int starindex, vector<string> path)
	{
		if (starindex == s.length())
		{
			vec.push_back(path);
			return;
		}

		for (int i = starindex; i < s.length(); i++)
		{
			string str = s.substr(starindex, i - starindex + 1);
			if (isvalid(str))
			{
				path.push_back(str);
				backtrack(s, i + 1, path);
				path.pop_back();
			}
			else
			{
				continue;
			}
		}
	}

	bool isvalid(string s)
	{
		if (s.empty())
		{
			return false;
		}
		int i = 0;
		int j = s.length() - 1;
		while (i <= j)
		{
			if (s[i] != s[j])
			{
				return false;
			}
			i++;
			j--;
		}
		return true;
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
		vector < vector<string>> res = partition(inputnums);
		for (auto s : res)
		{
			cout << "###########" << endl;
			for (auto c:s)
			{
				cout << c << " ";
			}
			cout << endl;
		}
	}

public:

	int m_N = 0;
	int m_K = 0;

	string inputnums;

};