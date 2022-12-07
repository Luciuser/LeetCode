/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-06 10:36:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1805.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-06 11:05:25
 * @Editor: Bingyang Jin
 * @Description: create VOILENCE_METHOD, TIME 0ms, 100.00%, MEMORY 6.5MB and 25.22%
 */

#ifndef __leet_code_1805__
#define __leet_code_1805__

#include<iostream>
#include<string>
#include<unordered_set>

class Solution {
public:
    int numDifferentIntegers(std::string word) {
        std::unordered_set<std::string> result;
        word += "a";

        int before = 0;
        bool find = false;
        for (int i = 0; i < word.size(); i++) {
            if (find) {
                if ('a' <= word[i] && word[i] <= 'z') {
                    find = false;
                    std::string str = word.substr(before, i - before);
                    before = -1;
                    for (int j = 0; j < str.size(); j++) {
                        if (str[j] != '0') {
                            before = j;
                            break;
                        }
                    }
                    if (before == -1) {
                        str = "0";
                    }
                    else {
                        str = str.substr(before, str.size() - before);
                    }
                    result.emplace(str);
                }
            }
            else {
                if ('0' <= word[i] && word[i] <= '9') {
                    find = true;
                    before = i;
                }
            }
        }

        return result.size();
    }
};

#endif // __leet_code_1805__