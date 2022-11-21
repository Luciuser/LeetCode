/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-21 10:03:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode808.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-21 18:44:16
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 0ms, 100.00%, MEMORY 6.5MB and 59.84%
 */

#ifndef __leet_code_808__
#define __leet_code_808__

#include<iostream>
#include<vector>

class Solution {
public:

    double dfs(int an, int bn) {
        
        // 停止条件，某一种汤被分完，或者两种汤被同时分完
        if (an <= 0 && bn > 0) {
            return 1;
        }
        else if (an <= 0 && bn <= 0) {
            return 0.5;
        }
        else if (an > 0 && bn <= 0) {
            return 0;
        }

        if (memo[an][bn] != -1) {
            return memo[an][bn];
        }

        // 动态规划
        memo[an][bn] = 0.25 * (dfs(an - 4, bn) + dfs(an - 3, bn - 1) + dfs(an - 2, bn - 2) + dfs(an - 1, bn - 3));

        return memo[an][bn];
    }

    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        
        memo = std::vector<std::vector<double>>(n + 1, std::vector<double>(n + 1, -1));
        return dfs(n, n);
    }

private:
    std::vector<std::vector<double>> memo;
};

#endif // __leet_code_808__