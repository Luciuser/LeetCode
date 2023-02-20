/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-20 10:19:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2347.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-20 10:23:04
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 9.9MB and 29.10%
 */

#ifndef __leet_code_2347_h__ 
#define __leet_code_2347_h__

#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<vector>

class Solution {
public:
	std::string bestHand(std::vector<int>& ranks, std::vector<char>& suits) {
		std::unordered_set<char> suits_set;
		for (int i = 0; i < suits.size(); i++) {
			suits_set.emplace(suits[i]);
		}

		if (suits_set.size() == 1) {
			return "Flush";
		}

		std::unordered_map<int, int>ranks_map;
		for (int i = 0; i < ranks.size(); i++) {
			ranks_map[ranks[i]]++;
		}

		for (auto iter : ranks_map) {
			if (iter.second >= 3) {
				return "Three of a Kind";
			}
		}

		if (ranks_map.size() < 5) {
			return "Pair";
		}

		return "High Card";

	}
};

#endif // __leet_code_2347_h__