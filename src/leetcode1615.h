/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-15 10:32:48
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1615.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-15 14:06:39
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 108ms, 12.01%, MEMORY 33.6MB and 26.26%
 */

#ifndef __leet_code_1615_h__
#define __leet_code_1615_h__

#include<iostream>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<vector>


class Solution {
public:

    struct MyHash {
        size_t operator()(const std::pair<int, int>& p) const {
            size_t t1 = std::hash<int>{}(p.first);
            size_t t2 = std::hash<int>{}(p.second);
            return t1 ^ (t2 << 1);
        }
    };

    int maximalNetworkRank(int n, std::vector<std::vector<int>>& roads) {
        std::vector<int> point_rank(n, 0);
        std::unordered_set<std::pair<int, int>, MyHash> road_set;

        for (int i = 0; i < roads.size(); i++) {
            point_rank[roads[i][0]]++;
            point_rank[roads[i][1]]++;
            if (roads[i][0] < roads[i][1]) {
                road_set.insert(std::pair<int, int>(roads[i][0], roads[i][1]));
            }
            else {
                road_set.insert(std::pair<int, int>(roads[i][1], roads[i][0]));
            }
        }

        std::map<int, std::vector<int>, std::greater<int>> max_point_rank;
        for (int i = 0; i < point_rank.size(); i++) {
            max_point_rank[point_rank[i]].emplace_back(i);
        }

        auto iter = max_point_rank.begin();
        if ((*iter).second.size() == 1) {
            int begin = (*iter).second[0];
            iter++;
            for (int i = 0; i < (*iter).second.size(); i++) {
                int end = (*iter).second[i];
                if (begin < end) {
                    if (road_set.count(std::pair<int, int>(begin, end)) == 0) {
                        return point_rank[begin] + point_rank[end];
                    }
                }
                else {
                    if (road_set.count(std::pair<int, int>(end, begin)) == 0) {
                        return point_rank[begin] + point_rank[end];
                    }
                }
            }
            int end = (*iter).second[0];
            return point_rank[begin] + point_rank[end] - 1;
        }
        else {
            int size = (*iter).second.size();
            for (int i = 0; i < size; i++) {
                int begin = (*iter).second[i];
                for (int j = i + 1; j < size; j++) {
                    int end = (*iter).second[j];
                    if (begin < end) {
                        if (road_set.count(std::pair<int, int>(begin, end)) == 0) {
                            return point_rank[begin] + point_rank[end];
                        }
                    }
                    else {
                        if (road_set.count(std::pair<int, int>(end, begin)) == 0) {
                            return point_rank[begin] + point_rank[end];
                        }
                    }
                }

            }
            int begin = (*iter).second[0];
            return 2 * point_rank[begin] - 1;
        }

    }
};

#endif // __leet_code_1615_h__