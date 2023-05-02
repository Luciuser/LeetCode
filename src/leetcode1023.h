/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-14 10:41:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1023.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-14 11:01:46
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 45.38%, MEMORY 7MB and 47.69%
 */

#ifndef __leet_code_1023_h__
#define __leet_code_1023_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    std::vector<bool> camelMatch(std::vector<std::string>& queries, std::string pattern) {
        int n = queries.size();
        std::vector<bool> result(n, false);

        for (int i = 0; i < n; i++) {
            int index = 0;
            bool success = true;
            for (int j = 0; j < queries[i].size(); j++) {
                if (index < pattern.size() && queries[i][j] == pattern[index]) {
                    index++;
                }
                else {
                    if (!('a' <= queries[i][j] && queries[i][j] <= 'z')) {
                        success = false;
                        break;
                    }
                }
            }
            if (success && index >= pattern.size()) {
                result[i] = true;
            }
        }
        
        return result;
    }
};

#endif // __leet_code_1023_h__