/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6368.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-26
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 52ms, MEMORY 21.1MB
 */

#ifndef __leet_code_6368_h__ 
#define __leet_code_6368_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::vector<int> divisibilityArray(std::string word, int m) {
		std::vector<int> result(word.size(), 0);
		long long sum = 0;
		for (int i = 0; i < word.size(); i++) {
			sum = sum * 10 + word[i] - '0';
			if (sum%m == 0) {
				result[i] = 1;
			}
			if (sum > m) {
				sum = sum % m;
			}
		}
		return result;
	}
};
#endif // __leet_code_6368_h__