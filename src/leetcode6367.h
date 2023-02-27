/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6367.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-26
 * @Editor: Bingyang Jin
 * @Description: create SORT_METHOD, TIME 132ms, MEMORY 58.6MB
 */

#ifndef __leet_code_6367_h__ 
#define __leet_code_6367_h__

#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
	int maxNumOfMarkedIndices(std::vector<int>& nums) {

		std::sort(nums.begin(), nums.end());
		int n = nums.size();

		int sum = 0;
		int i = n / 2 - 1;
		int j = n - 1;
		while (i >= 0) {
			if (2 * nums[i] <= nums[j]) {
				sum += 2;
				j--;
			}
			i--;
		}

		return sum;
	}
};
#endif // __leet_code_6368_h__