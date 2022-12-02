/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-03 00:16:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1796.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-03 00:23:20
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.6MB and 70.00%
 */

#ifndef __leet_code_1796__
#define __leet_code_1796__

#include<iostream>
#include<string>

class Solution {
public:
    int secondHighest(std::string s) {

        int max = -std::numeric_limits<int>::max();
        bool find = false;
        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                find = true;
                if (max < s[i] - '0') {
                    max = s[i] - '0';
                }
            }
        }

        if (find == false) {
            return -1;
        }
        find = false;
        int result = -std::numeric_limits<int>::max();
        for (int i = 0; i < s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (s[i] - '0' < max) {
                    find = true;
                    if (result < s[i] - '0') {
                        result = s[i] - '0';
                    }
                }
            }
        }
        if (find == false) {
            return -1;
        }
        return result;
    }
};

#endif // __leet_code_1796__