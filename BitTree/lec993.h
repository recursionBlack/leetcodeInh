#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>
#include <string>

using namespace std;

class Solution993 {
	vector<vector<int>> res;
public:
	bool isCousins(TreeNode* root, int x, int y) {
		vector<int> str;
		dfs(root, str, x);
		str.clear();
		dfs(root, str, y);
		if (res.front().size() == res.back().size())
		{
			vector<int> a = res.front();
			vector<int> b = res.back();
			// 如果路径长度相同，还要避免同一个父节点，
			if (a.back() == b.back())
			{
				return false;
			}
			return true;
		}
		return false;
	}

	void dfs(TreeNode* T,vector<int> s,  int k)
	{
		if (!T)
		{
			return;
		}
		if (k == T->val)
		{
			res.push_back(s);
			return;
		}
		s.push_back(T->val);
		dfs(T->left, s, k);
		dfs(T->right, s, k);
	}
	//	输入函数
	void ShuRu()
	{
		cout << "please putin leveloder list" << endl;
		int Inputnum;
		while (cin >> Inputnum)
		{
			m_levelorder.push_back(Inputnum);
		}
		cin.clear();
		cin.ignore();

		m_t1 = levelOrderToTree(m_levelorder);

		cout << "please putin target num" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();

		cout << "please putin target num" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		bool res = isCousins(m_t1, m_N, m_K);
		cout << "the result is: " << endl;
		cout << res << " ";
		cout << endl;
	}

public:

	int m_N = 0;
	int m_K = 0;
	vector<int> m_List;
	vector<int> m_preorder;
	vector<int> m_inorder;
	vector<int>	m_levelorder;
	TreeNode* m_t1;
	TreeNode* m_t2;

};