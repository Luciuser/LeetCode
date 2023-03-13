/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-13 13:05:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode42.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-13 12:41:29
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 16ms, 51.99%, MEMORY 19.6MB and 67.99%
 */

#ifndef __leet_code_42_h__
#define __leet_code_42_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int trap(std::vector<int>& height) {

        // 对于任意一个点，寻找其左侧比它高的最大值，并寻找右侧比它高的最大值，两个最大值的最小，即该点接完雨水后的最大高度
        int n = height.size();

        // 从右往左遍历，计算右侧最大值
        std::vector<int> right(n, 0); // 右侧最大值
        int max = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (height[i] < max) {
                right[i] = max;
            }
            else {
                max = height[i];
            }
        }

        // 从左往右遍历，计算左侧最大值
        max = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (max <= height[i]) {
                max = height[i];
                continue;
            }
            else {
                if (right[i] <= height[i]) {
                    continue;
                }
                else {
                    int temp = max > right[i] ? right[i] : max;
                    result += temp - height[i];
                }
            }
        }

        return result;
    }
};

#endif // __leet_code_42_h__