/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-27 11:12:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2309.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-27 11:20:02
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 20ms, 7.76%, MEMORY 10MB and 5.17%
 */

#ifndef __leet_code_2309_h__
#define __leet_code_2309_h__

#include<iostream>
#include<string>
#include<unordered_set>

class Solution {
public:
	std::string greatestLetter(std::string s) {
		char c = 'A' - 1;
		std::unordered_set<char> characters;

		for (int i = 0; i < s.size(); i++) {
			if ('a' <= s[i] && s[i] <= 'z') {
				if (characters.count(s[i] - 'a' + 'A') != 0 && s[i] - 'a' + 'A' > c) {
					c = s[i] - 'a' + 'A';
				}
			}
			else if ('A' <= s[i] && s[i] <= 'Z') {
				if (characters.count(s[i] - 'A' + 'a') != 0 && s[i] > c) {
					c = s[i];
				}
			}

			characters.emplace(s[i]);
		}

		if (c == 'A' - 1) {
			return "";
		}

		return std::string(1, c);
	}
};

#endif // __leet_code_2309_h__