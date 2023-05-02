/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-26 15:16:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2395.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-26 15:19:04
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 69.84%, MEMORY 7.5MB and 54.37%
 */

#ifndef __leet_code_2395_h__
#define __leet_code_2395_h__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    bool findSubarrays(std::vector<int>& nums) {
        std::unordered_set<int> my_set;
        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i - 1] + nums[i];
            if (my_set.count(sum) == 0) {
                my_set.insert(sum);
            }
            else {
                return true;
            }
        }

        return false;
    }
};
#endif // __leet_code_2395_h__