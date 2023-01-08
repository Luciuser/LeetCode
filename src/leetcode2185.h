/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-08 09:55:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2185.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-08 09:59:46
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 11.33%, MEMORY 9.6MB and 71.87%
 */

#ifndef __leet_code_2185_h__
#define __leet_code_2185_h__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int prefixCount(std::vector<std::string>& words, std::string pref) {
		int result = 0;
		for (int i = 0; i < words.size(); i++) {
			if (words[i].size() < pref.size()) {
				continue;
			}
			bool success = true;
			for (int j = 0; j < pref.size(); j++) {
				if (words[i][j] != pref[j]) {
					success = false;
					break;
				}
			}
			if (success) {
				result++;
			}
		}
		return result;
	}
};

#endif // __leet_code_2185_h__