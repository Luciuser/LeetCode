/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-15 12:49:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1042.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-15 13:16:05
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-04-15 13:20:57
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 120ms, 55.06%, MEMORY 44.8MB and 41.29%
 */

#ifndef __leet_code_1042_h__
#define __leet_code_1042_h__

#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<vector>

//#define DFS_METHOD // DFS 算法，会超时
#define NORMAL_METHOD // 直接枚举

#ifdef DFS_METHOD
class Solution {
public:
    std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths) {

        std::unordered_map<int, std::vector<int>> connect;
        for (int i = 0; i < paths.size(); i++) {
            int a = paths[i][0] - 1;
            int b = paths[i][1] - 1;
            connect[a].push_back(b);
            connect[b].push_back(a);
        }

        // DFS
        std::vector<int> result(n, -1); // -1 表示当前花园还没有涂色
        std::vector<int> temp(5, 0);
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            if (result[i] == -1) {
                q.push(i);
            }
            while (true) {
                if (q.size() == 0) {
                    break;
                }
                int current_node = q.front();
                q.pop();

                for (int j = 0; j < connect[current_node].size(); j++) {
                    int node = connect[current_node][j];
                    if (result[node] == -1) {
                        q.emplace(node);
                    }
                    else {
                        temp[result[node]] = 1;
                    }
                }
                for (int j = 1; j <= 4; j++) {
                    if (temp[j] == 0) {
                        result[current_node] = j;
                        break;
                    }
                }
                for (int j = 1; j <= 4; j++) {
                    temp[j] = 0;
                }
            }
        }

        return result;
    }
};
#endif // DFS_METHOD

#ifdef NORMAL_METHOD
class Solution {
public:
    std::vector<int> gardenNoAdj(int n, std::vector<std::vector<int>>& paths) {

        std::unordered_map<int, std::vector<int>> connect;
        for (int i = 0; i < paths.size(); i++) {
            int a = paths[i][0] - 1;
            int b = paths[i][1] - 1;
            connect[a].push_back(b);
            connect[b].push_back(a);
        }

        std::vector<int> result(n, 0); // -1 表示当前花园还没有涂色
        std::vector<int> temp(5, 0);
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < connect[i].size(); j++) {
                temp[result[connect[i][j]]] = 1;
            }
            for (int j = 1; j <= 4; j++) {
                if (temp[j] == 0) {
                    result[i] = j;
                    break;
                }
            }
            for (int j = 1; j <= 4; j++) {
                temp[j] = 0;
            }
        }

        return result;
    }
};
#endif // NORMAL_METHOD

#endif // __leet_code_1042_h__