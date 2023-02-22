/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-21 09:54:17
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1326.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-21 13:21:37
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 24ms, 48.10%, MEMORY 17.2MB and 16.46%
 */

#ifndef __leet_code_1326_h__ 
#define __leet_code_1326_h__

#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
	int minTaps(int n, std::vector<int>& ranges) {
		// 贪心法，先排序，然后每次尝试去找 end 最大的一个
		
		// 按照 left-->right，将所有的区间放入 map 中
		std::map<int, int>left_right;
		for (int i = 0; i < ranges.size(); i++) {
			if (ranges[i] == 0) {
				continue;
			}
			int left = i - ranges[i];
			int right = i + ranges[i];
			if (left < 0) {
				left = 0;
			}
			if (left_right.count(left) == 0) {
				left_right[left] = right;
			}
			else {
				if (right > left_right[left]) {
					left_right[left] = right;
				}
			}
		}

		if (left_right.size() == 0) {
			return -1;
		}

		// 贪心法
		int sum = 0;
		int current_right = 0;
		int max_right = -1;
		for (auto iter = left_right.begin(); iter != left_right.end(); iter++) {
			if ((*iter).first <= current_right) {
				if ((*iter).second > max_right) {
					max_right = (*iter).second;
				}
			}
			else {
				// 左边界在当前已选区域内的所有区间已经遍历完了，进行比较
				if (max_right == -1) {
					return -1;
				}
				sum++;
				current_right = max_right;
				max_right = -1;
				iter--;
				if (current_right >= n) {
					break;
				}
			}
		}
		if (current_right < n) {
			if (max_right >= n) {
				sum++;
			}
			else {
				return -1;
			}
		}

		return sum;
	}
};

#endif __leet_code_1326_h__