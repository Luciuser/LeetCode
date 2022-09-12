/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 16:38:32
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1470.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-12 16:40:16
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 4ms, 85.48%, MEMORY 9.7MB and 5.52%
 */

#ifndef __leet_code_1470__
#define __leet_code_1470__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	std::vector<int> shuffle(std::vector<int>& nums, int n) {
		std::vector<int> result;
		for (int i = 0; i < n; i++) {
			result.push_back(nums[i]);
			result.push_back(nums[n + i]);
		}
		return result;
	}
};

#endif // __leet_code_1470__