/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-14 08:16:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1375.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-13 08:38:29
 * @Editor: Bingyang Jin
 * @Description: create SORT_METHOD, TIME 48ms, 70.14%, MEMORY 37.4MB and 93.06%
 */

#ifndef __leet_code_1375_h__ 
#define __leet_code_1375_h__

#include<algorithm>
#include<iostream>
#include<vector>

class Solution {
public:
	int numTimesAllBlue(std::vector<int>& flips) {
		
		int n = flips.size();

		int sum = 0;
		int max = 0;
		for (int i = 0; i < n; i++) {
			if (flips[i] > max) {
				max = flips[i];
			}
			if (i + 1  == max) {
				sum++;
			}
		}

		return sum;
	}
};

#endif //__leet_code_1375_h__