/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-02 20:21:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode687.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-25 20:39:39
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 108ms, 13.71%, MEMORY 58.4MB and 66.40%
 */

#ifndef __leet_code_687__
#define __leet_code_687__

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

	void dfs(TreeNode *node, int length) {
		if (length > max) {
			max = length;
		}
		if (node->left != nullptr) {
			if (node->left->val == node->val) {
				dfs(node->left, length+1);
			}
			else {
				dfs(node->left, 0);
			}
		}
		if (node->right != nullptr) {
			if (node->right->val == node->val) {
				if (node->left != nullptr && node->right->val == node->left->val) {
					int TempMax = 
					dfs(node->right, length + 1);
				}
				else {
					dfs(node->right, length + 1);
				}
			}
			else {
				dfs(node->right, 0);
			}
		}
		return;
	}

	int longestUnivaluePath(TreeNode* root) {
		if (root != nullptr) {
			dfs(root, 0);
		}
		return max;
	}

private:
	int max = 0;
	int tempKey = -1;
	int tempLength = 0;
};

#endif // __leet_code_687__