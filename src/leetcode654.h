/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-22 10:53:09
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode654.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-22 11:34:40
 * @Editor: Bingyang Jin
 * @Description: create SORT_RECURSIVE_METHOD, out of TIME
 */

 /*
 * @EditTime: 2022-08-22 13:03:31
 * @Editor: Bingyang Jin
 * @Description: create SORT_RECURSIVE_METHOD_2, TIME 256ms, 5.40%, MEMORY 45.1MB and 27.37%
 */

 /*
 * @EditTime: 2022-08-22 13:03:31
 * @Editor: Bingyang Jin
 * @Description: create RECURSIVE_METHOD, TIME 76ms, 66.51%, MEMORY 41.7MB and 33.55%
 */

#ifndef __leet_code_654__
#define __leet_code_654__

//#define SORT_RECURSIVE_METHOD // ≈≈–Úµ›πÈµ˜”√£¨ª·≥¨ ±
//#define SORT_RECURSIVE_METHOD_2 // ≈≈–Úµ›πÈµ˜”√Œ¨ª§£¨TIME 256ms, 5.40%, MEMORY 45.1MB and 27.37%
#define RECURSIVE_METHOD // µ›πÈππΩ® ˜ 

#include<iostream>
#include<map>
#include<vector>
#include<string>

 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef SORT_RECURSIVE_METHOD
class Solution {
public:

	TreeNode* construct(const int left, const int right, std::map<int, int, std::greater<int>> numsSort, const int index) {

		auto iter = numsSort.begin();
		for (int i = 0; i < index; i++) {
			iter++;
		}
		if (iter == numsSort.end()) {
			return nullptr;
		}
		int val = (*iter).first;
		int middle = (*iter).second;
		TreeNode *node = new TreeNode(val);

		int temp = 0;
		for (iter++; iter != numsSort.end(); iter++) {
			temp++;
			if (left <= (*iter).second && (*iter).second <= middle) {
				node->left = construct(left, middle, numsSort, index + temp);
				break;
			}
		}

		temp = 0;
		iter = numsSort.begin();
		for (int i = 0; i < index; i++) {
			iter++;
		}
		for (iter++; iter != numsSort.end(); iter++) {
			temp++;
			if (middle <= (*iter).second && (*iter).second <= right) {
				node->right = construct(middle, right, numsSort, index + temp);
				break;
			}
		}

		return node;
	}

	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {

		// Ωµ–Ú≈≈–Ú
		std::map<int, int, std::greater<int>> numsSort;
		for (int i = 0; i < nums.size(); i++) {
			numsSort[nums[i]] = i;
		}
		//for (auto iter = numsSort.begin(); iter != numsSort.end(); iter++) {
		//	std::cout << (*iter).first << " " << (*iter).second << std::endl;
		//}

		TreeNode* root = construct(0, nums.size() - 1, numsSort, 0);

		return root;
	}
};
#endif // SORT_RECURSIVE_METHOD

#ifdef SORT_RECURSIVE_METHOD_2
class Solution {
public:

	TreeNode* construct(const int left, const int right) {

		auto iterTemp = iter;
		if (iter == numsSort.end()) {
			return nullptr;
		}
		int val = (*iter).first;
		int middle = (*iter).second;
		TreeNode *node = new TreeNode(val);

		int temp = 0;
		for (iter++; iter != numsSort.end(); iter++) {
			temp++;
			if (left <= (*iter).second && (*iter).second <= middle) {
				node->left = construct(left, middle);
				break;
			}
		}

		temp = 0;
		iter = iterTemp;
		for (iter++; iter != numsSort.end(); iter++) {
			temp++;
			if (middle <= (*iter).second && (*iter).second <= right) {
				node->right = construct(middle, right);
				break;
			}
		}

		return node;
	}

	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {

		// Ωµ–Ú≈≈–Ú
		for (int i = 0; i < nums.size(); i++) {
			numsSort[nums[i]] = i;
		}

		iter = numsSort.begin();
		TreeNode* root = construct(0, nums.size() - 1);

		return root;
	}
private:
	std::map<int, int, std::greater<int>> numsSort;
	std::map<int, int, std::greater<int>>::iterator iter;
};
#endif // SORT_RECURSIVE_METHOD_2

#ifdef RECURSIVE_METHOD
class Solution {
public:

	TreeNode* construct(const int left, const int right) {
		if (left > right){
			return nullptr;
		}

		int middle = left;
		for (int i = left + 1; i <= right; i++) {
			if (number[i] > number[middle]) {
				middle = i;
			}
		}

		TreeNode *node = new TreeNode(number[middle]);
		node->left = construct(left, middle - 1);
		node->right = construct(middle + 1, right);

		return node;
	}

	TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) {

		number = nums;
		return construct(0, number.size() - 1);
	}

private:
	std::vector<int> number;
};
#endif // RECURSIVE_METHOD

#endif // __leet_code_654__