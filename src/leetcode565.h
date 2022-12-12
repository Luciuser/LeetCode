/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-12 10:37:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode565.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-12 10:51:31
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 112ms, 65.20%, MEMORY 92.4MB and 20.34%
 */

#ifndef __leet_code_565__
#define __leet_code_565__

#include<iostream>
#include<vector>

class Solution {
public:
    int arrayNesting(std::vector<int>& nums) {

        int max = 0;
        std::vector<int> find(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (find[i] == 0) {
                int key = i;
                int length = 1;
                find[i] = 1;
                while (nums[key] != i) {
                    length++;
                    key = nums[key];
                    find[key] = 1;
                }
                if (length > max) {
                    max = length;
                }
            }
        }

        return max;
    }
};

#endif // __leet_code_565__