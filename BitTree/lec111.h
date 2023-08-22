#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution111 {
public:
	int minDepth(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		if (root->left&&root->right == nullptr)
		{
			return 1 + minDepth(root->left);
		}
		if (root->left == nullptr&&root->right)
		{
			return 1 + minDepth(root->right);
		}
		return 1 + min(minDepth(root->left), minDepth(root->right));

	}
	// 测例，先[3 9 4 5 7] , 中[9 3 5 4 7], 后[9 5 7 4 3]
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
		int res = minDepth(m_t1);
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