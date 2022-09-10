/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-07 11:09:54
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode646.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-07 11:34:02
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMING£¬TIME 396ms, 5.02%, MEMORY 66.8MB and 5.00%
 */

 /*
 * @EditTime: 2022-09-07 11:39:43
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD£¬TIME 252ms, 15.24%, MEMORY 64.4MB and 5.00%
 */

#ifndef __leet_code_646__
#define __leet_code_646__

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

//#define DYNAMIC_PROGRAMING // TIME 396ms, 5.02%, MEMORY 66.8MB and 5.00%
#define GREEDY_METHOD // TIME 252ms, 15.24%, MEMORY 64.4MB and 5.00%

#ifdef DYNAMIC_PROGRAMING
class Solution {
public:
	int findLongestChain(std::vector<std::vector<int>>& pairs) {

		std::sort(pairs.begin(), pairs.end(), [=](std::vector<int> a, std::vector<int> b) {
			if (a[0] != b[0]) {
				return a[0] < b[0];
			}
			else {
				return a[1] < b[1];
			}
		});

		int result = 1;
		std::map<int, int> lastNums;
		lastNums[pairs[0][1]] = 1;
		for (int i = 1; i < pairs.size(); i++) {
			int max = 0;
			for (auto iter = lastNums.begin(); iter != lastNums.end(); iter++) {
				if ((*iter).first >= pairs[i][0]) {
					break;
				}

				if (max < (*iter).second) {
					max = (*iter).second;
				}
			}
			lastNums[pairs[i][1]] = max + 1;
			if (result < max + 1) {
				result = max + 1;
			}
		}

		return result;
	}
};
#endif // DYNAMIC_PROGRAMING

#ifdef GREEDY_METHOD
class Solution {
public:
	int findLongestChain(std::vector<std::vector<int>>& pairs) {

		std::sort(pairs.begin(), pairs.end(), [=](std::vector<int> a, std::vector<int> b) {
			if (a[1] != b[1]) {
				return a[1] < b[1];
			}
			else {
				return a[0] < b[0];
			}
		});

		int result = 1;
		int temp = pairs[0][1];
		for (int i = 1; i < pairs.size(); i++) {
			if (pairs[i][0] > temp) {
				result++;
				temp = pairs[i][1];
			}
		}

		return result;
	}
};
#endif // GREEDY_METHOD



#endif // __leet_code_646__