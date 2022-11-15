/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-15 10:29:38
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode791.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-15 10:37:26
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 69.53%
 */

#ifndef __leet_code_791__
#define __leet_code_791__

#include<iostream>
#include<string>
#include<unordered_map>

class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        std::unordered_map<char, int> characters;
        for (int i = 0; i < order.size(); i++) {
            characters[order[i]] = 0;
        }

        std::string unoccur = "";
        for (int i = 0; i < s.size(); i++) {
            if (characters.count(s[i]) == 0) {
                unoccur += s[i];
            }
            else {
                characters[s[i]]++;
            }
        }

        std::string result = "";
        for (int i = 0; i < order.size(); i++) {
            for (int j = 0; j < characters[order[i]]; j++) {
                result += order[i];
            }
        }

        result += unoccur;
        return result;
    }
};

#endif // __leet_code_791__