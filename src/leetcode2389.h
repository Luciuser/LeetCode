/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-17 13:13:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2389.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-17 13:31:18
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 80.52%, MEMORY 13.3MB and 76.30%
 */

#ifndef __leet_code_2488_h__
#define __leet_code_2488_h__

#include<algorithm>
#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> answerQueries(std::vector<int>& nums, std::vector<int>& queries) {
        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });

        std::vector<int> sort_q(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            sort_q[i] = i;
        }
        std::sort(sort_q.begin(), sort_q.end(), [&](int a, int b) {
            return queries[a] < queries[b];
        });

        std::vector<int> result(queries.size(), 0);

        int i = 0; // nums 的指针
        int j = 0; // queries 的指针
        int sum = 0;
        while (true) {
            if (j >= sort_q.size()) {
                break;
            }
            if (i < nums.size()) {
                sum += nums[i];
            }
            else {
                for (; j < sort_q.size(); j++) {
                    result[sort_q[j]] = i;
                }
                break;
            }

            if (sum <= queries[sort_q[j]]) {
                result[sort_q[j]] = i + 1;
                i++;
            }
            else {
                sum -= nums[i];
                result[sort_q[j]] = i;
                j++;
            }
        }

        return result;
    }
};
#endif // __leet_code_2488_h__