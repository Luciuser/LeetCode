/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-18 09:19:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode827.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-18 13:46:16
 * @Editor: Bingyang Jin
 * @Description: create DFS_ENUM_METHOD, TIME OUT
 */

 /*
 * @EditTime: 2022-09-18 13:59:50
 * @Editor: Bingyang Jin
 * @Description: create DFS_ENUM_METHOD, TIME 1200ms, 5.64%, MEMORY 458.3MB and 5.04%
 */

#ifndef __leet_code_827__
#define __leet_code_827__

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

class Solution {
public:

	// 通过 dfs 来建立相应拓扑，O(n^2)
	void dfs(const std::vector<std::vector<int>>& grid) {
		int island = 1;
		int area = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				// 该部分未被遍历
				if (type[i][j] == -1) {
					// 小岛
					std::queue<std::pair<int, int>> qu;
					qu.push(std::pair<int, int>(i, j));
					while (true) {
						if (qu.size() == 0) {
							break;
						}
						std::pair<int, int> qTop = qu.front();
						qu.pop();
						int qi = qTop.first;
						int qj = qTop.second;
						// 小岛区域
						if (type[qi][qj] != -1) {
							continue;
						}
						// 水域
						if (grid[qi][qj] == 0) {
							type[qi][qj] = 0;
							isMax = false;
							continue;
						}
						type[qi][qj] = island;
						area++;
						maxArea++;
						if (qi > 0 && type[qi - 1][qj] == -1) {
							qu.push(std::pair<int, int>(qi - 1, qj));
						}
						if (qi + 1 < grid.size() && type[qi + 1][qj] == -1) {
							qu.push(std::pair<int, int>(qi + 1, qj));
						}
						if (qj > 0 && type[qi][qj - 1] == -1) {
							qu.push(std::pair<int, int>(qi, qj - 1));
						}
						if (qj + 1 < grid[i].size() && type[qi][qj + 1] == -1) {
							qu.push(std::pair<int, int>(qi, qj + 1));
						}
					}
					islandNums[island] = area;
					island++;
					area = 0;
				}
			}
		}
	}

	int largestIsland(std::vector<std::vector<int>>& grid) {
		type = std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid[0].size(), -1));
		dfs(grid);

		if (isMax) {
			return grid.size()*grid.size();
		}

		int crtArea = 0;
		int crtMax = 0;
		// 排查 O(n^2)
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (type[i][j] == 0) {
					std::unordered_map<int, int>islandIndexes;
					if (i > 0 && type[i - 1][j] > 0) {
						islandIndexes[type[i - 1][j]] = 1;
					}
					if (i + 1 < grid.size() && type[i + 1][j] > 0) {
						islandIndexes[type[i + 1][j]] = 1;
					}
					if (j > 0 && type[i][j - 1] > 0) {
						islandIndexes[type[i][j - 1]] = 1;
					}
					if (j + 1 < grid[i].size() && type[i][j + 1] > 0) {
						islandIndexes[type[i][j + 1]] = 1;
					}
					for (auto iterisland = islandIndexes.begin(); iterisland != islandIndexes.end(); iterisland++) {
						crtArea += islandNums[(*iterisland).first];
					}
					if (crtArea == maxArea) {
						return maxArea + 1;
					}

					if (crtArea + 1 > crtMax) {
						crtMax = crtArea + 1;
					}
					crtArea = 0;
				}
			}
		}

		return crtMax;
	}
private:

	std::vector<std::vector<int>> type; // 每个区域是海域或是小岛，-1为初始化，0为海域，1-n为小岛
	std::unordered_map<int, int> islandNums; // 每个小岛的面积
	int maxArea = 0; // 最大面积
	bool isMax = true;
};

#endif // __leet_code_827__