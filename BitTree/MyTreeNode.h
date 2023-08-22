#include<iostream>
#include<Vector>
#include<stdlib.h>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

 //Definition for a binary tree node.
 struct TreeNode 
 {
	 int val;
	 TreeNode *left;
	 TreeNode *right;
	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

 };

 // 层序遍历生成二叉树
 TreeNode* levelOrderToTree(vector<int>& nodes) {	 if (nodes.empty()) {		 return NULL;	 }	 TreeNode* root = new TreeNode(nodes[0]);	 queue<TreeNode*> q;	 q.push(root);	 int i = 1;	 while (!q.empty()) {		 TreeNode* node = q.front();		 q.pop();		 if (i < nodes.size() && nodes[i] != -1) {			 node->left = new TreeNode(nodes[i]);			 q.push(node->left);		 }		 i++;		 if (i < nodes.size() && nodes[i] != -1) {			 node->right = new TreeNode(nodes[i]);			 q.push(node->right);		 }		 i++;	 }	 return root; }

 //	pre_left表示preorder中子树的起点，pre_right表示preorder中子树的终点
  //in_left表示inorder中子树的起点，in_right表示inorder中子树的终点
 TreeNode* buildTree(vector<int>& preorder, int pre_left, int pre_right,
	 vector<int>& inorder, int in_left, int in_right) {
	 if (pre_left > pre_right)
		 return nullptr;
	 int root_val = preorder[pre_left];
	 int i = in_left;
	 while (i <= in_right && inorder[i] != root_val)		// i就是根节点在 inorder中的位置
		 ++i;
	 int left_len = i - in_left;			// 左子树的长度
	 auto* root = new TreeNode(root_val);
	 root->left = buildTree(preorder, pre_left + 1, pre_left + left_len,
		 inorder, in_left, i - 1);
	 root->right = buildTree(preorder, pre_left + left_len + 1, pre_right,
		 inorder, i + 1, in_right);
	 return root;
 }

 // 传入先序遍历和中序遍历序列，构造二叉树
 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	 if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size())
		 return nullptr;
	 int n = preorder.size();
	 return buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
 }
 // 删除树
 void destroy_tree(TreeNode* node) {
	 if (node) {
		 destroy_tree(node->left);
		 destroy_tree(node->right);
		 delete node;
	 }
 }

