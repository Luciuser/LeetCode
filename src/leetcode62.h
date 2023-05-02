/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-13 20:30:05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode62.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-13 20:44:17
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 65.13%
 */

#ifndef __leet_code_62_h__
#define __leet_code_62_h__

#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 动态规划，设到达点 m, n 时的路径总数为 dp[m][n]，则有：dp[m][n] = dp[m-1][n] + dp[m][n-1]
        // 可用一个数组来代替 dp[m][n]

        std::vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

#endif // __leet_code_62_h__