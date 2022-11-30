/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-29 23:40:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode556.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-30 00:08:39
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.7MB and 98.40%
 */

#ifndef __leet_code_556__
#define __leet_code_556__

#include<iostream>
#include<string>

class Solution {
public:
    int nextGreaterElement(int n) {
        std::string number = std::to_string(n);
        int mid = -1;
        for (int i = 1; i < number.size(); i++) {
            if (number[number.size() - 1 - i] < number[number.size() - i]) {
                mid = i;
                break;
            }
        }

        if (mid == -1) {
            return -1;
        }

        for (int i = 0; i <= mid; i++) {
            if (number[number.size() - i] > number[number.size() - mid - 1]) {
                char temp = number[number.size() - i];
                number[number.size() - i] = number[number.size() - mid - 1];
                number[number.size() - mid - 1] = temp;
                break;
            }
        }

        for (int i = 0; i < mid / 2; i++) {
            char temp = number[number.size() - i - 1];
            number[number.size() - i - 1] = number[number.size() - mid + i];
            number[number.size() - mid + i] = temp;
        }

        long long result = std::atoll(number.c_str());
        long long des = pow(2, 31) - 1;
        if (result > des) {
            return  -1;
        }

        return result;
    }
};

#endif // __leet_code_556__