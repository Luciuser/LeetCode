/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-05 11:22:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1000.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-05 11:29:31
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 20ms, 82.01%, MEMORY 24MB and 87.77%
 */

#ifndef __leet_code_2427_h__
#define __leet_code_2427_h__

#include<iostream>

class Solution {
public:
    int commonFactors(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }

        int sum = 0;
        for (int i = 1; i <= b; i++) {
            if (a % i == 0 && b % i == 0) {
                sum++;
            }
        }
        return sum;

    }
};

#endif // __leet_code_2427_h__