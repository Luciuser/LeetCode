/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-28 00:16:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode813.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-28 13:07:27
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 16ms, 77.25%, MEMORY 7.9MB and 10.48%
 */

#ifndef __leet_code_813__
#define __leet_code_813__

#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<numeric>

class Solution {
public:
    double largestSumOfAverages(std::vector<int>& nums, int k) {
        // 动态规划，可参考题解
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

        std::vector<std::vector<double>> dp(n + 1, std::vector<double>(k + 1, 0));
        // 动态规划初始值
        for (int i = 1; i < n + 1; i++) {
            dp[i][1] = 1.0 * prefix[i] / i;
        }
        // 动态规划
        for (int j = 2; j <= k; j++) {
            for (int i = j; i < n + 1; i++) {
                for (int x = j - 1; x < i; x++) {
                    dp[i][j] = std::max(dp[i][j], dp[x][j - 1] + 1.0 * (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }

        return dp[n][k];
    }
};

#endif // __leet_code_813__