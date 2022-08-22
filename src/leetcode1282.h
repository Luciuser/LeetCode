/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-12 13:37:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1417.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-12 14:03:00
 * @Editor: Bingyang Jin
 * @Description: create QUEUE_METHOD, TIME 8ms, 87.21%, MEMORY 14.5MB and 5.03%
 */

#ifndef __leet_code_1282__
#define __leet_code_1282__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes) {
		std::unordered_map<int, std::vector<std::vector<int>>> size2group;

		for (int i = 0; i < groupSizes.size(); i++) {
			if (size2group.count(groupSizes[i]) == 0) {
				std::vector<int> temp;
				temp.push_back(i);
				std::vector<std::vector<int>> temp2;
				temp2.push_back(temp);
				size2group[groupSizes[i]] = temp2;
			}
			else {
				int num = size2group[groupSizes[i]].size();
				if (size2group[groupSizes[i]][num - 1].size() < groupSizes[i]) {
					size2group[groupSizes[i]][num - 1].push_back(i);
				}
				else {
					std::vector<int> temp;
					temp.push_back(i);
					size2group[groupSizes[i]].push_back(temp);
				}
			}
		}

		std::vector<std::vector<int>> result;
		for (auto iter = size2group.begin(); iter != size2group.end(); iter++) {
			int num = (*iter).second.size();
			for (int i = 0; i < num; i++) {
				result.push_back((*iter).second[i]);
			}
		}

		return result;
	}
};

#endif // __leet_code_1282__