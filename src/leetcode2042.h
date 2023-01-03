/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-03 09:38:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2042.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-03 09:46:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.2MB and 44.94%
 */

#ifndef __leet_code_2042__
#define __leet_code_2042__

#include<iostream>
#include<string>

class Solution {
public:
	bool areNumbersAscending(std::string s) {
		s += " ";
		int before = -1;
		int temp = 0;
		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				temp = temp * 10 + s[i] - '0';
			}
			else {
				if (temp != 0) {
					if (before < temp) {
						before = temp;
					}
					else {
						return false;
					}
					temp = 0;
				}
			}
		}

		return true;
	}
};

#endif // __leet_code_2042__