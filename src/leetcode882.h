/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-26 10:21:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode882.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-26 11:55:27
 * @Editor: Bingyang Jin
 * @Description: create DIJKSTRA_METHOD, TIME 344ms, 10.94%, MEMORY 42.8MB and 96.35%
 */

 /*
 * @EditTime: 2022-11-26 11:55:27
 * @Editor: Bingyang Jin
 * @Description: create DIJKSTRA_PRIORITY_QUEUE_METHOD, TIME 132ms, 83.33%, MEMORY 43.1MB and 89.58%
 */

#ifndef __leet_code_882__
#define __leet_code_882__

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<math.h>
#include<algorithm>

//#define DIJKSTRA_METHOD // DIJKSTRA ���׷�����O(n^2)��TIME 344ms, 10.94%, MEMORY 42.8MB and 96.35%
#define DIJKSTRA_PRIORITY_QUEUE_METHOD // dijkstra + ���ȶ��У�TIME 132ms, 83.33%, MEMORY 43.1MB and 89.58%

#ifdef DIJKSTRA_METHOD
class Solution {
public:
    int reachableNodes(std::vector<std::vector<int>>& edges, int maxMoves, int n) {
        std::vector<std::vector<std::pair<int, int>>> node(n); // �������¼����ͼ����һ������ʾ���ﶥ�㣬�ڶ�������ʾ���ڵ�֮����ӽڵ���
        for (int i = 0; i < edges.size(); i++) {
            int p1 = edges[i][0];
            int p2 = edges[i][1];
            int cnt = edges[i][2];
            node[p1].push_back(std::pair<int, int>(p2, cnt));
            node[p2].push_back(std::pair<int, int>(p1, cnt));
        }

        // dijkstra ����������Դ���·��
        std::vector<int> dis(n, std::numeric_limits<int>::max()); // �� 0 �ڵ㵽����ڵ������������ٵĽڵ���
        std::vector<int> visit(n, false); // �Ƿ�������ýڵ�
        int crtNode = 0;
        dis[0] = 0;
        for (int i = 0; i < n; i++) {
            visit[crtNode] = true;
            for (int j = 0; j < node[crtNode].size(); j++) {
                int nextNode = node[crtNode][j].first;
                int length = node[crtNode][j].second + dis[crtNode] + 1;
                if (length < dis[nextNode] && length <= maxMoves) {
                    dis[nextNode] = length;
                }
            }

            int next_min = crtNode;
            int next_min_length = std::numeric_limits<int>::max();
            for (int j = 0; j < n; j++) {
                if (visit[j] == false && dis[j] < next_min_length && dis[j] <= maxMoves) {
                    next_min = j;
                    next_min_length = dis[j];
                }
            }
            if (next_min == crtNode) {
                break;
            }

            crtNode = next_min;
        }

        // �������·���������ܵ���Ľڵ���
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] <= maxMoves) {
                sum++;
            }
        }
        // �������·��������ÿ���ߵ��ӽڵ��ܴﵽ������
        for (int i = 0; i < edges.size(); i++) {
            int p1 = edges[i][0];
            int p2 = edges[i][1];
            int cnt = edges[i][2];

            if (dis[p1] > maxMoves && dis[p2] > maxMoves) {
                continue;
            }

            int temp = 0;
            if (dis[p1] < maxMoves) {
                temp += maxMoves - dis[p1];
            }
            if (dis[p2] < maxMoves) {
                temp += maxMoves - dis[p2];
            }
            if (temp > cnt) {
                temp = cnt;
            }
            sum += temp;
        }

        return sum;
    }
};
#endif // DIJKSTRA_METHOD

#ifdef DIJKSTRA_PRIORITY_QUEUE_METHOD
class Solution {
public:

    // Dijkstra �㷨ģ��
    // ���ش� start ��ÿ��������·
    std::vector<int> dijkstra(std::vector<std::vector<std::pair<int, int>>>& g, int start) {
        std::vector<int> dist(g.size(), INT_MAX);
        dist[start] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto [d, x] = pq.top();
            pq.pop();
            if (d > dist[x]) continue;
            for (auto [y, wt] : g[x]) {
                int new_d = dist[x] + wt;
                if (new_d < dist[y]) {
                    dist[y] = new_d;
                    pq.emplace(new_d, y);
                }
            }
        }
        return dist;
    }

    int reachableNodes(std::vector<std::vector<int>>& edges, int maxMoves, int n) {
        std::vector<std::vector<std::pair<int, int>>> g(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            g[u].emplace_back(v, cnt + 1);
            g[v].emplace_back(u, cnt + 1); // ��ͼ
        }

        auto dist = dijkstra(g, 0); // �� 0 ���������·

        int ans = 0;
        for (int d : dist)
            if (d <= maxMoves) // ���������� maxMoves ���ڵ���
                ++ans;
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = std::max(maxMoves - dist[u], 0);
            int b = std::max(maxMoves - dist[v], 0);
            ans += std::min(a + b, cnt); // �������Ͽ��Ե���Ľڵ���
        }
        return ans;
    }
};
#endif // DIJKSTRA_PRIORITY_QUEUE_METHOD

#endif // __leet_code_882__