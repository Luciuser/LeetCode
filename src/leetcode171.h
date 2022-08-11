/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-11 11:32:43
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1417.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-11 13:03:24
 * @Editor: Bingyang Jin
 * @Description: create CHANGE_METHOD, TIME 0ms, 100%, MEMORY 5.7MB and 91.70%
 */

#ifndef __leet_code_171__
#define __leet_code_171__

#include<iostream>
#include<string>

class Solution {
public:
	int titleToNumber(std::string columnTitle) {
		long result = 0;
		for (int i = 0; i < columnTitle.size(); i++) {
			result = result * 26 + columnTitle[i] - 'A' + 1;
		}
		return result;
	}
};

#endif // __leet_code_171__