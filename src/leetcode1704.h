/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-11 09:17:32
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1704.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-11 09:22:48
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 69.00%, MEMORY 6.5MB and 51.00%
 */

#ifndef __leet_code_1704__
#define __leet_code_1704__

#include<iostream>
#include<string>

class Solution {
public:
    bool halvesAreAlike(std::string s) {
        int i_n = 0;
        int j_n = 0;
        for (int i = 0; i < s.size() / 2; i++) {
            int j = s.size() - i - 1;
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                i_n++;
            }
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
                s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U') {
                j_n++;
            }
        }

        return i_n == j_n;
    }
};

#endif // __leet_code_1704__