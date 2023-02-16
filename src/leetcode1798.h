/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-04 14:55:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1145.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 10:59:22
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 104ms, 80.43%, MEMORY 65MB and 38.66%
 */

#ifndef __leet_code_1798_h__
#define __leet_code_1798_h__

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

class Solution {
public:
	int getMaximumConsecutive(std::vector<int>& coins) {

		// 题解贪心法，非常巧妙：
		// 假设已经取出了一部分数，并且能构成 [0, x] 的数组，那么再取出一个 y，则一定可以再构成 [y, x+y] 的数组
		// 若 y<=x+1，则此时一定可以构成 [0, x+y] 的数组
		// 为满足上述条件，每次可以从最小值取起

		std::sort(coins.begin(), coins.end());
		int result = 0;

		for (int i = 0; i < coins.size(); i++) {
			if (coins[i] <= result + 1) {
				result += coins[i];
			}
			else {
				break;
			}
		}

		return result + 1;
	}
};

#endif // __leet_code_1798_h__