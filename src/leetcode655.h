/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-22 10:29:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode655.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-22 10:50:00
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 4ms, 41.40%, MEMORY 8.2MB and 40.00%
 */

#ifndef __leet_code_655__
#define __leet_code_655__

#include<iostream>
#include<math.h>
#include<vector>
#include<string>

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

	void dfsDeep(const TreeNode* root, const int deep) {
		if (deep > height) {
			height = deep;
		}
		if (root->left) {
			dfsDeep(root->left, deep + 1);
		}
		if (root->right) {
			dfsDeep(root->right, deep + 1);
		}
	}

	void dfsPosition(const TreeNode* root, const int r, const int c, std::vector<std::vector<std::string>> &result) {
		if (root->left) {
			int newR = r + 1;
			int newC = c - pow(2, height - r - 1);
			result[newR][newC] = std::to_string(root->left->val);
			dfsPosition(root->left, newR, newC, result);
		}
		if (root->right) {
			int newR = r + 1;
			int newC = c + pow(2, height - r - 1);
			result[newR][newC] = std::to_string(root->right->val);
			dfsPosition(root->right, newR, newC, result);
		}
	}

	std::vector<std::vector<std::string>> printTree(TreeNode* root) {

		// dfs 获得树的高度 height
		dfsDeep(root, 0);

		std::vector<std::vector<std::string>> result(height + 1, std::vector<std::string>(pow(2, height + 1) - 1, ""));

		// dfs 赋值
		int r = 0;
		int c = ((pow(2, height + 1) - 1) - 1) / 2;
		result[r][c] = std::to_string(root->val);
		dfsPosition(root, r, c, result);

		return result;
	}

private:
	int height = 0;

};

#endif // __leet_code_655__