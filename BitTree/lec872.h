#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution872 {
public:
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		vector<int> r1, r2;
		r1 = leafserize(root1);
		m_List.clear();
		r2 = leafserize(root2);
		// 防止二者不一样长
		if (r1.size()!=r2.size())
		{
			return false;
		}
		for (int i = 0; i <r1.size(); i++)
		{
			if (r1[i] != r2[i])
			{
				return false;
			}
		}
		return true;
	}

	// 输出叶子序列
	vector<int> leafserize(TreeNode* node)
	{
		// 中序遍历，只存叶子节点
		if (node)
		{
			leafserize(node->left);
			if (node != nullptr&&node->left==nullptr&&node->right==nullptr)
			{
				m_List.push_back(node);
			}
			leafserize(node->right);
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