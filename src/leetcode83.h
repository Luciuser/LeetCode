/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-14 10:45:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode83.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-14 10:49:31
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 12ms, 30.08%, MEMORY 11.6MB and 82.9%
 */

#ifndef __leet_code_83__
#define __leet_code_83__

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
	ListNode* deleteDuplicates(ListNode* head) {

		ListNode* current = head;
		if (current == nullptr) {
			return nullptr;
		}
		ListNode* next = current->next;
		while (true) {
			if (next == nullptr) {
				current->next = nullptr;
				break;
			}
			if (current->val == next->val) {
				next = next->next;
			}
			else {
				current->next = next;
				current = next;
				next = next->next;
			}
		}

		return head;
	}
};

#endif // __leet_code_83__