/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-04 16:11:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode287.h
 * @Description: create the file
 */

#ifndef __leet_code_287__
#define __leet_code_287__

 // 题目要求：不能修改输入参数nums，同时空间复杂度为O(1)

#include<iostream>
#include<vector>

//#define VIOLENT_METHOD // 暴力解法，超时

#ifdef VIOLENT_METHOD
class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] == nums[j]) {
					return nums[i];
				}
			}
		}
		return -1;
	}
};
#endif // VIOLENT_METHOD

#endif // __leet_code_287__