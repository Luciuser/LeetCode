#ifndef __leet_code_965__
#define __leet_code_965__


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
	bool isUnivalTree(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) {
			return true;
		}

		if (root->right == nullptr) {
			if (root->left->val != root->val) {
				return false;
			}
			return isUnivalTree(root->left);
		}

		if (root->left == nullptr) {
			if (root->right->val != root->val) {
				return false;
			}
			return isUnivalTree(root->right);
		}

		if ((root->left->val != root->right->val) ||
			(root->val != root->left->val) ||
			(root->val != root->right->val)) {
			return false;
		}

		return isUnivalTree(root->left) && isUnivalTree(root->right);
	}
};


#endif // __leet_code_965__