/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-26 00:44:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1464.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-26 00:48:05
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 680ms, 9.02%, MEMORY 420.9MB and 5.16%
 */

#ifndef __leet_code_1464__
#define __leet_code_1464__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxProduct(std::vector<int>& nums) {
		int max1 = 0;
		int max2 = 1;
		if (nums[max1] < nums[max2]) {
			int temp = max1;
			max1 = max2;
			max2 = temp;
		}
		for (int i = 2; i < nums.size(); i++) {
			if (nums[max2] < nums[i] && nums[i] <= nums[max1]) {
				max2 = i;
			}
			else if (nums[max1] < nums[i]) {
				max2 = max1;
				max1 = i;
			}
		}

		return (nums[max1] - 1)*(nums[max2] - 1);
	}
};

#endif // __leet_code_1464__