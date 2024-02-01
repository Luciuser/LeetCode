/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-30 15:04:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2808.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-30 15:39:32
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 711ms, 11.21%, MEMORY 171.28MB and 17.76%
 */

#ifndef __leet_code_2808__
#define __leet_code_2808__

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
	int minimumSeconds(std::vector<int>& nums) {
		// 本质上是计算两个相同数字之间的最长距离，额外考虑 [0, x] 和 [x, +∞]这段
		// 对于每个数字，可以计算一个最长距离，各最长距离取最短即可

		std::unordered_map<int, int> number_left; // 数字第一次出现时的位置，用于记录最左侧的一段长度
		std::unordered_map<int, int> number_index; // 遍历过程中，数字最后一次出现的位置
		std::unordered_map<int, int> number_seconds; // 两个相同数字之间的最长 seconds
		for (int i = 0; i < nums.size(); i++) {
			if (number_left.find(nums[i]) == number_left.end()) {
				// 该数字第一次出现
				number_left[nums[i]] = i;
				number_index[nums[i]] = i;
				number_seconds[nums[i]] = 0;
			}
			else {
				// 该数字已经出现过
				int before = number_index[nums[i]];
				int temp_second = (i - before) / 2;
				if (temp_second > number_seconds[nums[i]]) {
					number_seconds[nums[i]] = temp_second;
				}
				number_index[nums[i]] = i;
			}
		}

		int min = nums.size();
		for (auto iter = number_left.begin(); iter != number_left.end(); iter++) {
			int number = (*iter).first;
			int right = (*iter).second + nums.size();
			int left = number_index[number];

			int temp_second = (right - left) / 2;
			if (temp_second > number_seconds[number]) {
				number_seconds[number] = temp_second;
			}
			if (number_seconds[number] < min) {
				min = number_seconds[number];
			}
		}

		return min;
	}
};

#endif // __leet_code_2808__