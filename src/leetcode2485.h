/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-26 08:45:41
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2485.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-26 08:52:37
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 0ms, 100.00%, MEMO5.8MB and 63.47%
 */

#ifndef __leet_code_2485_h__
#define __leet_code_2485_h__

#include<iostream>

class Solution {
public:
	int pivotInteger(int n) {
		// 根据公式，计算 (1+n)*n/2
		int sum = (1 + n)*n / 2;
		for (int i = 1; i <= sqrt(sum); i++) {
			if (i*i == sum) {
				return i;
			}
		}

		return -1;

	}
};

#endif // __leet_code_2485_h__