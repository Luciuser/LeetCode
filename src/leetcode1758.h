/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-29 14:18:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1758.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-29 14:23:36
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 18.22%, MEMORY 6.8MB and 59.48%
 */

#ifndef __leet_code_1758__
#define __leet_code_1758__

#include<iostream>
#include<string>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        int a = n;
        int b = n;
        for (int i = 0; i < n; i++) {
            int temp = i % 2;
            if (temp == 0) {
                if (s[i] == '0') {
                    a--;
                }
                else if (s[i] == '1') {
                    b--;
                }
            }
            else {
                if (s[i] == '0') {
                    b--;
                }
                else if (s[i] == '1') {
                    a--;
                }
            }
        }

        if (a < b) {
            return a;
        }
        return b;
    }
};

#endif // __leet_code_1758__