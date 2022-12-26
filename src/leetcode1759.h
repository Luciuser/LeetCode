/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-26 08:50:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1759.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-26 08:58:20
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 24ms, 45.41%, MEMORY 13.1MB and 9.19%
 */

#ifndef __leet_code_1759__
#define __leet_code_1759__

#include<iostream>
#include<string>

class Solution {
public:
	int countHomogenous(std::string s) {
		long long result = 0;
		int temp = 1;
		int MOD = 1e9 + 7;
		s += "_";
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == s[i - 1]) {
				temp++;
			}
			else {
				result += (temp + 1)*temp / 2;
				if (result > MOD) {
					result = result % MOD;
				}
				temp = 1;
			}
		}

		return result;
	}
};

#endif // __leet_code_1759__