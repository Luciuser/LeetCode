/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-08
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6283.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 327
 */

#ifndef __leet_code_6283_h__
#define __leet_code_6283_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int maximumCount(std::vector<int>& nums) {
		int a = 0, b = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] < 0) {
				a++;
			}
			else if (nums[i] > 0) {
				b++;
			}
		}

		return a > b ? a : b;
	}
};

#endif // __leet_code_6283_h__