/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-13 14:40:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode56.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-13 14:52:34
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 76ms, 40.89%, MEMORY 44.5MB and 13.02%
 */

#ifndef __leet_code_56_h__
#define __leet_code_56_h__

#include<iostream>
#include<map>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::map<int, int> point_value;
        for (int i = 0; i < intervals.size(); i++) {
            point_value[intervals[i][0]]++;
            point_value[intervals[i][1]]--;
        }

        std::vector<std::vector<int>> result;
        int current_sum = 0;
        int left = -1;
        int right = -1;
        for (auto iter = point_value.begin(); iter != point_value.end(); iter++) {
            if (current_sum == 0) {
                left = (*iter).first;
            }
            current_sum += (*iter).second;
            if (current_sum == 0) {
                right = (*iter).first;
                std::vector<int> temp = { left, right };
                result.emplace_back(temp);
            }
        }
        
        return result;
    }
};

#endif // __leet_code_56_h__