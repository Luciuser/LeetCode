/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-16 10:11:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2341.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 10:16:38
 * @Editor: Bingyang Jin
 * @Description: create UNORDERED_MAP_METHOD, TIME 8ms, 16.73%, MEMORY 8.9MB and 59.70%
 */

#ifndef __leet_code_2341_h__ 
#define __leet_code_2341_h__

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
	std::vector<int> numberOfPairs(std::vector<int>& nums) {
		std::unordered_map<int, int>frequence;
		std::vector<int>result(2, 0);
		result[1] = nums.size();
		for (int i = 0; i < nums.size(); i++) {
			frequence[nums[i]]++;
			if (frequence[nums[i]] == 2) {
				result[0]++;
				result[1] -= 2;
				frequence[nums[i]] = 0;
			}
		}

		return result;
	}
};

#endif // __leet_code_2341_h__