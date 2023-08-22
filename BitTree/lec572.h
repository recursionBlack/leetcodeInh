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

class Solution572 {
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root = nullptr)
		{
			return false;
		}
		// 要么等于根节点，要么等于左子树，要么等于右子树
		return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}
	bool isSameTree(TreeNode* node, TreeNode* sub)
	{
		// 递归(到底)结束条件
		if (node == nullptr&&sub== nullptr)
		{
			return true;
		}
		if (node == nullptr||sub == nullptr)
		{
			return false;
		}
		if (node->val != sub->val)
		{
			return false;
		}
		return isSameTree(node->left, sub->left) && isSameTree(node->right, sub->right);
	}
};