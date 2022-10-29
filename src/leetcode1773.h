/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-29 09:40:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1773.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-29 09:43:58
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 64ms, 77.26%, MEMORY 30MB and 91.59%
 */

#ifndef __leet_code_1773__
#define __leet_code_1773__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {

		int result = 0;
		for (int i = 0; i < items.size(); i++) {
			if (ruleKey == "type"&&ruleValue == items[i][0]) {
				result++;
			}
			else if (ruleKey == "color"&&ruleValue == items[i][1]) {
				result++;
			}
			else if (ruleKey == "name"&&ruleValue == items[i][2]) {
				result++;
			}
		}

		return result;
	}
};

#endif // __leet_code_1773__