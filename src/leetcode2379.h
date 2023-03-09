/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-09 10:27:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2379.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-09 11:15:56
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 35.66%, MEMORY 6MB and 42.62%
 */

#ifndef __leet_code_2379_h__
#define __leet_code_2379_h__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumRecolors(std::string blocks, int k) {
		// 双指针法
		int left = 0;
		int right = k - 1;

		// 初始化
		int result = 0;
		for (int i = left; i <= right; i++) {
			if (blocks[i] == 'W') {
				result++;
			}
		}

		int min = result;
		for (int i = 1; i + right < blocks.size(); i++) {
			if (blocks[left + i - 1] == 'W') {
				result--;
			}
			if (blocks[right + i] == 'W') {
				result++;
			}
			if (result < min) {
				min = result;
			}
		}

		return min;
	}
};

#endif // __leet_code_2379_h__