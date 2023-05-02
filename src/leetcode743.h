/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-18 18:42:55
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode743.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 19:44:18
 * @Editor: Bingyang Jin
 * @Description: create DIJKSTRA_METHOD, TIME 88ms, 86.66%, MEMORY 41.1MB and 18.26%
 */

#ifndef __leet_code_743_h__
#define __leet_code_743_h__

#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<vector>

class Solution {
public:

    struct MyPair {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a.second > b.second;
        }
    };

    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        std::unordered_map<int, std::vector<std::pair<int, int>>> edge; // 每个与每个点相连接的其他点及其边的value，pair 为 [终点，value]
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyPair> q; // 存储当前最短边的节点，pair 为 [终点，value]

        // 装载链表
        for (int i = 0; i < times.size(); i++) {
            int begin = times[i][0];
            int end = times[i][1];
            int value = times[i][2];
            edge[begin].push_back(std::pair<int, int>(end, value));
        }

        // 从源节点开始，进行初始化
        std::unordered_set<int> nodes_receive; // 收到信号的节点
        nodes_receive.emplace(k);
        for (int i = 0; i < edge[k].size(); i++) {
            q.emplace(edge[k][i]);
        }

        // 每次装载最近的一个节点
        int sum = 0;
        while (true) {
            if (q.size() == 0) {
                break;
            }

            auto pair_temp = q.top();
            q.pop();
            int end = pair_temp.first;

            if (nodes_receive.count(end) == 0) {
                nodes_receive.emplace(end);
                int value = pair_temp.second;
                if (nodes_receive.size() == n) {
                    return value;
                }

                for (int i = 0; i < edge[end].size(); i++) {
                    q.emplace(std::pair<int, int>(edge[end][i].first, edge[end][i].second + value));
                }
            }
        }

        return -1;
    }
};

#endif // __leet_code_743_h__