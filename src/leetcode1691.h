/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-10 12:47:11
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1691.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-08 10:51:41
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 8ms, 97.65%, MEMORY 8.8MB and 92.94%
 */

#ifndef __leet_code_1691__
#define __leet_code_1691__

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

class Solution {
public:
    int maxHeight(std::vector<std::vector<int>>& cuboids) {
        // 动态规划，详细推导参见题解
        int n = cuboids.size();
        for (auto& v : cuboids) {
            std::sort(v.begin(), v.end());
        }
        std::sort(cuboids.begin(), cuboids.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
        });
        int ans = 0;
        std::vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[i][0] >= cuboids[j][0] &&
                    cuboids[i][1] >= cuboids[j][1] &&
                    cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = std::max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};

#endif // __leet_code_1691__