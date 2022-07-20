#ifndef __leet_code_2__
#define __leet_code_2__

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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *root = new ListNode();
		ListNode *crtNode = root;

		int add = 0;
		ListNode *crtL1 = l1;
		ListNode *crtL2 = l2;


		while (true) {
			int val = crtL1->val + crtL2->val + add;
			add = val / 10;
			crtNode->val = val % 10;
			if (crtL1->next == nullptr && crtL2->next == nullptr) {
				if (add == 0) {
					break;
				}
				else {
					ListNode *newNode = new ListNode(1);
					crtNode->next = newNode;
					break;
				}
			}
			if (crtL1->next == nullptr) {
				ListNode *l1next = new ListNode(0);
				crtL1 = l1next;
			}
			else {
				crtL1 = crtL1->next;
			}
			if (crtL2->next == nullptr) {
				ListNode *l2next = new ListNode(0);
				crtL2 = l2next;
			}
			else {
				crtL2 = crtL2->next;
			}
			
			ListNode *newNode = new ListNode();
			crtNode->next = newNode;
			crtNode = newNode;
		}

		return root;
	}
};

#endif // __leet_code_2__