/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-30 10:55:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1637.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-30 11:02:49
 * @Editor: Bingyang Jin
 * @Description: create SORT_METHOD, TIME OUT
 */

 /*
 * @EditTime: 2023-03-30 11:09:04
 * @Editor: Bingyang Jin
 * @Description: create SET_METHOD, TIME 316ms, 15.28%, MEMORY 79.2MB and 18.06%
 */

#ifndef __leet_code_1637_h__
#define __leet_code_1637_h__

#include<algorithm>
#include<iostream>
#include<set>
#include<vector>

//#define SORT_METHOD // 先排序，再遍历，超时
#define SET_METHOD // 先通过set排序，再遍历，超时

#ifdef SET_METHOD
class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::set<int> x_positions;
        for (int i = 0; i < points.size(); i++) {
            x_positions.emplace(points[i][0]);
        }

        int max = 0;
        auto iter = x_positions.begin();
        int before = *iter;
        iter++;
        while (iter != x_positions.end()) {
            int temp = (*iter) - before;
            if (max < temp) {
                max = temp;
            }
            before = *iter;
            iter++;
        }

        return max;
    }
};
#endif // SET_METHOD

#ifdef SORT_METHOD
class Solution {
public:
    int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [&](std::vector<int> a, std::vector<int> b) {
            return a[0] < b[0];
        });

        int max = 0;
        int before = points[0][0];
        for (int i = 1; i < points.size(); i++) {
            int temp = points[i][0] - before;
            if (temp > max) {
                max = temp;
            }
            before = points[i][0];
        }

        return max;
    }
};
#endif // SORT_METHOD

#endif // __leet_code_1637_h__