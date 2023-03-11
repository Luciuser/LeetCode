/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-10 15:35:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1590.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-09 11:15:56
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 35.66%, MEMORY 6MB and 42.62%
 */

#ifndef __leet_code_1590_h__
#define __leet_code_1590_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int minSubarray(std::vector<int>& nums, int p) {

		long long target = 0;
		std::vector<long long> prefix(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			target += nums[i] % p;
			if (target >= p) {
				target = target % p;
			}

			prefix[i + 1] =  target;
		}
		if (target == 0) {
			return 0;
		}

		int min = nums.size();
		for (int right = 1; right < prefix.size(); right++) {
			for (int i = 1; i < min && right - i >= 0; i++) {
				int left = right - i;
				long long sum = prefix[right] - prefix[left];
				if (sum < 0) {
					sum += p;
				}
				if (sum == target) {
					min = i;
					break;
				}
			}
		}

		if (min == nums.size()) {
			return -1;
		}
		return min;
	}
};

#endif // __leet_code_1590_h__