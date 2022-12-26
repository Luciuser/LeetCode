/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-22 12:06:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1799.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-21 00:36:46
 * @Editor: Bingyang Jin
 * @Description: create ANSWER_METHOD, TIME 16ms, 30.39%, MEMORY 5.7MB and 99.02%
 */

#ifndef __leet_code_1799__
#define __leet_code_1799__

#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>

class Solution {
public:

	int maxScore(std::vector<int>& nums) {
		int m = nums.size();
		std::vector<int> dp(1 << m, 0);
		std::vector<std::vector<int>> gcd_tmp(m, std::vector<int>(m, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				// 计算最大公约数
				// gcd_tmp[i][j] = std::gcd(nums[i], nums[j]);
			}
		}
		int all = 1 << m;
		for (int s = 1; s < all; ++s) {
			// 计算t里有多少个1
			//int t = __builtin_popcount(s);
			int t = 0;
			if (t & 1) {
				continue;
			}
			for (int i = 0; i < m; ++i) {
				if ((s >> i) & 1) {
					for (int j = i + 1; j < m; ++j) {
						if ((s >> j) & 1) {
							dp[s] = std::max(dp[s], dp[s ^ (1 << i) ^ (1 << j)] + t / 2 * gcd_tmp[i][j]);
						}
					}
				}
			}
		}
		return dp[all - 1];
	}
private:
};

#endif // __leet_code_1799__