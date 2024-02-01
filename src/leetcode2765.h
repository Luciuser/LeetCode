/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-23 10:39:01
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2765.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-23 15:11:05
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 31ms, 17.33%, MEMORY 67.58MB and 5.45%
 */

#ifndef __leet_code_2765__
#define __leet_code_2765__

#include<iostream>
#include<vector>

class Solution {
public:
	int alternatingSubarray(std::vector<int>& nums) {

		int min = -1;

		int temp = 0;
		bool find = false;
		int ratio = -1;
		for (int i = 0; i+1 < nums.size(); i++) {
			if (find) {
				if (nums[i + 1] - nums[i] == ratio) {
					temp++;
					ratio = -ratio;
				}
				else if (nums[i + 1] - nums[i] == 1) {
					if (temp > min) {
						min = temp;
					}
					temp = 2;
				}
				else {
					if (temp > min) {
						min = temp;
					}
					find = false;
					temp = 0;
					ratio = -1;
				}
			}
			else if (nums[i + 1] - nums[i] == 1) {
				find = true;
				temp = 2;
			}
		}
		if (temp > min) {
			min = temp;
		}

		return min;
	}
};

#endif // __leet_code_2765__