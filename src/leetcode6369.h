/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6369.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-19
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, MEMORY 10.7MB
 */

#ifndef __leet_code_6369_h__ 
#define __leet_code_6369_h__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> leftRigthDifference(std::vector<int>& nums) {
		std::vector<int> result(nums.size(), 0);
		int left_sum = 0;
		int right_sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			right_sum += nums[i];
		}

		for (int i = 0; i < nums.size(); i++) {
			right_sum -= nums[i];
			result[i] = abs(left_sum - right_sum);
			left_sum += nums[i];
		}

		return result;
	}
};

#endif // __leet_code_6369_h__