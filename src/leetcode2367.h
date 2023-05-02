/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-31 14:06:31
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2367.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-31 14:10:57
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 8.4MB and 49.73%
 */

#ifndef __leet_code_2367_h__
#define __leet_code_2367_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int arithmeticTriplets(std::vector<int>& nums, int diff) {
        
        int n = nums.size();
        int sum = 0;
        int i = 0, j = 0, k = 0;
        while (i < n && j < n && k < n) {
            if (nums[j] - nums[i] > diff) {
                i++;
            }
            else if (nums[j] - nums[i] < diff) {
                j++;
            }
            else {
                if (nums[k] - nums[j] > diff) {
                    j++;
                }
                else if (nums[k] - nums[j] < diff) {
                    k++;
                }
                else {
                    sum++;
                    i++;
                    j++;
                    k++;
                }
            }
        }

        return sum;
    }
};

#endif // __leet_code_2367_h__