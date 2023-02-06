/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-04 14:55:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1145.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-03 13:43:02
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 62.61%, MEMORY 10.5MB and 33.91%
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
		int result = 1;
		std::sort(coins.begin(), coins.end());
		//int max = std::accumulate(coins.begin(), coins.end(), 0);

		std::vector<int> is_use(coins.size(), 0);
		while (true) {
			
		}

		return result;
	}
};

#endif // __leet_code_1798_h__