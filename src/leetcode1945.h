/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-15 09:44:18
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1945.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-15 10:02:28
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 63.37%, MEMORY 6.1MB and 67.33%
 */

#ifndef __leet_code_1945__
#define __leet_code_1945__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int getLucky(std::string s, int k) {
        std::string number = "";
        for (int i = 0; i < s.size(); i++) {
            number += std::to_string(s[i] - 'a' + 1);
        }
        int sum = 0;
        for (int i = 0; i < number.size(); i++) {
            sum += number[i] - '0';
        }

        int temp = 0;
        while (k != 1) {
            temp = 0;
            while (sum >= 10) {
                temp += sum % 10;
                sum = sum / 10;
            }
            temp += sum;
            k--;
            sum = temp;
        }

        return sum;
    }
};

#endif // __leet_code_1945__