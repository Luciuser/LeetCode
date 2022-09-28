/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-27 09:11:03
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode662.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-27 10:02:02
 * @Editor: Bingyang Jin
 * @Description: create BFS_METHOD, TIME 28ms, 13.31%, MEMORY 29.3MB and 5.00%
 */

#ifndef __leet_code_662__
#define __leet_code_662__

#include<iostream>
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
	 int widthOfBinaryTree(TreeNode* root) {

		 std::queue<TreeNode *>q;
		 std::queue<int> index;
		 q.emplace(root);
		 index.emplace(0);

		 int result = 0;
		 //int deep = 0; // 当前二叉树的深度
		 while (true) {
			 if (q.size() == 0) {
				 break;
			 }
			 int before = -1; // 当前层最左侧的节点的索引序号
			 int end = -1; // 当前层最右侧的节点的索引序号
			 //int i = 0;
			 std::queue<TreeNode*>temp;
			 std::queue<int> tempIndex;
			 while (true) {
				 if (q.size() == 0) {
					 break;
				 }
				 TreeNode *crtNode = q.front();
				 q.pop();
				 int crtIndex = index.front();
				 index.pop();
				 //if (crtNode->left == nullptr && crtNode->right == nullptr) {
					// //i++;
					// continue;
				 //}
				 if (before == -1) {
					 before = crtIndex;
				 }
				 if (crtIndex > end) {
					 end = crtIndex;
				 }
				 if (crtNode->left != nullptr) {
					 temp.emplace(crtNode->left);
				     tempIndex.emplace(2 * crtIndex - before);
				 }
				 if (crtNode->right != nullptr) {
  				     temp.emplace(crtNode->right);
				     tempIndex.emplace(2 * crtIndex + 1 - before);
				 }

				 //i++;
			 }
			 q = temp;
			 index = tempIndex;
			 //deep++;
			 result = result < end - before + 1 ? end - before + 1 : result;
		  }

		 return result;
	 }
 };

#endif // __leet_code_662__