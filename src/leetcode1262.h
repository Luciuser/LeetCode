/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-19 21:01:27
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1622.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-20 08:12:15
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 32ms, 76.58%, MEMORY 24.4MB and 80.74%
 */

#ifndef __leet_code_1622_h__ 
#define __leet_code_1622_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxSumDivThree(std::vector<int>& nums) {
		
		int sum = 0;
		int min_11 = 100000;
		int min_12 = 100000;
		int min_21 = 100000;
		int min_22 = 100000;

		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (nums[i] % 3 == 1) {
				if (nums[i] <= min_11) {
					min_12 = min_11;
					min_11 = nums[i];
				}
				else if (min_11 < nums[i] && nums[i] < min_12) {
					min_12 = nums[i];
				}
			}
			else if (nums[i] % 3 == 2) {
				if (nums[i] <= min_21) {
					min_22 = min_21;
					min_21 = nums[i];
				}
				else if (min_21 < nums[i] && nums[i] < min_22) {
					min_22 = nums[i];
				}
			}
		}

		if (sum % 3 == 1) {
			if (min_11 != 100000) {
				sum -= min_11;
			}
			else {
				sum -= min_21;
				sum -= min_22;
			}
		}
		if (sum % 3 == 2) {
			if (min_21 != 100000) {
				sum -= min_21;
			}
			else {
				sum -= min_11;
				sum -= min_12;
			}
		}

		return sum;
	}
};

#endif // __leet_code_1622_h__