#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// 分割问题
class Solution093 {
	vector<string> vec;
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> pat;
		backtrack(s, 0, pat);
		return vec;
	}

	void backtrack(string s, int startindex, vector<string> path)
	{
		//前一个条件保证切了4次，后一个条件保证用完了所有字母
		if (path.size()== 4)
		{
			if (startindex == s.length())
			{
				string res;
				for (auto s : path)
				{
					res = res + s + '.';
				}
				res.pop_back();
				vec.push_back(res);
			}
			return;
		}
		for (int i = startindex; i < s.length(); i++)
		{
			string cur = s.substr(startindex, i - startindex + 1);
			if (!isvalid(cur))
				continue;
			// 自己写出来的，根据剩余长度快速剪枝
			double limit = (double)(s.length() - startindex) / (4 - path.size());
			if (limit > 3)
				return;
			path.push_back(cur);
			backtrack(s, i + 1, path);
			path.pop_back();
		}
	}

	bool isvalid(string s)
	{
		if (s.length() == 0)
		{
			return false;
		}
		if (s.length() > 1 && s.front() == '0')
		{
			return false;
		}
		if (s.length() > 3)
		{
			return false;
		}
		else if (s.length() == 3)
		{
			if (s[0] - '0' > 2)
			{
				return false;
			}
			else if (s[0] == '2')
			{
				if (s[1] - '5' > 0)
				{
					return false;
				}
				else if (s[1] == '5')
				{
					if (s[2] - '5' > 0)
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	//	输入函数
	void ShuRu()
	{
		//2 5 5 2 5 5 1 1 1 3 5
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
		vector<string> res = restoreIpAddresses(inputnums);
		for (auto s : res)
		{
			cout << "###########" << endl;
			cout << s << endl;
		}
	}

public:

	int m_N = 0;
	int m_K = 0;

	string inputnums;

};
