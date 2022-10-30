/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-30 10:49:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode998.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-30 10:33:09
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 0ms, 100.00%, MEMORY 13MB and 70.82%
 */

#ifndef __leet_code_998__
#define __leet_code_998__

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

	void dfs(TreeNode* father, int val) {
		if (father->right == nullptr) {
			TreeNode *newNode = new TreeNode(val);
			father->right = newNode;
		}
		else {
			if (father->right->val < val) {
				TreeNode *newNode = new TreeNode(val);
				newNode->left = father->right;
				father->right = newNode;
			}
			else {
				dfs(father->right, val);
			}
		}
	}

	TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
		if (root->val < val) {
			TreeNode *newNode = new TreeNode(val);
			newNode->left = root;
			return newNode;
		}
		else {
			dfs(root, val);
		}

		return root;
	}
};

#endif // __leet_code_998__