/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-19 09:46:21
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1043.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-16 22:03:52
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 24.66%, MEMORY 6.1MB and 17.99%
 */

#ifndef __leet_code_1043_h__
#define __leet_code_1043_h__

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

class Solution {
public:
    int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
        // 按最大值将数组划分为多个区间，然后分别基于每个区间两侧的最大值，将区间内所有数改成该数
        
        int n = arr.size();
        std::vector<int> sort_arr(n);
        for (int i = 0; i < n; i++) {
            sort_arr[i] = i;
        }
        std::sort(sort_arr.begin(), sort_arr.end(), [&](const int a, const int b) {
            return arr[a] > arr[b];
        });

        std::unordered_map<int, int>value_index;
        for (int i = 0; i < k; i++) {
            value_index[arr[sort_arr[i]]] = sort_arr[i];
        }

    }
};

#endif // __leet_code_1043_h__