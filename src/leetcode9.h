/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-24 11:25:07
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode9.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-24 11:27:40
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 12ms, 52.24%, MEMORY 5.9MB and 15.34%
 */

#ifndef __leet_code_9__
#define __leet_code_9__

#include<iostream>
#include<string>

class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0) {
			return false;
		}

		std::string str = std::to_string(x);
		int n = str.size();
		for (int i = 0; i < n / 2; i++) {
			if (str[i] != str[n - i - 1]) {
				return false;
			}
		}

		return true;
	}
};

#endif // __leet_code_9__