/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-09
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode856.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-09
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 77.83%
 */

#ifndef __leet_code_856__
#define __leet_code_856__

#include<iostream>
#include<string>

class Solution {
public:
	int scoreOfParentheses(std::string s) {
		int leftNum = 1;
		int sum = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '(') {
				leftNum++;
			}
			else {
				leftNum--;
				if (s[i - 1] == '(') {
					sum += pow(2, leftNum);
				}
			}
		}

		return sum;
	}
};

#endif // __leet_code_856__