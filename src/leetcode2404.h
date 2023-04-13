/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-13 14:02:54
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2404.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-13 14:12:08
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 76ms, 40.89%, MEMORY 44.5MB and 13.02%
 */

#ifndef __leet_code_2404_h__
#define __leet_code_2404_h__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int mostFrequentEven(std::vector<int>& nums) {
        std::unordered_map<int, int> number_frequence;
        for (int i = 0; i < nums.size(); i++) {
            number_frequence[nums[i]]++;
        }
        int max = -1;
        for (auto iter = number_frequence.begin(); iter != number_frequence.end(); iter++) {
            if ((*iter).first % 2 == 0) {
                if (max == -1) {
                    max = (*iter).first;
                }
                else {
                    if ((*iter).second > number_frequence[max]) {
                        max = (*iter).first;
                    }
                    else if ((*iter).second == number_frequence[max] && (*iter).first < max) {
                        max = (*iter).first;
                    }
                }
            }
        }

        return max;
    }
};

#endif // __leet_code_2404_h__