/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-19 09:26:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2299.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-19 09:41:44
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 91.32%
 */

#ifndef __leet_code_2299_h__
#define __leet_code_2299_h__

#include<iostream>

class Solution {
public:
	bool strongPasswordCheckerII(std::string password) {
		bool is_lower_character = false;
		bool is_higher_character = false;
		bool is_number = false;
		bool is_special_character = false;

		if (password.size() < 8) {
			return false;
		}
		char before = ' ';
		for (int i = 0; i < password.size(); i++) {
			if ('a' <= password[i] && password[i] <= 'z') {
				is_lower_character = true;
			}
			else if ('A' <= password[i] && password[i] <= 'Z') {
				is_higher_character = true;
			}
			else if ('0' <= password[i] && password[i] <= '9') {
				is_number = true;
			}
			else 
				switch (password[i])
				{
				case '!':;
				case '@':;
				case '#':;
				case '$':;
				case '%':;
				case '^':;
				case '&':;
				case '*':;
				case '(':;
				case ')':;
				case '-':;
				case '+':is_special_character = true; break;
				default:
					break;
				}
			if (before == password[i]) {
				return false;
			}
			before = password[i];
		}

		if (is_lower_character && is_higher_character && is_number && is_special_character) {
			return true;
		}

		return false;
	}
};

#endif // __leet_code_2299_h__