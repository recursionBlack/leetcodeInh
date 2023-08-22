#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include "MyTreeNode.h"
//#include "../Stack/MyStack.h"
#include <stack>

using namespace std;

class Solution145 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if (root)
		{
			postorderTraversal(root->left);
			postorderTraversal(root->right);
			m_List.push_back(root->val);
		}
		return m_List;
	}

	// 非递归实现后序遍历, 后序的是最难的，
	// 当开始看这个题时，我的左眼两次都跳了，
	vector<int> PostOrder2(TreeNode* root) 
	{
		vector<int> res;
		if (root == nullptr) {
			return res;
		}

		stack<TreeNode*> stk;
		TreeNode* cur = root;
		TreeNode *prev = nullptr;
		while (!stk.empty() || cur != nullptr) {
			// 先一路往左走，遍历完左子树
			while (cur != nullptr) {
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			
			// 第一个条件，保证最右侧子树已经遍历完了，cur是最右侧叶子节点
			// 第二个条件，是退回来后，用来证明右侧子树已经遍历过了，不用再往右子树进了，
			if(cur->right == nullptr || cur->right == prev)	
			{
				res.push_back(cur->val);
				prev = cur;
				cur = nullptr;
			}
			else
			{
				stk.push(cur);
				cur = cur->right;
			}
			
		}
		return res;
	}

	/*二叉树前中后序的递归版本属于easy题，而迭代版本通常是medium甚至是hard。
		在做迭代版本之前，我建议大家先问问各类“遍历”算法的本质是什么？
		是最后输出的那一串有序的数字吗？数字的顺序是对的，遍历算法就是对的吗？
		个人认为，以上问题的答案都应该是：否。“遍历”的本质是对内存的有序访问，
		失去了访问顺序，即便你用各种数据结构恢复了这个次序，遍历本身也显得毫无意义。
		这个问题有一种很优雅的写法是先reverse(in)，
		然后再逐词翻转——“两次反转”，最后得到的就是正确顺序。
		回到二叉树后序遍历，你也可以利用这种思想，利用双向链表的addFirst，
		对外部次序和内含次序进行同时翻转，同样会得到一种非常”优雅”的解法，
		结构简单明晰，甚至还有点好背（狗头）。
		但是，它并没有真正实现“遍历”——仔细看会发现，
		该算法其实在使用一种异构的前序遍历：“中->右->左”，而非传统意义上的“中->左->右”，
		而这种异构也正是他的第一次反转。而第二次反转就在输出序列上。
		所以本质上，这是一个“前序遍历”，而不是所谓的“后序遍历”。
		只有当你的各个节点以“左->右->中”的次序依次出现在迭代的loop当中时，
		它才是真正的后序遍历，就像官解那样。
	*/
	// Morris 遍历的方法
	vector<int> PostOrder3(TreeNode* root)
	{
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
		vector<int> res = PostOrder2(m_t1);
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