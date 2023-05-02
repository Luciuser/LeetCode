/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-11 13:25:33
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode48.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-11 13:41:39
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 7MB and 22.38%
 */

#ifndef __leet_code_48_h__
#define __leet_code_48_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - 2 * i - 1; j++) {
                int temp = matrix[i][i + j];
                matrix[i][i + j] = matrix[n - i - j - 1][i];
                matrix[n - i - j - 1][i] = matrix[n - i - 1][n - i - j - 1];
                matrix[n - i - 1][n - i - j - 1] = matrix[i + j][n - i - 1];
                matrix[i + j][n - i - 1] = temp;
            }
        }

        return;
    }
};

#endif // __leet_code_48_h__