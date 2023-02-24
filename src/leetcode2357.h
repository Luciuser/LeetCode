/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-24 15:44:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2357.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-24 15:46:52
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 50.86%, MEMORY 8.1MB and 36.29%
 */

#ifndef __leet_code_2357_h__ 
#define __leet_code_2357_h__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
	int minimumOperations(std::vector<int>& nums) {
		std::unordered_set<int> temp;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				temp.emplace(nums[i]);
			}
		}
		
		return temp.size();
	}
};

#endif // __leet_code_2357_h__