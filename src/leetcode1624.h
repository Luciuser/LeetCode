/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-17 09:29:06
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1624.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-17 09:36:27
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.3MB and 15.85%
 */

#ifndef __leet_code_1624__
#define __leet_code_1624__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class Solution {
public:
	int maxLengthBetweenEqualCharacters(std::string s) {
		std::unordered_map<char, int> charNums;
		int result = -1;
		for (int i = 0; i < s.size(); i++) {
			if (charNums.count(s[i]) == 0) {
				charNums[s[i]] = i;
			}
			else {
				int length = i - charNums[s[i]] - 1;
				result = result < length ? length : result;
				charNums[s[i]] = i;
			}
		}
		return result;
	}
};

#endif // __leet_code_1624__