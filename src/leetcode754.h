/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-04 09:45:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode754.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-03 10:34:56
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 4ms, 100.00%, MEMORY 5.8MB and 69%
 */

#ifndef __leet_code_754__
#define __leet_code_754__

#include<iostream>
#include<math.h>

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }
        int begin = sqrt(2 * target) - 1;

        int result = 2 * target;
        for (long i = begin; i < 2 * (target + 1); i++) {
            long delta = i * (i + 1) / 2 - target;
            if (delta >= 0 && delta % 2 == 0) {
                result = i;
                break;
            }
        }

        return result;
    }
};

#endif // __leet_code_754__