/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-05 10:48:27
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode623.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-05 11:05:15
 * @Editor: Bingyang Jin
 * @Description: create RECURSION_METHOD, TIME 12 ms, MEMORY 24.3 MB
 */

#ifndef __leet_code_623__
#define __leet_code_623__

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  

class Solution {
public:

	void addOneRowInDepth(TreeNode* node, int nodeDepth, int val, int depth) {
		if (node == nullptr) {
			return;
		}
		if (nodeDepth == depth - 1) {
			TreeNode* newNodeLeft = new TreeNode(val, node->left, nullptr);
			TreeNode* newNodeRight = new TreeNode(val, nullptr, node->right);
			node->left = newNodeLeft;
			node->right = newNodeRight;
			return;
		}
		addOneRowInDepth(node->left, nodeDepth + 1, val, depth);
		addOneRowInDepth(node->right, nodeDepth + 1, val, depth);
		return;
	}

	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
		if (depth == 1) {
			TreeNode* newNode = new TreeNode(val, root, nullptr);
			return newNode;
		}

		addOneRowInDepth(root, 1, val, depth);
		return root;
	}
};

#endif // __leet_code_623__