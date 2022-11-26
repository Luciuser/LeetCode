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

//#define DIJKSTRA_METHOD // DIJKSTRA 简易方法，O(n^2)，TIME 344ms, 10.94%, MEMORY 42.8MB and 96.35%
#define DIJKSTRA_PRIORITY_QUEUE_METHOD // dijkstra + 优先队列，TIME 132ms, 83.33%, MEMORY 43.1MB and 89.58%

#ifdef DIJKSTRA_METHOD
class Solution {
public:
    int reachableNodes(std::vector<std::vector<int>>& edges, int maxMoves, int n) {
        std::vector<std::vector<std::pair<int, int>>> node(n); // 用数组记录无向图，第一个数表示到达顶点，第二个数表示两节点之间的子节点数
        for (int i = 0; i < edges.size(); i++) {
            int p1 = edges[i][0];
            int p2 = edges[i][1];
            int cnt = edges[i][2];
            node[p1].push_back(std::pair<int, int>(p2, cnt));
            node[p2].push_back(std::pair<int, int>(p1, cnt));
        }

        // dijkstra 方案求无向单源最短路径
        std::vector<int> dis(n, std::numeric_limits<int>::max()); // 从 0 节点到任意节点所经过的最少的节点数
        std::vector<int> visit(n, false); // 是否遍历到该节点
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

        // 根据最短路径，计算能到达的节点数
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (dis[i] <= maxMoves) {
                sum++;
            }
        }
        // 根据最短路径，计算每条边的子节点能达到的数量
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

    // Dijkstra 算法模板
    // 返回从 start 到每个点的最短路
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
            g[v].emplace_back(u, cnt + 1); // 建图
        }

        auto dist = dijkstra(g, 0); // 从 0 出发的最短路

        int ans = 0;
        for (int d : dist)
            if (d <= maxMoves) // 这个点可以在 maxMoves 步内到达
                ++ans;
        for (auto& e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            int a = std::max(maxMoves - dist[u], 0);
            int b = std::max(maxMoves - dist[v], 0);
            ans += std::min(a + b, cnt); // 这条边上可以到达的节点数
        }
        return ans;
    }
};
#endif // DIJKSTRA_PRIORITY_QUEUE_METHOD

#endif // __leet_code_882__