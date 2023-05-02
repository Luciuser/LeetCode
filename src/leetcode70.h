/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-16 21:59:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode70.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-16 22:03:52
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 24.66%, MEMORY 6.1MB and 17.99%
 */

#ifndef __leet_code_70_h__
#define __leet_code_70_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 1);
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

#endif // __leet_code_70_h__