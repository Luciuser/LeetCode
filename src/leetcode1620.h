/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-02 09:15:36
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1620.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-02 10:30:55
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 808ms, 5.95%, MEMORY 28.3MB and 11.90%
 */

#ifndef __leet_code_1620__
#define __leet_code_1620__

#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>

class Solution {
public:

	struct HashStruct
	{
	public:
		template<typename T, typename U>
		std::size_t operator()(const std::pair<T, U> &x) const{
			return std::hash<T>()(x.first) ^ std::hash<T>()(x.second);
		}
	};

	std::vector<int> bestCoordinate(std::vector<std::vector<int>>& towers, int radius) {
		
		int max = -1;
		std::vector<int> result = { 100,100 };

		std::unordered_map<std::pair<int, int>, int, HashStruct> influence;
		for (int i = 0; i < towers.size(); i++) {
			int x1 = towers[i][0];
			int y1 = towers[i][1];
			int p = towers[i][2];

			int x_begin = x1 - radius > 0 ? x1 - radius : 0;
			int x_end = x1 + radius <= 50 ? x1 + radius : 50;
			int y_begin = y1 - radius > 0 ? y1 - radius : 0;
			int y_end = y1 + radius <= 50 ? y1 + radius : 50;

			for (int xi = x_begin; xi <= x_end; xi++) {
				for (int yi = y_begin; yi <= y_end; yi++) {
					double distance = sqrt((x1 - xi)*(x1 - xi) + (y1 - yi)*(y1 - yi));
					if (distance <= radius) {
						std::pair<int, int>temp(xi, yi);
						influence[temp] += p / (1 + distance);
						if (influence[temp] > max) {
							max = influence[temp];
							result[0] = xi;
							result[1] = yi;
						}
						else if (influence[temp] == max) {
							if ((xi < result[0]) || (xi == result[0] && yi < result[1])) {
								result[0] = xi;
								result[1] = yi;
							}
						}
					}
				}
			}
		}

		if (max == 0) {
			result[0] = 0;
			result[1] = 0;
		}

		return result;
	}
};

#endif // __leet_code_1620__