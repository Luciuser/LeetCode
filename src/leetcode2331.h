/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-06 20:01:03
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2331.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-06 20:06:04
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 34.45%, MEMORY 14.5MB and 78.99%
 */

#ifndef __leet_code_2331_h__
#define __leet_code_2331_h__

#include<iostream>

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
	bool evaluateTree(TreeNode* root) {
		if (root->val == 0 || root->val == 1) {
			return root->val;
		}
		else if (root->val == 2) {
			bool result = false;
			if (root->left != nullptr) {
				result = result || evaluateTree(root->left);
			}
			if (root->right != nullptr) {
				result = result || evaluateTree(root->right);
			}
			return result;
		}
		else if (root->val == 3) {
			bool result = true;
			if (root->left != nullptr) {
				result = result && evaluateTree(root->left);
			}
			if (root->right != nullptr) {
				result = result && evaluateTree(root->right);
			}
			return result;
		}
		return true;
	}
};

#endif // __leet_code_2331_h__