/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-13 00:23:49
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1832.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-13 00:26:31
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 43.89%, MEMORY 6.3MB and 68.78%
 */

#ifndef __leet_code_1832__
#define __leet_code_1832__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::vector<int> c(26, 0);
        for (int i = 0; i < sentence.size(); i++) {
            c[sentence[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (c[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

#endif // __leet_code_1832__