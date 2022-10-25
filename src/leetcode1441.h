/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-25 09:45:06
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1441.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-25 09:48:15
 * @Editor: Bingyang Jin
 * @Description: create SINGLE_ERGODIC_METHOD, TIME 4ms, 43.49%, MEMORY 7.5MB and 93.74%
 */

#ifndef __leet_code_1441__
#define __leet_code_1441__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	std::vector<std::string> buildArray(std::vector<int>& target, int n) {
		int ti = 0;
		std::vector<std::string> result;
		for (int i = 1; i <= n; i++) {
			if (ti >= target.size()) {
				break;
			}
			if (target[ti] == i) {
				result.push_back("Push");
				ti++;
			}
			else if (target[ti] > i) {
				result.push_back("Push");
				result.push_back("Pop");
			}
		}

		return result;
	}
};

#endif // __leet_code_1441__