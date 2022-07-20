#ifndef __leet_code_audition_04_06__
#define __leet_code_audition_04_06__

#include<iostream>
#include<vector>

//#define BUILD_TABLE_METHOD // 建立二叉树中序表，并直接搜索
#define VALUE_OF_TREE_METHOD // 通过二叉搜索树的概念来生成

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
#ifdef BUILD_TABLE_METHOD
 class Solution {
 public:

	 int inorderTraversalNode(TreeNode* node, std::vector<TreeNode*>& results) {

		 if (node == nullptr) {
			 return 0;
		 }

		 inorderTraversalNode(node->left, results);
		 results.push_back(node);
		 inorderTraversalNode(node->right, results);

		 return 0;
	 }

	 // 递归生成中序遍历功能
	 std::vector<TreeNode*> inorderTraversal(TreeNode* root) {
		 std::vector<TreeNode*> results;

		 if (root == nullptr) {
			 return results;
		 }

		 inorderTraversalNode(root->left, results);
		 results.push_back(root);
		 inorderTraversalNode(root->right, results);

		 return results;
	 }

	 TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

		 std::vector<TreeNode *> results = inorderTraversal(root);
		 if (results.size() == 0) {
			 return nullptr;
		 }

		 for (int i = 0; i < results.size(); i++) {
			 if (results[i] == p) {
				 if (i == results.size() - 1) {
					 return nullptr;
				 }
				 else {
					 return results[i + 1];
				 }
			 }

		 }

		 return nullptr;
	 }
 };
#endif // BUILD_TABLE_METHOD

#ifdef VALUE_OF_TREE_METHOD
 class Solution {
 public:

	 TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		 
		 TreeNode* result = nullptr;
		 TreeNode* crtNode = root;
		 
		 while (true) {
			 if (crtNode->val <= p->val) {
				 if (crtNode->right == nullptr) {
					 break;
				 }
				 crtNode = crtNode->right;
			 }
			 else if (crtNode->val > p->val) {
				 result = crtNode;
				 if (crtNode->left == nullptr) {
					 break;
				 }
				 crtNode = crtNode->left;
			 }
		 }

		 return result;
	 }
 };
#endif // VALUE_OF_TREE_METHOD


#endif //__leet_code_audition_04_06__