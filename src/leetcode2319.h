/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-31 10:12:16
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2319.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-31 10:15:45
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 32ms, 49.32%, MEMORY 16MB and 5.02%
 */

#ifndef __leet_code_2319_h__
#define __leet_code_2319_h__

#include<iostream>
#include<vector>

class Solution {
public:
	bool checkXMatrix(std::vector<std::vector<int>>& grid) {
		int n = grid.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || i + j + 1 == n) {
					if (grid[i][j] == 0) {
						return false;
					}
				}
				else {
					if (grid[i][j] != 0) {
						return false;
					}
				}
			}
		}

		return true;
	}
};

#endif // __leet_code_2319_h__