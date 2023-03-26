/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-23 13:20:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1630.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 19:44:18
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 236ms, 5.24%, MEMORY 75.6MB and 5.25%
 */

#ifndef __leet_code_1630_h__
#define __leet_code_1630_h__

#include<iostream>
#include<set>
#include<map>
#include<vector>

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        int n = nums.size();
        int m = l.size();

        std::vector<bool> result(m, false);
        for (int i = 0; i < m; i++) {

            std::map<int, int> temp;
            for (int j = l[i]; j <= r[i]; j++) {
                temp[nums[j]]++;
            }

            bool is_success = true;
            auto iter = temp.begin();
            int before = (*iter).first;
            (*iter).second--;
            if ((*iter).second == 0) {
                iter++;
            }
            int target = -1;
            while (iter != temp.end()) {
                if (target == -1) {
                    target = (*iter).first - before;
                }
                else {
                    if (target != (*iter).first - before) {
                        is_success = false;
                        break;
                    }
                }
                before = (*iter).first;
                (*iter).second--;
                if ((*iter).second == 0) {
                    iter++;
                }
            }
            if (is_success) {
                result[i] = true;
            }
        }

        return result;
    }
};
#endif // __leet_code_1630_h__