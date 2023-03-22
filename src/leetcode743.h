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
        std::unordered_map<int, std::vector<std::pair<int, int>>> edge; // ÿ����ÿ���������ӵ������㼰��ߵ�value��pair Ϊ [�յ㣬value]
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyPair> q; // �洢��ǰ��̱ߵĽڵ㣬pair Ϊ [�յ㣬value]

        // װ������
        for (int i = 0; i < times.size(); i++) {
            int begin = times[i][0];
            int end = times[i][1];
            int value = times[i][2];
            edge[begin].push_back(std::pair<int, int>(end, value));
        }

        // ��Դ�ڵ㿪ʼ�����г�ʼ��
        std::unordered_set<int> nodes_receive; // �յ��źŵĽڵ�
        nodes_receive.emplace(k);
        for (int i = 0; i < edge[k].size(); i++) {
            q.emplace(edge[k][i]);
        }

        // ÿ��װ�������һ���ڵ�
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