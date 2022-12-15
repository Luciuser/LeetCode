/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-14 13:56:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1697.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-15 13:46:16
 * @Editor: Bingyang Jin
 * @Description: create FLOYD_METHOD, OUT OF TIME
 */

 /*
 * @EditTime: 2022-12-15 14:02:01
 * @Editor: Bingyang Jin
 * @Description: create DSU_METHOD, OUT OF TIME
 */

 /*
 * @EditTime: 2022-12-15 14:02:01
 * @Editor: Bingyang Jin
 * @Description: create DSU_METHOD, TIME 460ms, 88.93%, MEMORY 107.6MB and 76.55%
 */

#ifndef __leet_code_1697__
#define __leet_code_1697__

#include<iostream>
#include<vector>
#include<algorithm>

//#define FLOYD_METHOD // folyd算法，会超时
#define DSU_METHOD // 并查集算法，会超时
#define ANSWER_DSU_METHOD // 题解并查集算法，TIME 460ms, 88.93%, MEMORY 107.6MB and 76.55%

#ifdef FLOYD_METHOD
class Solution {
public:
    std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList, std::vector<std::vector<int>>& queries) {
        // 构建floyd初始矩阵
        std::vector<std::vector<int>> floyd(n, std::vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            floyd[i][i] = 0;
        }
        for (int i = 0; i < edgeList.size(); i++) {
            int u = edgeList[i][0];
            int v = edgeList[i][1];
            int l = edgeList[i][2];
            if (floyd[u][v] > l || floyd[u][v] == -1) {
                floyd[u][v] = l;
                floyd[v][u] = l;
            }
        }

        // 计算floyd矩阵
        for (int k = 0; k < n; k++) {
            for (int x = 0; x < n; x++) {
                if (x == k || floyd[x][k] == -1) {
                    continue;
                }
                for (int y = 0; y < n; y++) {
                    if (y == k || floyd[k][y] == -1) {
                        continue;
                    }
                    int temp = floyd[x][k] > floyd[k][y] ? floyd[x][k] : floyd[k][y];
                    if (floyd[x][y] == -1 || floyd[x][y] > temp) {
                        floyd[x][y] = temp;
                    }
                }
            }
        }

        std::vector<bool> result(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int l = queries[i][2];
            if (l > floyd[x][y] && floyd[x][y] != -1) {
                result[i] = true;
            }
        }

        return result;
    }
};
#endif // FLOYD_METHOD

#ifdef DSU_METHOD
class Solution {
public:
    std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList, std::vector<std::vector<int>>& queries) {
        // 按从小到大的顺序对edgeList和queries进行排序，以方便并查集进行处理
        std::sort(edgeList.begin(), edgeList.end(), [=](std::vector<int>& a, std::vector<int>& b) {
            return a[2] < b[2];
        });
        std::vector<int> q(queries.size());
        for (int i = 0; i < q.size(); i++) {
            q[i] = i;
        }
        std::sort(q.begin(), q.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });

        // 初始情况，每个节点都是单独的
        data.resize(n);
        for (int i = 0; i < n; i++) {
            data[i] = i;
        }

        std::vector<bool>result(q.size(), false);
        int ei = 0;
        for (int i = 0; i < q.size(); i++) {
            int index = q[i];
            if (ei < edgeList.size()) {
                while (edgeList[ei][2] < queries[index][2]) {
                    unionInData(edgeList[ei][0], edgeList[ei][1]);
                    ei++;
                    if (ei >= edgeList.size()) {
                        break;
                    }
                }
            }

            if (find(queries[index][0]) == find(queries[index][1])) {
                result[index] = true;
            }
        }

        return result;
    }
private:

    int find(int val) {
        if (data[val] == val) {
            return val;
        }
        return find(data[val]);
    }

    void unionInData(int val) {

    }
    void unionInData(int u, int v) {
        int u_root = find(u);
        int v_root = find(v);
        if (u_root != v_root) {
            data[u_root] = v_root;
        }
    }

    std::vector<int> data;
};
#endif // DSU_METHOD

#ifdef ANSWER_DSU_METHOD
class Solution {
public:
    std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>>& edgeList, std::vector<std::vector<int>>& queries) {
        // 按从小到大的顺序对edgeList和queries进行排序，以方便并查集进行处理
        std::sort(edgeList.begin(), edgeList.end(), [=](std::vector<int>& a, std::vector<int>& b) {
            return a[2] < b[2];
        });
        std::vector<int> q(queries.size());
        for (int i = 0; i < q.size(); i++) {
            q[i] = i;
        }
        std::sort(q.begin(), q.end(), [&](int a, int b) {
            return queries[a][2] < queries[b][2];
        });

        // 初始情况，每个节点都是单独的
        data.resize(n);
        for (int i = 0; i < n; i++) {
            data[i] = i;
        }

        std::vector<bool>result(q.size(), false);
        int ei = 0;
        for (int i = 0; i < q.size(); i++) {
            int index = q[i];
            if (ei < edgeList.size()) {
                while (edgeList[ei][2] < queries[index][2]) {
                    unionInData(edgeList[ei][0], edgeList[ei][1]);
                    ei++;
                    if (ei >= edgeList.size()) {
                        break;
                    }
                }
            }

            if (find(queries[index][0]) == find(queries[index][1])) {
                result[index] = true;
            }
        }

        return result;
    }
private:

    int find(int val) {
        if (data[val] == val) {
            return val;
        }
        return find(data[val]);
    }

    void unionInData(int val) {

    }
    void unionInData(int u, int v) {
        int u_root = find(u);
        int v_root = find(v);
        if (u_root != v_root) {
            data[u_root] = v_root;
        }
    }

    std::vector<int> data;
};
#endif // ANSWER_DSU_METHOD

#endif // __leet_code_1697__