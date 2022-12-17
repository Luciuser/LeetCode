/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-17 16:34:06
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode13.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-17 16:46:57
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 80.13%, MEMORY 5.8MB and 88.13%
 */

#ifndef __leet_code_13__
#define __leet_code_13__

#include<iostream>
#include<string>

class Solution {
public:

	int romanCharacterToInt(char c) {
		switch (c)
		{
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
		default:
			break;
		}
		return -1;
	}

	int romanToInt(std::string s) {
		int result = 0;
		int temp = romanCharacterToInt(s[0]);
		for (int i = 0; i < s.size() - 1; i++) {
			int next = romanCharacterToInt(s[i + 1]);
			if (next > temp) {
				result -= temp;
			}
			else {
				result += temp;
			}
			temp = next;
		}
		result += romanCharacterToInt(s[s.size() - 1]);
		return result;
	}
};

#endif // __leet_code_13__