/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-13 15:54:49
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode741.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-14 13:46:16
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 56ms, 39.37%, MEMORY 34.3MB and 20.14%
 */

#ifndef __leet_code_741__
#define __leet_code_741__

#include<iostream>
#include<vector>

class Solution {
public:
    int cherryPickup(std::vector<std::vector<int>>& grid) {

        int n = grid.size();

        // 动态规划，可参见题解
        std::vector<std::vector<std::vector<int>>> dp(2 * n - 1, std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));
        dp[0][0][0] = grid[0][0];

        for (int k = 1; k < 2 * n - 1; k++) {
            int begin = k >= n ? k + 1 - n : 0;
            int end = k <= n - 1 ? k : n - 1;
            for (int x1 = begin; x1 <= end; x1++) {
                for (int x2 = x1; x2 <= end; x2++) {
                    int y1 = k - x1;
                    int y2 = k - x2;

                    if (grid[x1][y1] == -1 || grid[x2][y2] == -1) {
                        dp[k][x1][x2] = -1;
                        continue;
                    }
                    int max = -1;
                    if (x1 <= k - 1 && x2 <= k - 1 && dp[k - 1][x1][x2] != -1) {
                        max = max >= dp[k - 1][x1][x2] ? max : dp[k - 1][x1][x2];
                    }
                    if (x1 > 0 && x2 <= k - 1 && dp[k - 1][x1 - 1][x2] != -1) {
                        max = max >= dp[k - 1][x1 - 1][x2] ? max : dp[k - 1][x1 - 1][x2];
                    }
                    if (x1 <= k - 1 && x2 > 0 && x1 <= x2 - 1 && dp[k - 1][x1][x2 - 1] != -1) {
                        max = max >= dp[k - 1][x1][x2 - 1] ? max : dp[k - 1][x1][x2 - 1];
                    }
                    if (x1 > 0 && x2 > 0 && dp[k - 1][x1 - 1][x2 - 1] != -1) {
                        max = max >= dp[k - 1][x1 - 1][x2 - 1] ? max : dp[k - 1][x1 - 1][x2 - 1];
                    }

                    if (max == -1) {
                        dp[k][x1][x2] = -1;
                        continue;
                    }

                    if (x1 == x2) {
                        dp[k][x1][x2] = max + grid[x1][y1];
                    }
                    else {
                        dp[k][x1][x2] = max + grid[x1][y1] + grid[x2][y2];
                    }
                }
            }
        }
        if (dp[2 * n - 2][n - 1][n - 1] == -1) {
            dp[2 * n - 2][n - 1][n - 1] = 0;
        }
        return dp[2 * n - 2][n - 1][n - 1];
    }
};

#endif // __leet_code_741__