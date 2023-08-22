#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution094 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root)
		{
			inorderTraversal(root->left);
			m_List.push_back(root->val);
			inorderTraversal(root->right);
		}
		return m_List;			// 注意，这里要用成员容器，而不要用局部变量当容器，否则只会存一个元素
	}

	// 非递归实现中序遍历
	vector<int> InOrder2(TreeNode* root)
	{
		TreeNode* cur = root;
		vector<int> res;
		if (!cur) return res;
		stack<TreeNode*> st;
		while (!st.empty() || cur) {
			if (cur) {
				st.push(cur);
				cur = cur->left;
			}
			else {
				cur = st.top();
				st.pop();
				res.push_back(cur->val);		// 左孩子已经被遍历完后，才开始输出

				cur = cur->right;
			}
		}
		return res;
	}
	
	// Morris遍历法
	// Morris遍历法是一种利用线索二叉树的思想来实现二叉树遍历的算法。
	vector<int>  InOrder3(TreeNode* root) {
		vector<int> res;
		TreeNode *predecessor = nullptr;

		while (root != nullptr) {
			if (root->left != nullptr) {
				// predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
				// pre指针，指向当前节点左子树的最右侧的叶子节点，然后，让pre指针的右孩子指向当前节点
				// pre主要是用来记录回来的路，和线索二叉树类似，就不需要用栈了
				predecessor = root->left;
				while (predecessor->right != nullptr && predecessor->right != root) {
					predecessor = predecessor->right;
				}

				// 让 predecessor 的右指针指向 root，继续遍历左子树
				if (predecessor->right == nullptr) {
					predecessor->right = root;
					root = root->left;
				}
				// 说明左子树已经访问完了，我们需要断开链接
				// 进到这个条件里，说明，我们已经从最左侧的叶子节点，通过pre指针构建的线索，回来了，
				// 当前节点的左子树已经被全部遍历过了，需要把pre指针搭建的线索，给断掉
				// 这一步，其实是在下一个else的后面。
				else {
					res.push_back(root->val);
					predecessor->right = nullptr;
					root = root->right;
				}
			}
			// 如果没有左孩子，则直接访问右孩子
			else {
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;
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
		for(auto item:res)
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