/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-17 16:58:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode14.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-17 17:04:10
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 8.9MB and 59.12%
 */

#ifndef __leet_code_14__
#define __leet_code_14__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		std::string result = "";
		int index = 0;
		while (true) {
			if (index >= strs[0].size()) {
				return result;
			}
			char c = strs[0][index];
			bool isRight = true;
			for (int i = 1; i < strs.size(); i++) {
				if (index >= strs[i].size() || strs[i][index] != c) {
					isRight = false;
					break;
				}
			}
			if (isRight == false) {
				return result;
			}
			result += c;
			index++;
		}

		return result;
	}
};

#endif // __leet_code_14__