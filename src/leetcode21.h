/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-20 10:35:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode21.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-20 10:39:44
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 92.24%, MEMORY 22.2MB and 5.05%
 */

#ifndef __leet_code_21__
#define __leet_code_21__

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
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

		if (list1 == nullptr) {
			return list2;
		}
		if (list2 == nullptr) {
			return list1;
		}

		ListNode *root = new ListNode();
		if (list1->val < list2->val) {
			root->val = list1->val;
			root->next = mergeTwoLists(list1->next, list2);
		}
		else {
			root->val = list2->val;
			root->next = mergeTwoLists(list1, list2->next);
		}

		return root;
	}
};

#endif // __leet_code_21__