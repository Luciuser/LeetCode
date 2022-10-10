/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-10 13:06:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode801.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-10 13:43:41
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 55.89%
 */

#ifndef __leet_code_1694__
#define __leet_code_1694__

#include<iostream>
#include<string>

class Solution {
public:
	std::string reformatNumber(std::string number) {
		std::string temp = "";

		for (int i = 0; i < number.size(); i++) {
			if ('0' <= number[i] && number[i] <= '9') {
				temp += number[i];
			}
		}

		std::string result = "";
		int i = 0;
		for (; i < temp.size(); i += 3) {
			if (i + 4 >= temp.size()) {
				break;
			}
			result += temp[i];
			result += temp[i + 1];
			result += temp[i + 2];
			result += "-";
		}

		int last = (int)(temp.size()) - i;
		switch (last) {
		case 4: {
			result += temp[i];
			result += temp[i + 1];
			result += '-';
			result += temp[i + 2];
			result += temp[i + 3];
			break;
		}
		case 3: {
			result += temp[i];
			result += temp[i + 1];
			result += temp[i + 2];
			break;
		}
		case 2: {
			result += temp[i];
			result += temp[i + 1];
			break;
		}
		}

		return result;
	}
};

#endif // __leet_code_1694__