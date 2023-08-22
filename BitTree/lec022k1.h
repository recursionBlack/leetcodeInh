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

class Solution022k1 {
	vector<vector<int>> vecBit;
public:
	int sumRootToLeaf(TreeNode* root) {
		vector<int> str;
		dfs(root, str);
		int sum = 0;
		for (auto item:vecBit)
		{
			sum += binary2decimal(item);
		}
		return sum;
	}
	void dfs(TreeNode* T, vector<int> s)
	{
		if (!T)
		{
			return;
		}
		s.push_back(T->val);
		if (!T->left&&!T->right)
		{
			vecBit.push_back(s);
			return;
		}
		dfs(T->left, s);
		dfs(T->right, s);
	}

	int binary2decimal(vector<int> binary)
	{
		int decimal = 0;
		int size = binary.size();
		for (int i = size - 1; i >=0; i--)
		{
			decimal |= (binary[i] << (size - i - 1));
		}
		return decimal;
	}

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