/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-27 10:16:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1144.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-27 10:28:45
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 35.11%, MEMORY 6.9MB and 97.87%
 */

#ifndef __leet_code_1144_h__ 
#define __leet_code_1144_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int movesToMakeZigzag(std::vector<int>& nums) {
		int sum = 0;
		// 先计算第一种情况
		for (int i = 1; i < nums.size(); i += 2) {
			int min = nums[i - 1];
			if (i + 1 < nums.size() && nums[i + 1] < min) {
				min = nums[i + 1];
			}
			if (nums[i] >= min) {
				sum += nums[i] - min + 1;
			}
		}
		int sum2 = 0;
		// 先计算第二种情况
		for (int i = 0; i < nums.size(); i += 2) {
			int min = std::numeric_limits<int>::max();
			if (i - 1 >= 0 && nums[i - 1] < min) {
				min = nums[i - 1];
			}
			if (i + 1 < nums.size() && nums[i + 1] < min) {
				min = nums[i + 1];
			}
			if (nums[i] >= min) {
				sum2 += nums[i] - min + 1;
			}
		}

		return sum < sum2 ? sum : sum2;
	}
};
#endif // __leet_code_1144_h__