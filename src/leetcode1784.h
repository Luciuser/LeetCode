/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-09
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1784.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-09
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 83.62%
 */

#ifndef __leet_code_1784__
#define __leet_code_1784__

#include<iostream>
#include<string>

class Solution {
public:
	bool checkOnesSegment(std::string s) {
		int sum = 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '1' && s[i - 1] == '0') {
				return false;
			}
		}
		return true;
	}
};

#endif // __leet_code_1784__