/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-02 00:16:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1769.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-02 00:24:43
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 91.79%, MEMORY 8.6MB and 91.05%
 */

#ifndef __leet_code_1769__
#define __leet_code_1769__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        // 动态规划
        // 设 dp[i] 表示所有小球移动到第 i 个数的总次数
        // 记录第 i 个数左边 1 的个数为 left[i]，右边包括自己 1 的个数为 right[i]
        // 那么状态转移公式为：dp[i+1] = dp[i] - right[i] + left[i]
        // 如果第 i 个数是 1，则 left[i+1] = left[i] + 1; right[i] = right[i] - 1;
        // 返回值即 dp 数组

        int left = 0;
        int right = 0;
        int sum = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                right++;
                sum += i;
            }
        }

        std::vector<int> result(boxes.size());
        result[0] = sum;
        if (boxes[0] == '1') {
            right--;
            left++;
        }
        for (int i = 1; i < boxes.size(); i++) {
            // 修改 result
            result[i] = result[i - 1] - right + left;
            // 维护 right 和 left
            if (boxes[i] == '1') {
                right--;
                left++;
            }
        }

        return result;
    }
};

#endif // __leet_code_1769__