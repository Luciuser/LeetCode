/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-18 16:16:01
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode23.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-18 16:37:12
 * @Editor: Bingyang Jin
 * @Description: create POINTER_METHOD, TIME 20ms, 77.40%, MEMORY 12.8MB and 74.81%
 */

#ifndef __leet_code_23_h__ 
#define __leet_code_23_h__

#include<iostream>
#include<vector>
#include<queue>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeCmp {
public:
	bool operator()(const ListNode *a, const ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		
		ListNode* root = nullptr;
		ListNode* father = nullptr;
		std::priority_queue<ListNode*, std::vector<ListNode*>, ListNodeCmp> sort_queue;

		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != nullptr) {
				sort_queue.emplace(lists[i]);
			}
		}

		while (sort_queue.size() > 0) {
			ListNode *current_node = sort_queue.top();
			sort_queue.pop();
			if (current_node->next != nullptr) {
				sort_queue.emplace(current_node->next);
			}
			if (root == nullptr) {
				father = current_node;
				root = current_node;
			}
			else {
				father->next = current_node;
				father = current_node;
			}
		}

		return root;
	}
};

#endif // __leet_code_23_h__