/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-01 09:35:38
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1779.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-01 09:38:35
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 144ms, 69.21%, MEMORY 58.1MB and 13.01%
 */

#ifndef __leet_code_1779__
#define __leet_code_1779__

#include<iostream>
#include<vector>

class Solution {
public:
    int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
        int index = -1;
        int min = std::numeric_limits<int>::max();
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int length = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (length < min) {
                    index = i;
                    min = length;
                }
            }
        }

        return index;
    }
};

#endif // __leet_code_1779__