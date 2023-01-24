/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-24 12:16:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1828.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-24 12:45:50
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 200ms, 18.80%, MEMORY 108.2MB and 16.80%
 */

#ifndef __leet_code_1828_h__
#define __leet_code_1828_h__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> countPoints(std::vector<std::vector<int>>& points, std::vector<std::vector<int>>& queries) {
		
		std::vector<std::vector<int>> is_points_exist(501, std::vector<int>(501, 0));
		for (int i = 0; i < points.size(); i++) {
			is_points_exist[points[i][0]][points[i][1]]++;
		}

		std::vector<int> result(queries.size(), 0);
		for (int i = 0; i < queries.size(); i++) {
			int length = queries[i][2] * 2 + 1;
			if (length * length < points.size()) {
				for (int j = 0; j < length; j++) {
					for (int k = 0; k < length; k++) {
						int r = queries[i][2];
						int x = queries[i][0] - r + j;
						int y = queries[i][1] - r + k;
						if (x < 0 || x > 500 || y < 0 || y > 500) {
							continue;
						}
						if (is_points_exist[x][y] != 0 && (x - queries[i][0])*(x - queries[i][0]) + (y - queries[i][1])*(y - queries[i][1]) <= r * r) {
							result[i] += is_points_exist[x][y];
						}
					}
				}
			}
			else {
				for (int j = 0; j < points.size(); j++) {
					if ((points[j][0] - queries[i][0])*(points[j][0] - queries[i][0]) + (points[j][1] - queries[i][1])*(points[j][1] - queries[i][1]) <= queries[i][2] * queries[i][2]) {
						result[i]++;
					}
				}
			}
		}

		return result;
	}
};

#endif // __leet_code_1828_h__