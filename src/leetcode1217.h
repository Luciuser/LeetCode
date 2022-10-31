/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-31 13:22:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1217.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-31 13:18:30
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 0ms, 100.00%, MEMORY 7MB and 97.46%
 */

#ifndef __leet_code_1217__
#define __leet_code_1217__

#include<iostream>
#include<vector>

class Solution {
public:
	int minCostToMoveChips(std::vector<int>& position) {
		int m = 0, n = 0;
		for (int i = 0; i < position.size(); i++) {
			position[i] % 2 == 0 ? m++ : n++;
		}

		return m < n ? m : n;
	}
};

#endif // __leet_code_1217__