/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-06 11:27:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2180.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-06 11:56:25
 * @Editor: Bingyang Jin
 * @Description: create HALF_MATH_METHOD, TIME 4ms, 27.232%, MEMORY 5.8MB and 67.32%
 */

#ifndef __leet_code_2180__
#define __leet_code_2180__

#include<iostream>
#include<vector>

class Solution {
public:
	int countEven(int num) {
		
		int ten = num / 10;
		int sum = ten * 5;
		if (sum != 0) {
			sum--;
		}
		int one = num % 10;
		// sum += one / 2;

		int temp = 0;
		while (num >= 10) {
			temp += num % 10;
			num /= 10;
		}
		temp += num;
		temp -= one;

		int i = 0;
		if (temp == 0) {
			i = 1;
		}
		for (; i <= one; i++) {
			if ((temp + i) % 2 == 0) {
				sum++;
			}
		}


		return sum;
	}
};

#endif // __leet_code_2180__