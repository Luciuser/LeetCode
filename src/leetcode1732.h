/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-19 14:22:18
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1732.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-19 14:24:02
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 7.6MB and 95.34%
 */

#ifndef __leet_code_1732__
#define __leet_code_1732__

#include<iostream>
#include<vector>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int sum = 0;
        int result = 0;
        for (int i = 0; i < gain.size(); i++) {
            sum += gain[i];
            if (result < sum) {
                result = sum;
            }
        }
        return result;
    }
};

#endif // __leet_code_1732__