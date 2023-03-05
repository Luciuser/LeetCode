/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-28 16:23:47
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2363.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-28 16:28:45
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 24ms, 89.02%, MEMORY 16MB and 80.89%
 */

#ifndef __leet_code_2363_h__ 
#define __leet_code_2363_h__

#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
	std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
		std::map<int, int> value_weight;
		for (int i = 0; i < items1.size(); i++) {
			value_weight[items1[i][0]] += items1[i][1];
		}
		for (int i = 0; i < items2.size(); i++) {
			value_weight[items2[i][0]] += items2[i][1];
		}

		std::vector<std::vector<int>> result(value_weight.size(), std::vector<int>(2, 0));
		auto iter = value_weight.begin();
		for (int i = 0; i < value_weight.size(); i++) {
			result[i][0] = (*iter).first;
			result[i][1] = (*iter).second;
			iter++;
		}

		return result;
	}
};

#endif // __leet_code_2363_h__