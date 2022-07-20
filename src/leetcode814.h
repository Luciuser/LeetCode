/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-21 00:30:24
 * @FilePath: /src/leetcode814.h
 * @Description: create th recurrence method
 */

#ifndef __leet_code_814__
#define __leet_code_814__


//  Definition for a binary tree node.
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

	TreeNode* pruneTree(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}

		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (root->left == nullptr && root->right == nullptr && root->val == 0) {
			return nullptr;
		}

		return root;
	}
};

#endif // __leet_code_814__