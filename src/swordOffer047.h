/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-08 22:46:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/swordOffer047.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-08 22:52:36
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGTAMMING_METHOD, TIME 4ms, 96.23%, MEMORY 8.9MB and 69.18%
 */

#ifndef __sword_offer_047__ 
#define __sword_offer_047__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxValue(std::vector<std::vector<int>>& grid) {
		
		int m = grid.size();
		int n = grid[0].size();
		// 动态规划，直接在 grid 里写即可
		// 初始化
		for (int i = 1; i < grid[0].size(); i++) {
			grid[0][i] += grid[0][i - 1];
		}
		for (int i = 1; i < grid.size(); i++) {
			grid[i][0] += grid[i - 1][0];
		}

		// 动态规划
		for (int i = 1; i < grid.size(); i++) {
			for (int j = 1; j < grid[i].size(); j++) {
				int max = grid[i][j - 1] < grid[i - 1][j] ? grid[i - 1][j] : grid[i][j - 1];
				grid[i][j] += max;
			}
		}

		return grid[m - 1][n - 1];
	}
};

#endif // __sword_offer_047__