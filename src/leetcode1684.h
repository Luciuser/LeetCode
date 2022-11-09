/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-08 09:51:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1684.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-08 09:55:00
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 64ms, 26.06%, MEMORY 29.5MB and 13.56%
 */

#ifndef __leet_code_1684__
#define __leet_code_1684__

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {

        std::unordered_set<char> character;
        for (int i = 0; i < allowed.size(); i++) {
            character.emplace(allowed[i]);
        }

        int sum = 0;
        for (int i = 0; i < words.size(); i++) {
            bool isSame = true;
            for (int j = 0; j < words[i].size(); j++) {
                if (character.count(words[i][j]) == 0) {
                    isSame = false;
                    continue;
                }
            }
            if (isSame) {
                sum++;
            }
        }

        return sum;
    }
};

#endif // __leet_code_1684__