#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>
#include <queue>

using namespace std;

class Solution671 {
	int ans = -1;
	int rootval;
public:
	int findSecondMinimumValue(TreeNode* root) {
		if (root == nullptr || root->left == nullptr)
		{
			return -1;
		}
		rootval = root->val;
		dfs(root);
		return ans;
	}
	// 深度优先搜索，不返回值，只用来遍历和修改全局变量ans的值。
	void dfs(TreeNode* node)
	{
		if (node==nullptr)
		{
			return;
		}
		if (ans!=-1 && node->val>=ans)
		{
			return;
		}
		if (node->val>rootval)
		{
			ans = node->val;
		}
		dfs(node->left);
		dfs(node->right);
	}
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
	}
	// 输出函数
	void CalcResult()
	{
		int res = findSecondMinimumValue(m_t1);
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
