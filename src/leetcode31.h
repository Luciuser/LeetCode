/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-18 16:41:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode31.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-18 16:37:12
 * @Editor: Bingyang Jin
 * @Description: create POINTER_METHOD, TIME 20ms, 77.40%, MEMORY 12.8MB and 74.81%
 */

#ifndef __leet_code_31_h__ 
#define __leet_code_31_h__

#include<iostream>
#include<stack>
#include<vector>

class Solution {
public:
	void nextPermutation(std::vector<int>& nums) {
		if (nums.size() == 1) {
			return;
		}

		bool is_max = true; // 判断是否当前数为最大数
		int before = nums[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; i++) {

		}

	}

};

#endif // __leet_code_31_h__