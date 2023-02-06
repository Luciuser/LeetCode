/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-03 13:29:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1145.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-03 13:43:02
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 62.61%, MEMORY 10.5MB and 33.91%
 */

#ifndef __leet_code_1145_h__
#define __leet_code_1145_h__

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
	bool btreeGameWinningMove(TreeNode* root, int n, int x) {
		// �� x ���Ǹ��ڵ�ʱ��������ҵ�����ѡ��Ϊ x �ĸ��ڵ������ĳһ���ӽڵ�
		// �� x �Ǹ��ڵ�ʱ��������ҵ�����ѡ��Ϊ x ��ĳһ���ӽڵ�

		// ����Ӹ��ڵ㿪ʼ������ x �ڵ�ǰ�����������Ľڵ���
		wall_number = x;
		int before = dfs(root);
		int left = 0, right = 0;
		if (x_node->left != nullptr) {
			left = dfs(x_node->left);
		}
		if (x_node->right != nullptr) {
			right = dfs(x_node->right);
		}

		if (left > before) {
			int temp = left;
			left = before;
			before = temp;
		}
		if (right > before) {
			int temp = right;
			right = before;
			before = temp;
		}
		if (before > left + right + 1) {
			return true;
		}
		return false;

	}
private:

	int dfs(TreeNode* root) {
		if (root->val == wall_number) {
			x_node = root;
			return 0;
		}
		int sum = 1;
		if (root->left != nullptr) {
			sum += dfs(root->left);
		}
		if (root->right != nullptr) {
			sum += dfs(root->right);
		}
		return sum;
	}

	TreeNode *x_node = nullptr;
	int wall_number = 0;
};

#endif // __leet_code_1145_h__