/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-19 11:13:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1971.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-19 11:08:55
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, OUT OF TIME
 */

 /*
 * @EditTime: 2022-12-19 13:47:10
 * @Editor: Bingyang Jin
 * @Description: create DISJOINT_SET_UNION_METHOD, TIME 332ms, 65.01%, MEMORY 108.4MB and 62.72%
 */

#ifndef __leet_code_1971__
#define __leet_code_1971__

#include<iostream>
#include<vector>

//#define DFS_METHOD // DFS方法，会超时
#define DISJOINT_SET_UNION_METHOD // 并查集, TIME 332ms, 65.01%, MEMORY 108.4MB and 62.72%

#ifdef DFS_METHOD
class Solution {
public:

	bool dfs(std::vector<std::vector<int>> &edges, int source, int destination) {
		if (source == destination) {
			return true;
		}
		flag[source] = 0;
		for (int i = 0; i < edges.size(); i++) {
			if (edges[source][i] == 1 && flag[i] == 1) {
				bool success = dfs(edges, i, destination);
				if (success == true) {
					return true;
				}
			}
		}

		return false;
	}

	bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
		std::vector<std::vector<int>> e(n, std::vector<int>(n, 0));
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			e[u][v] = 1;
			e[v][u] = 1;
		}
		flag = std::vector<int>(n, 1); // 标记该节点是否已经访问过

		return dfs(e, source, destination);
	}

private:
	std::vector<int>flag;
};
#endif // DFS_METHOD

#ifdef DISJOINT_SET_UNION_METHOD
class Solution {
public:

	int find(int index) {
		if (data[index] == index) {
			return index;
		}
		return find(data[index]);
	}

	bool data_union(int a, int b) {
		int a_root = find(a);
		int b_root = find(b);
		if (a_root != b_root) {
			data[a_root] = b_root;
		}
		return true;
	}

	bool validPath(int n, std::vector<std::vector<int>>& edges, int source, int destination) {
		data = std::vector<int>(n);
		for (int i = 0; i < n; i++) {
			data[i] = i;
		}

		for (int i = 0; i < edges.size(); i++) {
			data_union(edges[i][0], edges[i][1]);
		}

		if (find(source) == find(destination)) {
			return true;
		}

		return false;
	}

private:
	std::vector<int> data;
};
#endif // DISJOINT_SET_UNION_METHOD


#endif // __leet_code_1971__