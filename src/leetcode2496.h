/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-23 09:25:07
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2496.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-23 09:28:51
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 7.6MB and 33.05%
 */

#ifndef __leet_code_2496_h__
#define __leet_code_2496_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	int maximumValue(std::vector<std::string>& strs) {
		int max = 0;
		for (int i = 0; i < strs.size(); i++) {
			bool is_number = true;
			int answer = 0;
			for (int j = 0; j < strs[i].size(); j++) {
				if ('0' <= strs[i][j] && strs[i][j] <= '9') {
					answer = answer * 10 + strs[i][j] - '0';
				}
				else {
					is_number = false;
					break;
				}
			}
			if (is_number == false) {
				answer = strs[i].size();
			}
			if (max < answer) {
				max = answer;
			}
		}

		return max;
	}
};

#endif // __leet_code_2496_h__