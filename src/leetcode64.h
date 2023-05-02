/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-15 14:16:18
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode64.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-15 14:20:23
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 8ms, 80.65%, MEMORY 9.3MB and 92.13%
 */

#ifndef __leet_code_64_h__
#define __leet_code_64_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // 计算第一行和第一列
        for (int i = 1; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }

        // 动态规划，计算剩余部分
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += grid[i - 1][j] < grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            }
        }

        return grid[m - 1][n - 1];
    }
};

#endif // __leet_code_64_h__