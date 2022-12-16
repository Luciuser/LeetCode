/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-16 09:20:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1785.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-16 09:29:14
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 104ms, 37.59%, MEMORY 71.7MB and 24.82%
 */

#ifndef __leet_code_1785__
#define __leet_code_1785__

#include<iostream>
#include<vector>

class Solution {
public:
	int minElements(std::vector<int>& nums, int limit, int goal) {
		long long sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		long long delta = abs(goal - sum);
		long long result = delta / limit;
		if (delta%limit != 0) {
			result++;
		}
		return result;
	}
};

#endif // __leet_code_1785__