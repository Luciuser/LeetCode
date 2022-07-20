#ifndef __leet_code_450__
#define __leet_code_450__

#include<iostream>
#include<assert.h>

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

	TreeNode* findNode(TreeNode* root, int key, TreeNode **father) {
		if (root == nullptr) { return nullptr; }

		TreeNode* temp = root;
		*father = nullptr;
		while (temp->val != key) {
			if (temp->val < key) {
				*father = temp;
				temp = temp->right;
			}
			if (temp->val > key) {
				*father = temp;
				temp = temp->left;
			}
			if (temp == nullptr) {
				return nullptr;
			}
			//if (temp->left == nullptr && temp->val > key) {
			//	return nullptr;
			//}
			//if (temp->right == nullptr && temp->val < key) {
			//	return nullptr;
			//}
		}

		return temp;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		
		// 寻找节点
		TreeNode* father = nullptr; // 找到节点的父节点
		TreeNode* crtNode = findNode(root, key, &father);
		if (crtNode == nullptr) { return root; }

		// 删除节点

		//若为叶节点，则直接删除
		if (crtNode->left == nullptr && crtNode->right == nullptr) {
			if (father == nullptr) {
				return nullptr;
			}
			else {
				if (father->left == crtNode) {
					father->left = nullptr;
					return root;
				}
				else if (father->right == crtNode) {
					father->right = nullptr;
					return root;
				}
				else {
					assert(false);
				}
			}
		}

		// 若不为叶节点，则需要找到左子树的最大值或右子树的最小值
		// 找左子树的最大值
		if (crtNode->left != nullptr) {
			TreeNode* temp = crtNode->left;
			TreeNode* tempFather = crtNode;
			while (temp->right != nullptr) {
				tempFather = temp;
				temp = temp->right;
			}

			if (temp == crtNode->left) {
				temp->right = crtNode->right;
			}
			else {
				if (temp->left == nullptr) {
					tempFather->right = nullptr;
					temp->left = crtNode->left;
					temp->right = crtNode->right;
				}
				else {
					tempFather->right = deleteNode(temp, temp->val);
					temp->left = crtNode->left;
					temp->right = crtNode->right;
				}
			}

			if (father != nullptr) {
				if (father->left == crtNode) {
					father->left = temp;
					return root;
				}
				else if (father->right == crtNode) {
					father->right = temp;
					return root;
				}
				else {
					assert(false);
				}
			}
			else {
				return temp;
			}
		}

		// 找右子树的最小值
		if (crtNode->right != nullptr) {
			TreeNode* temp = crtNode->right;
			TreeNode* tempFather = crtNode;
			while (temp->left != nullptr) {
				tempFather = temp;
				temp = temp->left;
			}

			if (temp == crtNode->right) {
				temp->left = crtNode->left;
			}
			else {
				if (temp->right == nullptr) {
					tempFather->left = nullptr;
					temp->left = crtNode->left;
					temp->right = crtNode->right;
				}
				else {
					tempFather->left = deleteNode(temp, temp->val);
					temp->left = crtNode->left;
					temp->right = crtNode->right;
				}
			}

			if (father != nullptr) {
				if (father->left == crtNode) {
					father->left = temp;
					return root;
				}
				else if (father->right == crtNode) {
					father->right = temp;
					return root;
				}
				else {
					assert(false);
				}
			}
			else {
				return temp;
			}
		}

		return root;
	}
};

#endif // __leet_code_450__