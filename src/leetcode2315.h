/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-29 09:15:24
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2315.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-29 09:17:52
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.3MB and 34.29%
 */

#ifndef __leet_code_2315_h__
#define __leet_code_2315_h__

#include<iostream>
#include<string>

class Solution {
public:
	int countAsterisks(std::string s) {
		int result = 0;
		int is_in_pair = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '*' && is_in_pair == 0) {
				result++;
			}
			if (s[i] == '|') {
				is_in_pair = 1 - is_in_pair;
			}
		}

		return result;
	}
};

#endif // __leet_code_2315_h__