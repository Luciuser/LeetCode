#ifndef __leet_code_1022__
#define __leet_code_1022__

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

	int sumRootToLeaf(TreeNode *node, int temp) {
		if (node == nullptr) {
			return temp;
		}
		else {
			int sum = 0;
			if (node->left == nullptr && node->right == nullptr) {
				sum = temp + node->val;
			}
			else {
				if (node->left != nullptr) {
					sum += sumRootToLeaf(node->left, temp * 2 + node->val);
				}
				if (node->right != nullptr) {
					sum += sumRootToLeaf(node->right, temp * 2 + node->val);
				}
			}

			return sum;
		}
	}

	int sumRootToLeaf(TreeNode* root) {
		int sum = 0;;
		if (root != nullptr) {
			if (root->left == nullptr && root->right == nullptr) {
				sum = root->val;
			}
			else {
				if (root->left != nullptr) {
					sum += sumRootToLeaf(root->left, root->val);
				}
				if (root->right != nullptr) {
					sum += sumRootToLeaf(root->right, root->val);
				}
			}
		}
		return sum;
	}
};

#endif // __leet_code_1022__