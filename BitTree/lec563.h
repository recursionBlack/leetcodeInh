#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution563 {
	int res = 0;
public:
	int findTilt(TreeNode* root) {
		sum(root);
		return res;

	}

	int sum(TreeNode* node)
	{
		if (node ==nullptr)
		{
			return 0;
		}
		int sumleft = sum(node->left);
		int sumright = sum(node->right);
		res += fabs(sumleft - sumright);			// 太精妙了，递归中计算了梯度值，但不作为递归的返回值，
		return node->val + sumleft + sumright;
	}
	vector<int> preorder(TreeNode* root)
	{
		if (root)
		{
			m_List.push_back(root->val);
			preorder(root->left);
			preorder(root->right);
		}
		return m_List;
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
		int res = findTilt(m_t1);
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