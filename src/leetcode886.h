/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-16 12:27:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode886.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-16 13:18:26
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 664ms, 5.24%, MEMORY 79.9MB and 5.07%
 */

#ifndef __leet_code_886__
#define __leet_code_886__

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

#define GREEDY_METHOD // 贪心法，每次都尝试判断该点不友好的点是否能成功，TIME 664ms, 5.24%, MEMORY 79.9MB and 5.07%

struct SimplePairHash {
	std::size_t operator()(const std::pair<int, int>& p) const {
		return p.first ^ p.second;
	}
};

class Solution {
public:
	bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {

		std::vector<int> group1;
		std::vector<int> group2;

		std::unordered_set<std::pair<int, int>, SimplePairHash> dislikeSet;
		for (int i = 0; i < dislikes.size(); i++) {
			dislikeSet.emplace(std::pair<int, int>(dislikes[i][0], dislikes[i][1]));
		}

		//for (int i = 1; i <= n; i++) {
		//	bool temp = false;

		//}

		std::unordered_map<int, std::vector<int>> dislikeMap;
		for (int i = 0; i < dislikes.size(); i++) {
			dislikeMap[dislikes[i][0]].push_back(dislikes[i][1]);
			dislikeMap[dislikes[i][1]].push_back(dislikes[i][0]);
		}
		std::unordered_set<int> used;

		for (int i = 1; i <= n; i++) {
			if (used.count(i) == 0) {
				used.emplace(i);
				std::vector<int> temp = dislikeMap[i];
				for (int j = 0; j < temp.size(); j++) {
					used.emplace(temp[j]);
				}
				while (temp.size() > 0) {
					std::vector<int> next;
					for (int j = 0; j < temp.size(); j++) {
						for (int k = j + 1; k < temp.size(); k++) {
							if (dislikeSet.count(std::pair<int, int>(temp[j], temp[k])) != 0) {
								return false;
							}
						}
					}
					for (int j = 0; j < temp.size(); j++) {
						for (int k = 0; k < dislikeMap[temp[j]].size(); k++) {
							if (used.count(dislikeMap[temp[j]][k]) == 0) {
								next.push_back(dislikeMap[temp[j]][k]);
								used.emplace(dislikeMap[temp[j]][k]);
							}
						}
					}
					temp = next;
				}
			}
		}

		return true;
	}
};

#endif // __leet_code_886__