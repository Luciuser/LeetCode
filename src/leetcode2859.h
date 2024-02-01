/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-25 10:06:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2859.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-25 10:14:41
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 10ms, 63.27%, MEMORY 23.81MB and 5.09%
 */

#ifndef __leet_code_2859__
#define __leet_code_2859__

#include<iostream>
#include<vector>

class Solution {
public:
	int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
		int sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			int t = i;
			int one_number = 0;
			while (t >= 2) {
				if (t % 2 == 1) {
					one_number++;
					if (one_number > k) {
						break;
					}
				}
				t /= 2;

			}
			if (t != 0) {
				one_number += 1;
			}
			// std::cout << i << " " << one_number << std::endl;
			if (one_number == k) {
				sum += nums[i];
			}
		}

		return sum;
	}
};
#endif // __leet_code_2859__