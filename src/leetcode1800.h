/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-07 14:09:07
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1800.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-07 14:14:20
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 8.1MB and 70.06%
 */

#ifndef __leet_code_1800__
#define __leet_code_1800__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxAscendingSum(std::vector<int>& nums) {
		int result = nums[0];
		int sum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1]) {
				sum += nums[i];
			}
			else
			{
				if (sum > result) {
					result = sum;
				}
				sum = nums[i];
			}
		}

		if (sum > result) {
			result = sum;
		}

		return result;
	}
};

#endif // __leet_code_1800__