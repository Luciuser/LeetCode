/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-11 10:37:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1417.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-11 11:23:34
 * @Editor: Bingyang Jin
 * @Description: create QUEUE_METHOD, TIME 8ms, 13.9%, MEMORY 7.6MB and 9.87%
 */

#ifndef __leet_code_1417__
#define __leet_code_1417__

#include<iostream>
#include<vector>
#include<string>
#include<queue>

class Solution {
public:
	std::string reformat(std::string s) {
		std::queue<char> character;
		std::queue<char> number;

		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				number.push(s[i]);
			}
			else if ('a' <= s[i] && s[i] <= 'z') {
				character.push(s[i]);
			}
		}

		std::string result = "";
		if ( 0 <= character.size() - number.size() + 1 && character.size() - number.size() <= 1) {
			if (number.size() - character.size() == 1) {
				// 数字比字母多一
				result += number.front();
				number.pop();
			}
			while (true) {
				if (number.size() == 0 || character.size() == 0) {
					break;
				}
				result += character.front();
				character.pop();
				result += number.front();
				number.pop();
			}
			if (character.size() - number.size() == 1) {
				// 字母比数字多一
				result += character.front();
				character.pop();
			}
		}

		return result;
	}
};

#endif // __leet_code_1417__