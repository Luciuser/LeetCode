/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-30 10:11:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode784.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-30 10:33:09
 * @Editor: Bingyang Jin
 * @Description: create BIT_METHOD, TIME 4ms, 89.69%, MEMORY 9.1MB and 96.11%
 */

#ifndef __leet_code_784__
#define __leet_code_784__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::vector<std::string> letterCasePermutation(std::string s) {

		std::vector<int> index;
		for (int i = 0; i < s.size(); i++) {
			if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
				index.push_back(i);
			}
		}

		std::vector<std::string> result;
		int n = index.size();
		for (int order = 0; order < pow(2, n); order++) {
			int temp = order;
			std::string str = s;
			int i = 0;
			while (temp > 0) {
				if (temp % 2 == 1) {
					if (('a' <= str[index[i]] && str[index[i]] <= 'z')) {
						str[index[i]] = str[index[i]] + 'A' - 'a';
					}
					else{
						str[index[i]] = str[index[i]] + 'a' - 'A';
					}
				}
				temp /= 2;
				i++;
			}
			result.push_back(str);
		}

		return result;
	}
};

#endif // __leet_code_784__