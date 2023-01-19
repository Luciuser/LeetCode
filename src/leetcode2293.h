/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-15 09:58:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2293.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-15 10:05:16
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 54.88%, MEMORY 9.5MB and 79.07%
 */

#ifndef __leet_code_2293_h__
#define __leet_code_2293_h__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>

class Solution {
public:
	int minMaxGame(std::vector<int>& nums) {
		int n = nums.size();
		while (n > 1) {
			for (int i = 0; i < n / 2; i++) {
				if (i % 2 == 0) {
					nums[i] = nums[2 * i] < nums[2 * i + 1] ? nums[2 * i] : nums[2 * i + 1];
				}
				else {
					nums[i] = nums[2 * i] > nums[2 * i + 1] ? nums[2 * i] : nums[2 * i + 1];
				}
			}
			n = n / 2;
		}

		return nums[0];
	}
};

#endif // __leet_code_2293_h__