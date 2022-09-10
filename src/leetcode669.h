/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-10 16:26:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode669.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-08 16:37:30
 * @Editor: Bingyang Jin
 * @Description: create DFS_RECURSION_METHOD，TIME 12ms, 83.08%, MEMORY 23.4MB and 7.64%
 */

 /*
 * @EditTime: 2022-09-08 17:07:39
 * @Editor: Bingyang Jin
 * @Description: create DFS_LTERATION_METHOD，TIME 12ms, 83.08%, MEMORY 23.3MB and 62.37%
 */

#ifndef __leet_code_669__
#define __leet_code_669__

#include<iostream>

//#define DFS_RECURSION_METHOD // 深度优先搜索，递归法，TIME 12ms, 83.08%, MEMORY 23.4MB and 7.64%
#define DFS_LTERATION_METHOD // 深度优先搜索，迭代法，TIME 12ms, 83.08%, MEMORY 23.4MB and 7.64%

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef DFS_METHOD
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root->val < low) {
			return trimBST(root->right, low, high);
		}
		else if (high < root->val) {
			return trimBST(root->left, low, high);
		}
		else {
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
			return root;
		}
	}
};
#endif // DFS_METHOD

#ifdef DFS_LTERATION_METHOD
class Solution {
public:
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		// 找到根节点
		while (true) {
			if (root == nullptr) {
				return nullptr;
			}
			if (root->val < low) {
				root = root->right;
			}
			else if (high < root->val) {
				root = root->left;
			}
			else {
				break;
			}
		}

		// 修剪左子树
		TreeNode *father = root;
		TreeNode *left = root->left;
		while (left != nullptr) {
			if (left->val < low) {
				left = left->right;
			}
			else {
				father->left = left;
				father = left;
				left = left->left;
			}
		}
		father->left = left;

		// 修剪右子树
		father = root;
		TreeNode *right = root->right;
		while (right != nullptr) {
			if (high < right->val) {
				right = right->left;
			}
			else {
				father->right = right;
				father = right;
				right = right->right;
			}
		}
		father->right = right;

		return root;
	}
};
#endif // DFS_LTERATION_METHOD



#endif // __leet_code_669__