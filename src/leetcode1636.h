/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-19 10:15:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1636.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-18 10:25:30
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 12ms, 38.19%, MEMORY 10.8MB and 27.08%
 */

#ifndef __leet_code_1636__
#define __leet_code_1636__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	std::vector<int> frequencySort(std::vector<int>& nums) {
		std::unordered_map<int, int> numberTimes;
		for (int i = 0; i < nums.size(); i++) {
			if (numberTimes.count(nums[i]) == 0) {
				numberTimes[nums[i]] = 1;
			}
			else {
				numberTimes[nums[i]]++;
			}
		}

		std::sort(nums.begin(), nums.end(), [=](int a, int b) {
			if (numberTimes[a] == numberTimes[b]) {
				return a > b;
			}
			else {
				return numberTimes[a] < numberTimes[b];
			}
		});

		return nums;
	}
};

#endif // __leet_code_1636__