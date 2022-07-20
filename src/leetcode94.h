#ifndef __leet_code_94__
#define __leet_code_94__

#include<iostream>
#include<vector>
#include<stack>
#include<map>

//#define RECURSIVE_METHOD // �ݹ鷨
#define ITERATION_METHOD // ������
//#define MORRIS_METHOD // Morris ���������

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
#ifdef RECURSIVE_METHOD
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

	 // �ݹ����������������
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
 };
#endif // RECURSIVE_METHOD

#ifdef ITERATION_METHOD
 class Solution {
 public:

	 // �������������������
	 std::vector<TreeNode*> inorderTraversal(TreeNode* root) {
		 std::vector<TreeNode*> results;
		 std::stack<TreeNode*> nodeStack;
		 std::map<TreeNode*, int> nodeMap; // ��־ÿ���ڵ��left node�Ƿ��Ѿ���ʹ�ù���

		 if (root == nullptr) {
			 return results;
		 }

		 nodeStack.push(root);
		 while (nodeStack.size() != 0) {
			 TreeNode *crtNode = nodeStack.top();

			 //if (crtNode->left != nullptr) {
				// nodeStack.push(crtNode->left);
				// crtNode->left = nullptr; // ��������ֱ���ƻ�����������Ƽ���nodeMap����ϣ����
				// continue;
			 //}

			 if (crtNode->left != nullptr && nodeMap.count(crtNode)==0) {
				 nodeStack.push(crtNode->left);
				 nodeMap[crtNode] = 1;
				 continue;
			 }

			 results.push_back(crtNode);
			 nodeStack.pop();
			 if (crtNode->right != nullptr) {
				 nodeStack.push(crtNode->right);
			 }

		 }

		 return results;
	 }
 };
#endif // ITERATION_METHOD

#ifdef MORRIS_METHOD
 class Solution {
 public:

	 // �������������������
	 std::vector<TreeNode*> inorderTraversal(TreeNode* root) {
		 std::vector<TreeNode*> results;

		 if (root == nullptr) {
			 return results;
		 }

		 TreeNode* crtNode = root;
		 while (crtNode != nullptr) {
			 if (crtNode->left != nullptr) {
				 TreeNode *predecessor = crtNode->left;
				 // predecessor �� crtNode �����������һ���ڵ㣬����������һֱ�� rightNode
				 while (predecessor->right != nullptr && predecessor->right != crtNode) {
					 predecessor = predecessor->right;
				 }

				 if (predecessor->right == crtNode) {
					 predecessor->right = nullptr;
					 results.push_back(crtNode);
					 crtNode = crtNode->right;
				 }
				 else {
					 // predecessor �� rightNode ��Ϊ crtNode
					 predecessor->right = crtNode;
					 crtNode = crtNode->left;
				 }

			 }
			 else {
				 results.push_back(crtNode);
				 crtNode = crtNode->right;
				 continue;
			 }
		 }

		 return results;
	 }
 };
#endif // MORRIS_METHOD

#endif //__leet_code_94__