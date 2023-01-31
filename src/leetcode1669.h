/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-30 13:54:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1669.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-30 14:10:17
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 268ms, 29.90%, MEMORY 92.1MB and 87.19%
 */

#ifndef __leet_code_1669_h__
#define __leet_code_1669_h__

#include<iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {

private:
	ListNode* findLastNode(ListNode* root) {
		if (root->next == nullptr) {
			return root;
		}
		return findLastNode(root->next);
	}

public:
	ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
		ListNode* list2_end_node = findLastNode(list2);

		ListNode* root = list1;
		bool is_delete = false;
		if (a == 0) {
			root = list2;
			is_delete = true;
		}
		ListNode* father = list1;
		int index = 0;
		while (true) {
			ListNode *current = father->next;
			index++;
			if (current == nullptr) {
				break;
			}
			else if (index == a) {
				if (is_delete == false) {
					is_delete = true;
					father->next = list2;
				}
			}
			if (index == b) {
				if (is_delete == true) {
					is_delete = false;
					list2_end_node->next = current->next;
					break;
				}
			}
			father = current;
		}

		return root;
	}
};

#endif // __leet_code_1669_h__