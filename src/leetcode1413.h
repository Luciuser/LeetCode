/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-09 13:43:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1413.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-09 13:47:52
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME WRONG(0ms, 100.00%), MEMORY 7.1 MB and 90.51%
 */

#ifndef __leet_code_1413__
#define __leet_code_1413__

#include<iostream>
#include<vector>

class Solution {
public:
	int minStartValue(std::vector<int>& nums) {
		int min = std::numeric_limits<int>::max();
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum < min) {
				min = sum;
			}
		}

		return min >= 1 ? 1 : 1 - min;

	}
};

#endif // __leet_code_1413__