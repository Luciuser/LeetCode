/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-24 09:09:49
 * @FilePath: /src/leetcode1184.h
  * @Description: create the file and the solution
 */

#ifndef __leet_code_1184__
#define __leet_code_1184__

#include<iostream>
#include<vector>

class Solution {
public:
	int distanceBetweenBusStops(std::vector<int>& distance, int start, int destination) {
		int left;
		int right;
		
		// Ë³Ðò
		int sumSort = 0;
		left = start;
		right = destination > start ? destination : destination + distance.size();
		for (int i = left; i < right; i++) {
			int index = i % distance.size();
			sumSort += distance[index];
		}
		// ÄæÐò
		int sumRev = 0;
		left = destination;
		right = start > destination ? start : start + distance.size();
		for (int i = left; i < right; i++) {
			int index = i % distance.size();
			sumRev += distance[index];
		}
		return sumSort > sumRev ? sumRev : sumSort;
	}
};

#endif // __leet_code_1184__