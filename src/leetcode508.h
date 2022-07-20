#ifndef __leet_code_508__
#define __leet_code_508__

#include<iostream>
#include<vector>
#include<map>

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
	std::vector<int> findFrequentTreeSum(TreeNode *root) {
		std::vector<int> results;
		
		if (root == nullptr) {
			return results;
		}
		
		int allSum = getTreeSum(root);
		if (numCount.count(allSum) == 0) {
			numCount[allSum] = 1;
		}
		else {
			numCount[allSum]++;
		}

		int max = 0;
		for (auto iter = numCount.begin(); iter != numCount.end(); iter++) {
			if ((*iter).second > max) {
				max = (*iter).second;
				results.clear();
				results.push_back((*iter).first);
			}
			else if ((*iter).second == max) {
				results.push_back((*iter).first);
			}
		}

		return results;
	}
private:

	// 此节点 node 一定不为 nullptr
	int getTreeSum(TreeNode *node) {
		int leftSum = 0, rightSum = 0;
		if (node->left != nullptr) {
			leftSum = getTreeSum(node->left);
			if (numCount.count(leftSum) == 0) {
				numCount[leftSum] = 1;
			}
			else {
				numCount[leftSum]++;
			}
		}
		
		if (node->right != nullptr) {
			rightSum = getTreeSum(node->right);
			if (numCount.count(rightSum) == 0) {
				numCount[rightSum] = 1;
			}
			else {
				numCount[rightSum]++;
			}
		}

		return node->val + leftSum + rightSum;
	}

	std::map<int, int> numCount;
};


#endif // __leet_code_508__