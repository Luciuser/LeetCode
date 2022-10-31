/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-01 00:14:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1662.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-01 00:20:14
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 74.94%, MEMORY 11.1MB and 70.97%
 */

#include<iostream>
#include<vector>
#include<string>

#ifndef __leet_code_1662__
#define __leet_code_1662__

class Solution {
public:
	bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {

		int i1 = 0, j1 = 0;
		int i2 = 0, j2 = 0;
		while (true) {
			if (word1[i1][j1] != word2[i2][j2]) {
				return false;
			}

			j1++;
			j2++;
			if (j1 >= word1[i1].size()) {
				i1++;
				j1 = 0;
			}
			if (j2 >= word1[i2].size()) {
				i2++;
				j2 = 0;
			}
			if (i1 == word1.size() || i2 == word2.size()) {
				break;
			}
		}

		if (i1 == word1.size() && i2 == word2.size()) {
			return true;
		}

		return false;
	}
};

#endif // __leet_code_1662__