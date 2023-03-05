/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6309.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 335
 */

#ifndef __leet_code_6309_h__
#define __leet_code_6309_h__

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
	int findValidSplit(std::vector<int>& nums) {
		int result = 0;
		std::unordered_map<int, int> factor;

		for (int i = 0; i < nums.size(); i++) {
			int n = nums[i];
			for (int j = 2; j <= sqrt(n); j++) {
				if (n%j == 0) {
					if (factor.count(j) == 0) {
						factor[j] = i;
					}
					else {
						if (factor[j] <= result) {
							result = i;
						}
					}
					int other = n / j;
					if (factor.count(other) == 0) {
						factor[other] = i;
					}
					else {
						if (factor[other] <= result) {
							result = i;
						}
					}
				}
			}
			if (factor.count(n) == 0) {
				factor[n] = i;
			}
			else {
				if (factor[n] <= result) {
					result = i;
				}
			}
		}
		if (result == nums.size() - 1) {
			return -1;
		}
		else {
			return result;
		}
	}
};

#endif // __leet_code_6309_h__