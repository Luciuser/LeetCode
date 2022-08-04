/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-04 14:22:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1403.h
 * @Description: create the file and greedy method, TIME 8 ms, MEMORY 10.3 MB
 */

#ifndef __leet_code_1403__
#define __leet_code_1403__

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

class Solution {
public:
	std::vector<int> minSubsequence(std::vector<int>& nums) {
		
		int sumRemain = std::accumulate(nums.begin(), nums.end(), 0);
		std::sort(nums.begin(), nums.end(), [=](int a, int b) {return a > b; });

		std::vector<int> result;
		int sumGain = 0;

		int index = 0;
		while (true) {
			result.push_back(nums[index]);
			sumGain += nums[index];
			sumRemain -= nums[index];
			index++;

			if (sumGain > sumRemain) {
				break;
			}
		}

		return result;
	}
};

#endif // 