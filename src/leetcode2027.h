/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-27 09:22:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2027.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-27 09:28:31
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 4ms, 30.88%, MEMORY 6.2MB and 92.17%
 */

#ifndef __leet_code_2027__
#define __leet_code_2027__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumMoves(std::string s) {
		int result = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'X') {
				i += 2;
				result++;
			}
		}
		return result;
	}
};

#endif // __leet_code_2027__