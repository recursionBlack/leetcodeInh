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

class Solution616 {
public:
	string tree2str(TreeNode* root) {
		if (root == nullptr)
		{
			return "";
		}
		if (!root->left&&!root->right)
		{
			return to_string(root->val);
		}
		string res = to_string(root->val);
		if (root->left)
		{
			res += "(" + tree2str(root->left) + ")";
		}
		else
		{
			res += "()";
		}
		if (root->right)
		{
			res += "(" + tree2str(root->right) + ")";
		}
		return res;
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