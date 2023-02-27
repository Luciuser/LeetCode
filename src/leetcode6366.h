/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6366.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-26
 * @Editor: Bingyang Jin
 * @Description: create BFS_MAP_METHOD, TIME 0ms, 0.00%, MEMORY 123.4MB and 0.00%
 */

#ifndef __leet_code_6366_h__ 
#define __leet_code_6366_h__

#include<iostream>
#include<algorithm>
#include<assert.h>
#include<map>
#include<vector>

#define BFS_MAP_METHOD

class Solution {
public:
	int minimumTime(std::vector<std::vector<int>>& grid) {
		
		int m = grid.size();
		int n = grid[0].size();

		// 判断能否走到
		bool is_success = false;
		if (m >= 2 && grid[1][0] <= 1) {
			is_success = true;
		}
		if (n >= 2 && grid[0][1] <= 1) {
			is_success = true;
		}
		if (is_success == false) {
			return -1;
		}

		std::vector<std::vector<int>> mark(m, std::vector<int>(n, 0)); // 标记每个格子是否已经到达
		std::map<int, std::vector<std::pair<int, int>>> time_to_position; // 可到达的每个格子所需要的最小时间
		time_to_position[0].emplace_back(std::pair<int, int>(0, 0)); // 初始值
		std::vector<std::vector<int>> xychange = { {-1,0},{1,0},{0,-1},{0,+1} }; // 向上、向下、向左、向右时，x、y的变化

		auto iter = time_to_position.begin();
		while (true) {
			
			if (iter == time_to_position.end()) {
				break;
			}

			int current_time = (*iter).first;
			auto current_position = (*iter).second;

			for (int i = 0; i < current_position.size(); i++) {
				int x = current_position[i].first;
				int y = current_position[i].second;

				if (mark[x][y] == 1) {
					continue;
				}
				mark[x][y] = 1; // 标记当前格子

				if (x == m - 1 && y == n - 1) {
					return current_time;
				}

				// 从该格子开始向各个方向前进
				for (int j = 0; j < 4; j++) {
					int new_x = x + xychange[j][0];
					int new_y = y + xychange[j][1];
					if (0 <= new_x && new_x <= m - 1 && 0 <= new_y && new_y <= n - 1 && mark[new_x][new_y] == 0) {
						if (grid[new_x][new_y] > current_time + 1) {
							if ((grid[new_x][new_y] + new_x + new_y) % 2 != 0) {
								time_to_position[grid[new_x][new_y] + 1].push_back(std::pair<int, int>(new_x, new_y));
							}
							else {
								time_to_position[grid[new_x][new_y]].push_back(std::pair<int, int>(new_x, new_y));
							}
						}
						else {
							time_to_position[current_time + 1].push_back(std::pair<int, int>(new_x, new_y));
						}
					}
				}

			}

			iter++;
		}

		assert(false);
		return -1;
	}

};
#endif // __leet_code_6366_h__