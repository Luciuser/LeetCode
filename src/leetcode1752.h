/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-27 09:52:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1752.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-27 10:02:45
 * @Editor: Bingyang Jin
 * @Description: create DIJKSTRA_METHOD, TIME 0ms, 100.00%, MEMORY 8.1MB and 65.73%
 */

#ifndef __leet_code_1752__
#define __leet_code_1752__

#include<iostream>
#include<vector>

class Solution {
public:
    bool check(std::vector<int>& nums) {
        int middle = 0;
        bool isRight = true;
        int min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                middle = i;
                isRight = false;
                break;
            }
        }

        if (isRight) {
            return true;
        }
        int max = nums[nums.size() - 1];
        for (int i = middle + 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }

        if (max <= min) {
            return true;
        }
        return false;
    }
};

#endif // __leet_code_1752__