/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-25 20:32:23
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1302.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-25 20:39:39
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 108ms, 13.71%, MEMORY 58.4MB and 66.40%
 */

 /*
 * @EditTime: 2022-08-25 20:54:49
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 128ms, 6.19%, MEMORY 60.4MB and 27.08%
 */

#ifndef __leet_code_1302__
#define __leet_code_1302__

#include<iostream>
#include<queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
//#define DFS_METHOD // 深度优先搜索，TIME 108ms, 13.71%, MEMORY 58.4MB and 66.40%
#define BFS_METHOD // 广度优先搜索，TIME 128ms, 6.19%, MEMORY 60.4MB and 27.08%

#ifdef DFS_METHOD
class Solution {
public:

	int dfs(TreeNode* node, int deep) {
		if (node == nullptr) {
			return 0;
		}
		if (deep > deepest) {
			deepest = deep;
			sum = node->val;
		}
		else if (deep == deepest) {
			sum += node->val;
		}
		dfs(node->left, deep + 1);
		dfs(node->right, deep + 1);

		return 0;
	}

	int deepestLeavesSum(TreeNode* root) {
		deepest = -1;
		sum = 0;
		dfs(root, 0);
		return sum;
	}
private:
	int deepest = -1;
	int sum = 0;
};
#endif // DFS_METHOD

#ifdef BFS_METHOD
class Solution {
public:

	int deepestLeavesSum(TreeNode* root) {
		
		int sum = 0;

		std::queue<TreeNode*> crtNodes;
		//std::stack<TreeNode*> nextNodes;

		crtNodes.push(root);
		while (true) {
			int n = crtNodes.size();
			bool isAddNewNode = false;
			sum = 0;
			for (int i = 0; i < n; i++) {
				TreeNode *node = crtNodes.front();
				crtNodes.pop();
				sum += node->val;
				if (node->left) {
					crtNodes.push(node->left);
					isAddNewNode = true;
				}
				if (node->right) {
					crtNodes.push(node->right);
					isAddNewNode = true;
				}
			}
			if (isAddNewNode == false) {
				break;
			}
		}

		return sum;
	}

};
#endif // BFS_METHOD




#endif // __leet_code_1302__