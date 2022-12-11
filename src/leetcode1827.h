/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-11 10:21:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1827.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-11 10:25:23
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 99.77%, MEMORY 15.3MB and 94.13%
 */

#ifndef __leet_code_1827__
#define __leet_code_1827__

#include<iostream>
#include<vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] >= nums[i]) {
                sum += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }

        return sum;
    }
};

#endif // __leet_code_1827__