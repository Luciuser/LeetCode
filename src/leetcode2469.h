/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-23 14:12:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2469.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 19:44:18
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 5.43%
 */

#ifndef __leet_code_2469_h__
#define __leet_code_2469_h__

#include<iostream>
#include<set>
#include<map>
#include<vector>

class Solution {
public:
    std::vector<double> convertTemperature(double celsius) {
        return std::vector<double>{celsius + 273.15, celsius * 1.8 + 32};
    }
};

#endif // __leet_code_2469_h__