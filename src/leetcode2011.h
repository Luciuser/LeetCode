/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-23 09:05:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2011.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-23 09:08:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 12ms, 18.69%, MEMORY 13.6MB and 54.21%
 */

#ifndef __leet_code_2011__
#define __leet_code_2011__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int finalValueAfterOperations(std::vector<std::string>& operations) {
		int result = 0;
		for (int i = 0; i < operations.size(); i++) {
			if (operations[i][1] == '+') {
				result++;
			}
			else if (operations[i][1] == '-') {
				result--;
			}
		}
		return result;
	}
};

#endif // __leet_code_2011__