#ifndef __leet_code_513__
#define __leet_code_513__


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
	int findBottomLeftValue(TreeNode* root) {

		dfs(root, 0);
		return deepest->val;

	}

private:

	TreeNode* deepest = nullptr;
	int maxHeight = -1;

	int dfs(TreeNode *node, int height) {
		if (height > maxHeight) {
			maxHeight = height;
			deepest = node;
		}

		if (node->left != nullptr) {
			dfs(node->left, height + 1);
		}
		if (node->right != nullptr) {
			dfs(node->right, height + 1);
		}

		return 0;
	}

};

#endif // __leet_code_513__