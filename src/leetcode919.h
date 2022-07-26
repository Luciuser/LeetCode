/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-25 09:09:49
 * @FilePath: /src/leetcode919.h
  * @Description: create the file and the solution
 */

#ifndef __leet_code_919__
#define __leet_code_919__

#include<iostream>
#include<vector>
#include<queue>
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

class CBTInserter {
public:
	CBTInserter(TreeNode* root) {
		treeRoot = root;

		deepestNode = treeRoot;
		deepMax = 1;
		while (true) {
			if (deepestNode->left == nullptr) {
				break;
			}
			deepestNode = deepestNode->left;
			deepMax++;
		}

		//nextNodes.push(deepestNode);
		findNodeEmpty(treeRoot, 1);
		if (crtNodes.size() == 0) {
			crtNodes = nextNodes;;
			while (nextNodes.empty() == false) {
				nextNodes.pop();
			}
		}
	}

	int insert(int val) {
		TreeNode* result = crtNodes.front();

		TreeNode* newNode = new TreeNode(val);
		nextNodes.push(newNode);
		
		if (result->left == nullptr) {
			result->left = newNode;
		}
		else if (result->right == nullptr) {
			result->right = newNode;
			crtNodes.pop();
		}
		else {
			assert(false);
		}

		if (crtNodes.size() == 0) {
			crtNodes = nextNodes;;
			while (nextNodes.empty() == false) {
				nextNodes.pop();
			}
		}
		return result->val;
	}

	TreeNode* get_root() {
		return treeRoot;
	}

private:

	int findNodeEmpty(TreeNode* node, int deep) {

		if (node->left == nullptr || node->right == nullptr) {
			if (deep == deepMax) {
				nextNodes.push(node);
			}
			else if (deep == deepMax - 1) {
				crtNodes.push(node);
			}
			else {
				assert(false);
			}
			if (node->left != nullptr) {
				findNodeEmpty(node->left, deep + 1);
			}
		}
		else {
			findNodeEmpty(node->left, deep + 1);
			findNodeEmpty(node->right, deep + 1);
		}

		return 0;
	}

	TreeNode *treeRoot;
	
	TreeNode *deepestNode;
	int deepMax;

	std::queue<TreeNode *> crtNodes;
	std::queue<TreeNode *> nextNodes;

};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

#endif // __leet_code_919__