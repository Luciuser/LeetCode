/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-22 09:11:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition1619.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-22 09:26:57
 * @Editor: Bingyang Jin
 * @Description: create BFS_METHOD, TIME 96ms, 59.89%, MEMORY 56.7MB and 12.43%
 */

#ifndef __audition_16_19_h__ 
#define __audition_16_19_h__

#include<iostream>
#include<queue>
#include<map>
#include<vector>

class Solution {
public:
	std::vector<int> pondSizes(std::vector<std::vector<int>>& land) {
		
		std::map<int, int> result_map;

		int m = land.size();
		int n = land[0].size();

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (land[i][j] == 0) {
					// 开始广度优先搜索
					int sum = 0;
					std::queue<std::pair<int, int>> q;
					q.push(std::pair<int, int>(i, j));
					land[i][j] = 1;

					while (q.size() != 0)	{
						sum++;
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						// 向 8 个方向试探
						for (int xi = -1; xi <= 1; xi++) {
							for (int yi = -1; yi <= 1; yi++) {

								if (xi == 0 && yi == 0) {
									continue;
								}
								
								int xd = x + xi;
								int yd = y + yi;
								if (xd < 0 || xd >= m || yd < 0 || yd >= n) {
									continue;
								}

								if (land[xd][yd] == 0) {
									land[xd][yd] = 1;
									q.push(std::pair<int, int>(xd, yd));
								}

							}
						}

					}
					
					result_map[sum]++;
				}
			}
		}

		std::vector<int> result;
		for (auto iter = result_map.begin(); iter != result_map.end(); iter++) {
			int key = (*iter).first;
			int value = (*iter).second;
			for (int i = 0; i < value; i++) {
				result.push_back(key);
			}
		}

		return result;

	}
};

#endif // __audition_16_19_h__