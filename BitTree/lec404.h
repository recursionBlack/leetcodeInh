#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution404 {
	
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr)
		{
			return 0;
		}
		int res = 0;
		if (root->left&&root->left->left == nullptr&&root->left->right == nullptr)
		{
			res += root->left->val;
		}
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + res;
		
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
		int res = sumOfLeftLeaves(m_t1);
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