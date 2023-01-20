/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-20 09:40:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1817.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-20 10:03:58
 * @Editor: Bingyang Jin
 * @Description: create UNORDERED_SET_METHOD, TIME 224ms, 48.39%, MEMORY 69.2MB and 89.52%
 */

#ifndef __leet_code_1817_h__
#define __leet_code_1817_h__

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_set>

class Solution {
public:
	std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k) {

		// 按照用户ID，对 log 进行排序
		std::sort(logs.begin(), logs.end(), [&](std::vector<int> &a, std::vector<int> &b) {
			return a[0] < b[0];
		});

		// 计算每个用户的 UAM
		std::vector<int> result(k, 0);
		int usr_ID = logs[0][0];
		std::unordered_set<int> minute;
		for (int i = 0; i < logs.size(); i++) {
			if (logs[i][0] != usr_ID) {
				result[(int)minute.size() - 1]++;
				minute.clear();
				usr_ID = logs[i][0];
			}
			minute.emplace(logs[i][1]);
		}
		result[(int)minute.size() - 1]++;

		return result;
	}
};

#endif // __leet_code_1817_h__