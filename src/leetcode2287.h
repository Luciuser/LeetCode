/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-13 08:46:31
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2287.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-13 08:53:59
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD, TIME 0ms, 100.00%, MEMORY 6.2MB and 42.13%
 */

#ifndef __leet_code_2287_h__
#define __leet_code_2287_h__

#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
	int rearrangeCharacters(std::string s, std::string target) {
		std::unordered_map<char, int> target_frequence;
		std::unordered_map<char, int> s_frequence;

		for (int i = 0; i < target.size(); i++) {
			target_frequence[target[i]]++;
		}

		for (int i = 0; i < s.size(); i++) {
			if (target_frequence.count(s[i]) != 0) {
				s_frequence[s[i]]++;
			}
		}

		int result = std::numeric_limits<int>::max();
		for (auto iter = target_frequence.begin(); iter != target_frequence.end(); iter++) {
			char key = (*iter).first;
			if (s_frequence.count(key) == 0) {
				return 0;
			}
			int min = s_frequence[key] / (*iter).second;
			if (min < result) {
				result = min;
			}
		}

		return result;

	}
};

#endif // __leet_code_2287_h__