/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-26 15:26:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1574.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-26 15:19:04
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 69.84%, MEMORY 7.5MB and 54.37%
 */

#ifndef __leet_code_1574_h__
#define __leet_code_1574_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int findLengthOfShortestSubarray(std::vector<int>& arr) {
        int n = arr.size(), j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }
        if (j == 0) {
            return 0;
        }
        int res = j;
        for (int i = 0; i < n; i++) {
            while (j < n && arr[j] < arr[i]) {
                j++;
            }
            res = std::min(res, j - i - 1);
            if (i + 1 < n && arr[i] > arr[i + 1]) {
                break;
            }
        }
        return res;
    }
};
#endif // __leet_code_1574_h__