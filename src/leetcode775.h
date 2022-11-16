/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-16 10:11:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode775.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-16 10:18:39
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 132ms, 22.09%, MEMORY 81.2MB and 48.47%
 */

#ifndef __leet_code_775__
#define __leet_code_775__

#include<iostream>
#include<vector>

class Solution {
public:
    bool isIdealPermutation(std::vector<int>& nums) {
        // 要满足全局倒置数等于局部倒置数，需满足当 0<= i < i+1 < j < n 时，恒有 nums[i] < nums[j]
        int max = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (max > nums[i]) {
                return false;
            }
            if (max < nums[i - 1]) {
                max = nums[i - 1];
            }
        }

        return true;
    }
};

#endif // __leet_code_775__