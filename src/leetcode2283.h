/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-11 10:01:01
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2283.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-11 10:06:09
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.1MB and 9.65%
 */

#ifndef __leet_code_2283_h__
#define __leet_code_2283_h__

#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
	bool digitCount(std::string num) {
		std::unordered_map<char, int> character;
		for (int i = 0; i < num.size(); i++) {
			character[num[i]]++;
		}
		for (int i = 0; i < num.size(); i++) {
			if (character[i + '0'] != num[i] - '0') {
				return false;
			}
		}

		return true;
	}
};

#endif // __leet_code_2283_h__