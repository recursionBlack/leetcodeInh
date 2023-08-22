#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution101 {
public:
	bool isSymmetric(TreeNode* root) {
		return isSameTree(root->left, root->right);
	}
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr && q == nullptr)
		{
			return true;
		}
		if (p == nullptr)
		{
			return false;
		}
		if (q == nullptr)
		{
			return false;
		}
		if (p->val == q->val)
		{
			return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
		}
		else
		{
			return false;
		}
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
		vector<int> res = inorderTraversal(m_t1);
		cout << "the result is: " << endl;
		for (auto item : res)
		{
			cout << item << " ";
		}
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