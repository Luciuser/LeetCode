/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-28 10:50:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1663.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-28 11:06:57
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 32ms, 44.49%, MEMORY 28.1MB and 8.07%
 */

#ifndef __leet_code_1663_h__
#define __leet_code_1663_h__

#include<iostream>
#include<string>

class Solution {
public:
	std::string getSmallestString(int n, int k) {
		int a, b, c; // a 的数量，一个字符的数值 b，z 的数量

		c = (k - n) / 25;
		b = (k - n) % 25;
		a = n - c - 1;
		if (b == 0) {
			a++;
		}

		std::string result = "";
		result += std::string(a, 'a');
		if (b != 0) {
			result += std::string(1, 'a' + b);
		}
		result += std::string(c, 'z');

		return result;
	}
};

#endif // __leet_code_1663_h__