/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-22 09:50:06
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode878.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-22 10:59:15
 * @Editor: Bingyang Jin
 * @Description: create DICHOTOMY_METHOD, TIME 0ms, 100.00%, MEMORY 5.7MB and 93.51%
 */

#ifndef __leet_code_878__
#define __leet_code_878__

#include<iostream>

class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {
        
        long long MOD = 1e9 + 7;

        // 求最大公约数
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int a_t = a;
        int b_t = b;
        while (true) {
            if (b_t % a_t == 0) {
                break;
            }
            int temp = b_t;
            b_t = a_t;
            a_t = temp % a_t;
        }
        int gcdAB = a * b / a_t;

        long long left = a;
        long long right = b;
        right *= n;

        // 二分法找严格递增数组 an 和 bn 的中位数
        while (true) {
            long long middle = (left + right) / 2;

            long long ax = middle / a;
            long long bx = middle / b;
            long long same = middle / gcdAB;
            long long number =  ax + bx - same;
            if (number == n - 1) {
                long long a_next = (ax + 1) * a;
                long long b_next = (bx + 1) * b;
                if (a_next < b_next) {
                    return a_next % MOD;
                }
                else {
                    return b_next % MOD;
                }
            }
            else if (number == n) {
                long long a_next = ax * a;
                long long b_next = bx * b;
                if (a_next < b_next) {
                    return b_next % MOD;
                }
                else {
                    return a_next % MOD;
                }
            }
            else if (number == n + 1) {
                long long a_next = ax * a;
                long long b_next = bx * b;
                if (a_next < b_next) {
                    b_next = (bx - 1) * b;
                    if (a_next < b_next) {
                        return b_next % MOD;
                    }
                    else {
                        return a_next % MOD;
                    }
                }
                else {
                    a_next = (ax - 1) * a;
                    if (a_next < b_next) {
                        return b_next % MOD;
                    }
                    else {
                        return a_next % MOD;
                    }
                }
            }

            if (number < n - 1) {
                left = middle;
            }
            else {
                right = middle;
            }

        }

    }
};

#endif // __leet_code_878__