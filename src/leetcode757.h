/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-22 14:59:37
 * @FilePath: /src/leetcode757.h
  * @Description: create the function intersectionSizeTwo2
 */
 /*
  * @EditTime: 2022-07-22 15:20:22
  * @Editor: Bingyang Jin
  * @Description: create Greedy method, time 300ms, memory 55.1MB
  */

#ifndef __leet_code_757__
#define __leet_code_757__

#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>

class Solution {
public:
	// 此函数可返回一个连续整数区间的大小，但是不是本题要求
	int intersectionSizeTwo2(std::vector<std::vector<int>>& intervals) {
		int minRight = intervals[0][1];
		int maxLeft = intervals[0][0];
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i][0] > maxLeft) {
				maxLeft = intervals[i][0];
			}
			if (intervals[i][1] < minRight) {
				minRight = intervals[i][1];
			}
		}

		int result = 2;
		if (minRight - maxLeft >= 2) {
		}
		else {
			result = maxLeft + 1 - (minRight - 1) + 1;
		}
		return result;
	}

	int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
		
		std::sort(intervals.begin(), intervals.end(), [=](std::vector<int> a, std::vector<int> b) {
			return a[0] == b[0] ? a[1] > b[1]:a[0] < b[0];
		});

		std::vector<int> results;
		int sameSize = 2;
		for (int i = intervals.size()-1; i >=0; i--) {
			int count = 0;
			for (int j = results.size() - 1; j >= 0; j--) {
				if (results[j] > intervals[i][1]) {
					break;
				}
				count++;
				if (count >= sameSize) {
					break;
				}
			}

			if (count >= sameSize) {
				continue;
			}
			for (int j = sameSize - count - 1; j >= 0; j--) {
				results.push_back(intervals[i][0] + j);
			}
		}
		return results.size();
	}
};

#endif // __leet_code_757__