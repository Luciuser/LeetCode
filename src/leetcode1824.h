/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-21 10:26:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1824.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-21 11:50:07
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 748ms, 11.52%, MEMORY 313.1MB and 10.99%
 */

#ifndef __leet_code_1824_h__
#define __leet_code_1824_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int minSideJumps(std::vector<int>& obstacles) {
		// 动态规划：令 dp[i][j] 表示到达 i 点 j+1 跑道时，最少的侧跳次数
		// 初始情况下，有：dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 1
		// 若第 i 个点的第 j 条跑道有障碍物，则 dp[i][j] = MAX // -1 表示不存在
		// 若第 i - 1 个点的第 j 条跑道不存在障碍物，则 dp[i][j] 可以由 dp[i-1][j] 转移而来
		// 若第 i 个点的第 j 条跑道和第 k 条跑道无障碍物，则 dp[i][j] 可以由 dp[i][k] 转移而来

		std::vector<std::vector<int>> dp(obstacles.size(), std::vector<int>(3, std::numeric_limits<int>::max()));
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[0][2] = 1;

		for (int i = 1; i < obstacles.size(); i++) {
			for (int j = 0; j < 3; j++) {
				if (obstacles[i] == j + 1) {
					continue;
				}
				
				// 从 i - 1 向 i 进行状态转移
				if (obstacles[i - 1] != j + 1) {
					dp[i][j] = dp[i - 1][j];
				}
			}
			// 进行侧跳转移
			for (int j = 0; j < 3; j++) {
				int min_step = dp[i][j];
				for (int k = 0; k < 3; k++) {
					if (j == k || dp[i][k] == std::numeric_limits<int>::max()) {
						continue;
					}
					min_step = min_step < dp[i][k] + 1 ? min_step : dp[i][k] + 1;
				}
				dp[i][j] = min_step;
			}
		}

		int n = obstacles.size();
		int result = dp[n - 1][0] < dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
		result = result < dp[n - 1][2] ? result : dp[n - 1][2];

		return result;
	}
};

#endif // __leet_code_1824_h__