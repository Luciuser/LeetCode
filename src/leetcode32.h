/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-31 14:28:11
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode32.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-31 14:51:59
 * @Editor: Bingyang Jin
 * @Description: create STACK_METHOD, TIME 4ms, 76.68%, MEMORY 7.8MB and 5.05%
 */

#ifndef __leet_code_32_h__
#define __leet_code_32_h__

#include<iostream>
#include<stack>
#include<string>
#include<vector>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        
        std::stack<int> left;
        std::vector<int> success(s.size(), 0);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left.emplace(i);
            }
            else {
                if (left.size() > 0) {
                    int top = left.top();
                    left.pop();
                    success[top] = 1;
                    success[i] = 1;
                }
            }
        }

        int max = 0;
        int sum = 0;
        for (int i = 0; i < success.size(); i++) {
            if (success[i] == 0) {
                max = sum > max ? sum : max;
                sum = 0;
            }
            else {
                sum++;
            }
        }
        max = sum > max ? sum : max;

        return max;
    }
};

#endif //__leet_code_32_h__