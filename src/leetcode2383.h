/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-13 12:36:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2383.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-13 12:41:29
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 15.68%, MEMORY 10.9MB and 22.46%
 */

#ifndef __leet_code_1129_h__
#define __leet_code_1129_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, std::vector<int>& energy, std::vector<int>& experience) {
        int sum = 0;
        int n = energy.size();
        for (int i = 0; i < n; i++) {
            if (initialEnergy <= energy[i]) {
                sum += (energy[i] - initialEnergy + 1);
                initialEnergy = 1;
            }
            else {
                initialEnergy -= energy[i];
            }

            if (initialExperience <= experience[i]) {
                sum+= (experience[i] - initialExperience + 1);
                initialExperience = experience[i] * 2 + 1;
            }
            else {
                initialExperience += experience[i];
            }
        }

        return sum;
    }
};

#endif // __leet_code_1129_h__