/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6316.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 336
 */

#ifndef __leet_code_6316_h__
#define __leet_code_6316_h__

#include<iostream>
#include<queue>
#include<vector>

class Solution {
public:
	int maxScore(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), [=](int a, int b) {
			return a > b;
		});
		long long sum = 0;
		int result = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (sum > 0) {
				result++;
			}
			else {
				break;
			}
		}

		return result;
	}
};


#endif // __leet_code_6316_h__