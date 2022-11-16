/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-15 10:51:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode790.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-16 10:52:18
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 57.84%, MEMORY 7.4MB and 20.86%
 */

#ifndef __leet_code_790__
#define __leet_code_790__

#include<iostream>
#include<vector>

class Solution {
public:
    int numTilings(int n) {
        // 动态规划可参考题解
        int MOD = 1e9 + 7;
        std::vector<std::vector<long>> dp(n, std::vector<long>(4));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 1;

        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][3]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }

        return dp[n - 1][3];
    }
};

#endif // __leet_code_790__