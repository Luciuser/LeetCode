/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-08 11:06:55
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode652.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-10 18:47:22
 * @Editor: Bingyang Jin
 * @Description: create SERIALIZE_HASH_METHOD，TIME 32ms, 75.20%, MEMORY 35.7MB and 84.51%
 */

#ifndef __leet_code_652__
#define __leet_code_652__

#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<tuple>
#include<functional>

//#define SERIALIZE_HASH_METHOD // 序列化哈希表法，TIME 32ms, 75.20%, MEMORY 35.7MB and 84.51%
#define TRIPLE_SERIALIZE_HASH_METHOD // 三元组序列化哈希表法，

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#ifdef SERIALIZE_HASH_METHOD
class Solution {
public:

	// 找到叶节点，对每个节点进行序列化
	std::string dfs(TreeNode* node) {
		if (node == nullptr) {
			return "";
		}

		std::string name = std::to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
		if (nodeMap.count(name) == 0) {
			nodeMap[name] = 0;
		}
		else if (nodeMap[name] == 0) {
			result.push_back(node);
			nodeMap[name] = 1;
		}

		return name;
	}

	std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		result.clear();

		dfs(root);

		return result;
	}

private:
	std::vector<TreeNode* >result;
	std::unordered_map<std::string, int> nodeMap;
};
#endif // SERIALIZE_HASH_METHOD

#ifdef TRIPLE_SERIALIZE_HASH_METHOD

//class Solution {
//public:
//	// 找到叶节点，对每个节点进行序列化
//	std::string dfs(TreeNode* node) {
//		if (node == nullptr) {
//			return "";
//		}
//
//		std::string name = std::to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
//		if (nodeMap.count(name) == 0) {
//			nodeMap[name] = 0;
//		}
//		else if (nodeMap[name] == 0) {
//			result.push_back(node);
//			nodeMap[name] = 1;
//		}
//
//		return name;
//	}
//
//	std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//		result.clear();
//
//		dfs(root);
//
//		return result;
//	}
//
//	size_t tuple_hash(const std::tuple<int, int, int>& t) {
//		
//		int x = std::get<0>(t);
//		return std::hash<int>();
//	}
//
//private:
//
//	static constexpr auto tri_hash = [fn = std::hash<int>()](const std::tuple<int, int, int>& o)->size_t {
//		auto&&[x, y, z] = o;
//		return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
//	};
//
//	std::vector<TreeNode* >result;
//	std::unordered_map<std::tuple<int, int, int>, int> nodeMap;
//	int index; // 给不同节点赋予不同的序号
//};

#endif // TRIPLE_SERIALIZE_HASH_METHOD

#endif // __leet_code_652__