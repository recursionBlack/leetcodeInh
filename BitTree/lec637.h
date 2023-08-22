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

class Solution637 {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<vector<int>> lo;
		vector<double> res;
		lo = levelOrder(root);
		for (auto item : lo)
		{
			int size = item.size();
			if (size == 0)
			{
				continue;
			}
			double sum = 0.0;
			for (int it : item)
			{
				sum += it;
			}
			res.push_back(sum / size);
		}
		return res;
	}
	// 层序遍历
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
			for (int i = 1; i <= size; ++i)
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

		cout << "please putin target num" << endl;
		cin >> m_N;
		cin.clear();
		cin.ignore();

		cout << "please putin target num" << endl;
		cin >> m_K;
		cin.clear();
		cin.ignore();

	}
	// 输出函数
	void CalcResult()
	{
		bool res = isCousins(m_t1, m_N, m_K);
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
	vector<int>	m_levelorder;
	TreeNode* m_t1;
	TreeNode* m_t2;

};