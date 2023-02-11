/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-11 11:13:54
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2335.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-11 11:26:38
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 56.60%, MEMORY 11.5MB and 6.25%
 */

#ifndef __leet_code_2335_h__
#define __leet_code_2335_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int fillCups(std::vector<int>& amount) {
		int a = amount[0];
		int b = amount[1];
		int c = amount[2];

		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (a < c) {
			int temp = a;
			a = c;
			c = temp;
		}
		if (b < c) {
			int temp = b;
			b = c;
			c = temp;
		}

		if (a > b + c) {
			return a;
		}
		else{
			int sum = b - c;
			a -= sum;

			sum += a;
			c -= (a / 2);
			sum += c;

			return sum;
		}

	}
};

#endif // __leet_code_2335_h__