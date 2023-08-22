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

class Solution257 {
	vector<string> res;
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		string s;
		dfs(root, s);
		return res;
	}

	void dfs(TreeNode* T, string s)
	{
		// 空值直接返回
		if (T == nullptr)
		{
			return;
		}
		s +=to_string(T->val) + "->";
		// 到达叶子节点时，返回
		if (T->left==nullptr&&T->right==nullptr)
		{
			//去掉最后一个“->”
			s.pop_back();
			s.pop_back();
			res.push_back(s);
			return;
		}
		// 没到叶子节点
		dfs(T->left, s);
		dfs(T->right, s);
	}
	// 自己做出来的，好开心呀!
	//	输入函数
	void ShuRu()
	{
		cout << "please putin preoder list" << endl;
		int Inputnum;
		while (cin >> Inputnum)
		{
			m_preorder.push_back(Inputnum);
		}
		cin.clear();
		cin.ignore();

		cout << "please putin inorder list" << endl;
		while (cin >> Inputnum)
		{
			m_inorder.push_back(Inputnum);
		}
		cin.clear();
		cin.ignore();

		m_t1 = buildTree(m_preorder, m_inorder);

		cout << "please putin target num" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		bool res = hasPathSum(m_t1, m_K);
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
	TreeNode* m_t1;
	TreeNode* m_t2;

};