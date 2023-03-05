/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6308.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 335
 */

#ifndef __leet_code_6308_h__
#define __leet_code_6308_h__

#include<iostream>

#include<map>
#include<queue>
#include<vector>

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
	long long kthLargestLevelSum(TreeNode* root, int k) {
		std::queue<TreeNode *> q;
		q.emplace(root);

		std::map<long long, int, std::greater<long long>> result;

		while (true) {
			int n = q.size();
			if (n == 0) {
				break;
			}
			long long sum = 0;
			for (int i = 0; i < n; i++) {
				TreeNode *top = q.front();
				q.pop();
				sum += top->val;
				if (top->left != nullptr) {
					q.emplace(top->left);
				}
				if (top->right != nullptr) {
					q.emplace(top->right);
				}
			}
			result[sum]++;
		}

		auto iter = result.begin();
		while (true) {
			if (iter == result.end()) {
				break;
			}
			k -= (*iter).second;
			if (k <= 0) {
				return (*iter).first;
			}
			iter++;
		}

		return -1;
	}
};

#endif // __leet_code_6308_h__