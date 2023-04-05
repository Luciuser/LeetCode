/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-05 12:05:16
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode34.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-05 12:52:22
 * @Editor: Bingyang Jin
 * @Description: create DICHOTOMY_METHOD, TIME 20ms, 82.01%, MEMORY 24MB and 87.77%
 */

#ifndef __leet_code_34_h__
#define __leet_code_34_h__

#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // 二分法
        int n = nums.size();
        if (n == 0) {
            return { -1,-1 };
        }
        else if (n == 1) {
            if (nums[0] == target) {
                return { 0,0 };
            }
            else {
                return { -1,-1 };
            }
        }
        int left = 0;
        int right = n - 1;

        // 第一次二分，寻找开始位置
        int begin = -1;
        if (nums[left] == target) {
            begin = left;
        }
        else {
            while (true) {
                if (left + 1 == right) {
                    break;
                }
                int middle = (left + right) / 2;
                if (nums[middle] < target) {
                    left = middle;
                }
                else {
                    right = middle;
                }
            }
            if (nums[right] == target) {
                begin = right;
            }
        }

        // 第二次二分，寻找结束位置
        left = 0;
        right = n - 1;
        int end = -1;
        if (nums[right] == target) {
            end = right;
        }
        else {
            while (true) {
                if (left + 1 == right) {
                    break;
                }
                int middle = (left + right) / 2;
                if (nums[middle] <= target) {
                    left = middle;
                }
                else {
                    right = middle;
                }
            }
            if (nums[left] == target) {
                end = left;
            }
        }

        return { begin, end };

    }
};

#endif // __leet_code_34_h__