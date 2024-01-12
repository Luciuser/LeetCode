/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-12 23:46:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2085.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-12 23:54:57
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 24ms, 95.74%, MEMORY 1.69MB and 95.04%
 */

#ifndef __leet_code_2085__
#define __leet_code_2085__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class Solution {
public:
	int countWords(std::vector<std::string>& words1, std::vector<std::string>& words2) {
		std::unordered_map<std::string, int> frequence;
		for (int i = 0; i < words1.size(); i++) {
			frequence[words1[i]]++;
		}
		for (int i = 0; i < words2.size(); i++) {
			if (frequence.find(words2[i]) != frequence.end() && frequence[words2[i]] <= 1) {
				// 有且只有一个
				frequence[words2[i]]--;
			}
		}
		int sum = 0;
		for (auto iter = frequence.begin(); iter != frequence.end(); iter++) {
			if ((*iter).second == 0) {
				sum++;
			}
		}

		return sum;
	}
};

#endif // __leet_code_2085__