/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-09 14:06:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1806.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-09 14:34:25
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 52.94%
 */

#ifndef __leet_code_1806__
#define __leet_code_1806__

#include<iostream>

class Solution {
public:
	int reinitializePermutation(int n) {
		// 追踪一个数，判断该数是否回去，这里选择追踪数 1
		int result = 1;
		int destination = 1;
		int current = n >= 4 ? 2 : 1;
		while (current != destination) {
			if (current < n / 2) {
				current *= 2;
			}
			else {
				current = (current - n / 2 ) * 2 - 1;
			}
			result++;
		}

		return result;
	}
};

#endif // __leet_code_1806__