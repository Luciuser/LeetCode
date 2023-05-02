/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-10 11:05:21
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1019.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-10 11:17:52
 * @Editor: Bingyang Jin
 * @Description: create STACK_METHOD, TIME 112ms, 23.18%, MEMORY 41.6MB and 42.92%
 */

#ifndef __leet_code_1019_h__
#define __leet_code_1019_h__

#include<iostream>
#include<vector>
#include<stack>

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
    std::vector<int> nextLargerNodes(ListNode* head) {
        std::vector<int> result;
        std::stack<std::pair<int, int>> position_value_stack;

        ListNode* temp = head;
        int i = 0;
        while (temp != nullptr) {
            if (position_value_stack.size() == 0) {
                result.emplace_back(0);
                position_value_stack.emplace(std::pair<int, int>(i, temp->val));
            }
            else {
                while (true) {
                    if (position_value_stack.size() == 0) {
                        // 装入堆栈
                        result.emplace_back(0);
                        position_value_stack.emplace(std::pair<int, int>(i, temp->val));
                        break;
                    }
                    auto top_pair = position_value_stack.top();
                    if (top_pair.second >= temp->val) {
                        // 装入堆栈
                        result.emplace_back(0);
                        position_value_stack.emplace(std::pair<int, int>(i, temp->val));
                        break;
                    }
                    else {
                        result[top_pair.first] = temp->val;
                        position_value_stack.pop();
                    }
                }
            }
            temp = temp->next;
            i++;
        }

        return result;
    }
};

#endif // __leet_code_1019_h__