/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-23 11:22:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1768.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-22 11:26:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 24.78%, MEMORY 6.2MB and 33.96%
 */

#ifndef __leet_code_1768__
#define __leet_code_1768__

#include<iostream>
#include<string>

class Solution {
public:
	std::string mergeAlternately(std::string word1, std::string word2) {
		
		std::string result = "";
		int i = 0, j = 0;
		while (true) {
			if (i >= word1.size() || j >= word2.size()) {
				break;
			}
			result += word1[i];
			result += word2[j];
			i++;
			j++;
		}

		if (i < word1.size()) {
			std::string temp = word1.substr(i, word1.size() - i);
			result += temp;
		}
		if (i < word2.size()) {
			std::string temp = word2.substr(j, word2.size() - j);
			result += temp;
		}

		return result;
	}
};

#endif // __leet_code_1768__