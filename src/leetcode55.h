/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-18 20:14:16
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode55.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 19:44:18
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 52ms, 57.80%, MEMORY 47.3MB and 22.19%
 */

#ifndef __leet_code_743_h__
#define __leet_code_743_h__

#include<iostream>
#include<vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return true;
        }

        int need = 1;
        for (int i = n - 2; i > 0; i--) {
            // 根据第 i 个值，判断能否到达后面的区域
            if (nums[i] >= need) {
                need = 1;
            }
            else {
                need++;
            }
        }

        return nums[0] >= need;
    }
};

#endif // __leet_code_55_h__