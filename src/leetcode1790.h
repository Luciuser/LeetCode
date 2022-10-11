/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-11 08:46:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1790.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-11 08:51:17
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 18.89%, MEMORY 6MB and 77.27%
 */

#ifndef __leet_code_1790__
#define __leet_code_1790__

#include<iostream>
#include<string>

class Solution {
public:
	bool areAlmostEqual(std::string s1, std::string s2) {
		int n = s1.size();
		int sum = 0;
		int a, b;
		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				sum++;
				if (sum == 1) {
					a = i;
				}
				else if (sum == 2) {
					b = i;
				}
				else if (sum > 2) {
					return false;
				}
			}
		}

		if (sum == 0) {
			return true;
		}
		else if (sum == 2 && s1[a] == s2[b] && s1[b] == s2[a]) {
			return true;
		}

		return false;
	}
};

#endif // __leet_code_1790__