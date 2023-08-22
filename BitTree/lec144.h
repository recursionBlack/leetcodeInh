#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution144 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if (root)
		{
			m_List.push_back(root->val);
			preorderTraversal(root->left);
			preorderTraversal(root->right);
		}
		return m_List;
	}

	// 非递归实现先序遍历
	vector<int> preOrder2(TreeNode* root)
	{
		TreeNode* cur = root;
		stack<TreeNode*> st;
		vector<int> res;
		while (!st.empty() || cur)
		{
			if (cur)
			{
				res.push_back(cur->val);			// 从根往底下推进的时候，就要进行输出了
				st.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = st.top();
				st.pop();
				cur = cur->right;
			}
		}
		return res;
	}

	// Morris遍历法
	vector<int> preOrder3(TreeNode *root) {
		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		TreeNode *p1 = root, *p2 = nullptr;

		while (p1 != nullptr) {
			p2 = p1->left;
			if (p2 != nullptr) {
				while (p2->right != nullptr && p2->right != p1) {
					p2 = p2->right;
				}
				if (p2->right == nullptr) {
					res.emplace_back(p1->val);
					p2->right = p1;
					p1 = p1->left;
					continue;
				}
				else {
					p2->right = nullptr;
				}
			}
			else {
				res.emplace_back(p1->val);
			}
			p1 = p1->right;
		}
		return res;
	}

	// 目前见过的最强的前中后遍历统一版迭代写法（只用移动左中右的顺序即可）： 
	// 前序遍历：
	vector<int> preorder0(TreeNode* root) {
		if (!root) return {};
		vector<int> result;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) {
			TreeNode* node = stk.top();
			stk.pop();
			if (node) {
				if (node->right) {
					stk.push(node->right);
				}
				if (node->left) {
					stk.push(node->left);
				}
				stk.push(node);
				stk.push(nullptr); //压了nullptr说明nullptr前面压的那个根节点的左右节点已经访问过了，
				// 可以直接储存这个根节点的数据，也就是执行else
			}
			else {
				result.push_back(stk.top()->val);
				stk.pop();
			}
		}
		return result;
	}

	// 中序遍历：
	vector<int> inorder0(TreeNode* root) 
	{
		if (!root) return {};
		vector<int> result;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) 
		{
			TreeNode* node = stk.top();
			stk.pop();
			if (node) 
			{
				if (node->right) 
				{
					stk.push(node->right);
				}
				stk.push(node);
				stk.push(nullptr);
				if (node->left) 
				{
					stk.push(node->left);
				}
			}
			else 
			{
				result.push_back(stk.top()->val);
				stk.pop();
			}
		}
		return result;
	}

	// 后序遍历：
	vector<int> postorder0(TreeNode* root)
	{
		if (!root) return {};
		vector<int> result;
		stack<TreeNode*> stk;
		stk.push(root);
		while (!stk.empty()) 
		{
			TreeNode* node = stk.top();
			stk.pop();
			if (node) 
			{
				stk.push(node);
				stk.push(nullptr);
				if (node->right) {
					stk.push(node->right);
				}
				if (node->left) {
					stk.push(node->left);
				}
			}
			else 
			{
				result.push_back(stk.top()->val);
				stk.pop();
			}
		}
		return result;
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
		vector<int> res = preorderTraversal(m_t1);
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