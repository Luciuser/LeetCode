/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-15 13:21:34
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode82.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-15 13:39:24
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 8ms, 59.56%, MEMORY 11.17MB and 68.72%
 */

#ifndef __leet_code_82__
#define __leet_code_82__


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
        ListNode* before = new ListNode(0, head);
        ListNode* root = before;
        ListNode* current = head;
        if (current == nullptr) {
            return current;
        }
        ListNode* next = head->next;

        bool b_delete = false;
        while (true) {
            if (next == nullptr) {
                break;
            }
            if (current->val == next->val) {
                b_delete = true;
                next = next->next;
            }
            else {
                if (b_delete == true) {
                    current = next;
                    next = next->next;
                    b_delete = false;
                }
                else {
                    before->next = current;
                    before = current;
                    current = next;
                    next = next->next;
                }
            }

        }
        if (b_delete) {
            before->next = nullptr;
        }
        else {
            before->next = current;
            current->next = nullptr;
        }

        return root->next;
    }
};

#endif // __leet_code_82__