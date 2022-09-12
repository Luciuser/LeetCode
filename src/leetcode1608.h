/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 09:49:43
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1608.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-12 10:04:32
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 4ms, 49.77%, MEMORY 8.1MB and 32.03%
 */

#ifndef __leet_code_1608__
#define __leet_code_1608__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int specialArray(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), [=](int a, int b) {return a > b; });
		for (int i = nums.size(); i > 0; i--) {
			if (nums[i - 1] >= i) {
				if (i != nums.size() && nums[i] >= i) {
					continue;
				}
				return i;
			}
		}

		return -1;
	}
};

#endif // __leet_code_1608__