/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-12 14:47:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode53.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-11 13:41:39
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 7MB and 22.38%
 */

#ifndef __leet_code_53_h__
#define __leet_code_53_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        // 计算前缀和数组
        int n = nums.size();
        std::vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int sum = prefix[1] - prefix[0];
        int min = prefix[0];
        for (int i = 1; i < n + 1; i++) {
            if (prefix[i] > min) {
                int temp = prefix[i] - min;
                if (sum < temp) {
                    sum = temp;
                }
            }
            else {
                int temp = prefix[i] - min;
                if (sum < temp) {
                    sum = temp;
                }
                min = prefix[i];
            }
        }

        return sum;
    }
};

#endif // __leet_code_53_h__