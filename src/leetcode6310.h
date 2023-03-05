/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6310.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 335
 */

#ifndef __leet_code_6310_h__
#define __leet_code_6310_h__

#include<iostream>
#include<queue>
#include<vector>

class Solution {
public:
	int waysToReachTarget(int target, std::vector<std::vector<int>>& types) {
		// 多重背包动态规划
		int n = types.size();
		int mod = 1e9 + 7;

		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(target + 1, 0));
		dp[0][0] = 1;

		for (int i = 1; i <= n; i++) {
			int count = types[i - 1][0];
			int mark = types[i - 1][1];
			for (int j = 0; j <= target; j++) {
				dp[i][j] = dp[i - 1][j];
				for (int k = 1; k <= count; k++) {
					if (k*mark <= j) {
						dp[i][j] = (dp[i][j] + dp[i - 1][j - k * mark]) % mod;
					}
					else {
						break;
					}
				}
			}
		}
		
		return dp[n][target];
	}
};

#endif // __leet_code_6310_h__