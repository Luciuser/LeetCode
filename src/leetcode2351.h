/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-01 11:10:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2351.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-01 11:16:18
 * @Editor: Bingyang Jin
 * @Description: create SET_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 34.57%
 */

#ifndef __leet_code_2351__
#define __leet_code_2351__

#include<iostream>
#include<string>
#include<unordered_set>

class Solution {
public:
	char repeatedCharacter(std::string s) {
		std::unordered_set<char> cSet;
		for (int i = 0; i < s.size(); i++) {
			if (cSet.count(s[i]) == 0) {
				cSet.emplace(s[i]);
			}
			else {
				return s[i];
			}
		}
		return ' ';
	}
};

#endif // __leet_code_2351__