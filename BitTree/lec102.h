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

class Solution102 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector <vector <int>> res;
		if (!root) {
			return res;
		}
		queue <TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			int size = que.size();
			vector<int> vec;
			res.push_back(vector <int>());
			// 这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的
			for (int i = 0; i < size; ++i) 
			{
				TreeNode* cur = que.front();
				que.pop();
				res.back().push_back(cur->val);
				if (cur->left) 
					que.push(cur->left);
				if (cur->right) 
					que.push(cur->right);
			}
			res.push_back(vec);
		}
		return res;
	}
	//	层次遍历只有一种方法，太爽了
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
		vector<vector<int>> res = levelOrder(m_t1);
		cout << "the result is: " << endl;
		for (auto items : res)
		{
			for (auto item:items)
			{
				cout << item << " ";
			}
			cout << endl;
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