/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-20 10:26:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode20.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-20 10:30:09
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.1MB and 65.60w%
 */

#ifndef __leet_code_20__
#define __leet_code_20__

#include<iostream>
#include<string>
#include<stack>

class Solution {
public:
	bool isValid(std::string s) {
		std::stack<char> character;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				character.emplace(s[i]);
			}
			else {
				if (character.size() == 0) {
					return false;
				}
				char c = character.top();
				if (c == '(' && s[i] == ')') {
					character.pop();
					continue;
				}
				if (c == '[' && s[i] == ']') {
					character.pop();
					continue;
				}
				if (c == '{' && s[i] == '}') {
					character.pop();
					continue;
				}
				return false;
			}
		}

		if (character.size() == 0) {
			return true;
		}

		return false;
	}
};

#endif // __leet_code_20__