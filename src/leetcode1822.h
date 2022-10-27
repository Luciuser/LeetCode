/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-27 10:06:03
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1822.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-27 10:08:55
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 35.83%, MEMORY 9.9MB and 35.37%
 */

#ifndef __leet_code_1822__
#define __leet_code_1822__

#include<iostream>
#include<vector>

class Solution {
public:
	int arraySign(std::vector<int>& nums) {
		int result = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				return 0;
			}
			else if (nums[i] < 0) {
				result *= -1;
			}
		}
		return result;
	}
};

#endif // __leet_code_1822__