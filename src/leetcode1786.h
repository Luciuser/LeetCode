#ifndef __leet_code_1786__
#define __leet_code_1786__

#include<iostream>
#include<vector>
#include<assert.h>

#define VIOLENCE_METHOD // 暴力计算

#ifdef VIOLENCE_METHOD

#endif // VIOLENCE_METHOD

class Solution {
public:

	int min(int a, int b) { return a < b ? a : b; }

	// 二分法插入
	int insertInQu(std::vector<std::pair<int, int>> &qu, std::pair<int, int> &pa) {
		auto pos = std::lower_bound(qu.begin(), qu.end(), pa, [=](std::pair<int, int>a, std::pair<int, int>b) {
			return a.second < b.second;
		});
		qu.insert(pos, pa);
		return 0;
	}

	// 二分法删除
	int deleteInQu(std::vector<std::pair<int, int>> &qu, std::pair<int, int> &pa) {
		auto pos = std::lower_bound(qu.begin(), qu.end(), pa, [=](std::pair<int, int>a, std::pair<int, int>b) {
			return a.second < b.second;
		});

		qu.erase(pos);
		return 0;
	}

	int countRestrictedPaths(int n, std::vector<std::vector<int>>& edges) {

		// 建立图 O(n)
		std::vector<std::vector<int>> graph(n, std::vector<int>(n, -1)); // 图
		std::vector<int> distanceToLastNode(n, -1);	// 到第n个点的最短距离

		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0] - 1;
			int v = edges[i][1] - 1;
			int weight = edges[i][2];
			graph[u][v] = weight;
			graph[v][u] = weight;
		}

		// 构造每个点的 distanceToLastNode
		std::vector<std::pair<int, int>> qu; // 遍历到的节点和对应的最短距离
		qu.push_back(std::pair<int, int>(n - 1, 0));
		distanceToLastNode[n - 1] = 0;
		
		// O(n^2 * logn)
		while (qu.size() != 0) {
			auto node = qu[0];
			int crtNode = node.first;
			int crtDis = node.second;
			for (int i = 0; i < graph[crtNode].size(); i++) {
				if (graph[crtNode][i] != -1) {
					if (distanceToLastNode[i] == -1) {
						// 队列里没有第i个节点，因此新增该节点
						distanceToLastNode[i] = graph[crtNode][i] + distanceToLastNode[crtNode];
						insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));// 新增节点
					}
					else {
						// 队列里已经存在第i个节点，因此比较该节点存储值与新路径的值的大小
						if (graph[crtNode][i] + distanceToLastNode[crtNode] < distanceToLastNode[i]) {
							deleteInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
							distanceToLastNode[i] = graph[crtNode][i] + distanceToLastNode[crtNode];
							insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
						}
					}
				}
			}
			qu.erase(qu.begin());
		}

		// 进行遍历，寻找可能的路径结果
		std::vector<int> isUsed(n, -1); // 判断某个节点是否已经被遍历到
		std::vector<long long> result(n, 0);  // 最终结果
		qu.push_back(std::pair<int, int>(n - 1, 0));
		result[n - 1] = 1;
		while (qu.size() != 0) {
			auto node = qu[0];
			int crtNode = node.first;
			int crtDis = node.second;
			for (int i = 0; i < graph[crtNode].size(); i++) {
				if (graph[crtNode][i] != -1) {
					// 该路径是否能通过
					if (distanceToLastNode[crtNode] < distanceToLastNode[i]) {
						// 能够通过
						if (isUsed[i] == -1) {
							insertInQu(qu, std::pair<int, int>(i, distanceToLastNode[i]));
							isUsed[i] = 1;
						}
						result[i] += result[crtNode];
						if (result[i] >= (1000000007)) {
							result[i] = result[i] % (1000000007);
						}
					}
				}
			}
			qu.erase(qu.begin());
		}


		return result[0];
	}
};

#endif // __leet_code_1786__