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

class Solution897 {
	vector<int> vec;
public:
	TreeNode* increasingBST(TreeNode* root) {
		if (root == nullptr)
		{
			return nullptr;
		}
		vec.clear();
		dfs(root);
		TreeNode* T = new TreeNode(vec[0]);
		TreeNode* cur = T;
		for (int i = 1; i < vec.size(); i++)
		{
			TreeNode* tmp = new TreeNode(vec[i]);
			cur->right = tmp;
			cur = cur->right;
		}
		return T;
	}

	void dfs(TreeNode* root)
	{
		if (root)
		{
			dfs(root->left);
			vec.push_back(root->val);
			dfs(root->right);
		}
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

	}
	// 输出函数
	void CalcResult()
	{
		TreeNode* res = increasingBST(m_t1);
		cout << "the result is: " << endl;
		//cout << res << " ";
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