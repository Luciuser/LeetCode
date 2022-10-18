/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-16 12:27:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode886.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-16 13:18:26
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 664ms, 5.24%, MEMORY 79.9MB and 5.07%
 */

 /*
 * @EditTime: 2022-10-18 10:34:19
 * @Editor: Bingyang Jin
 * @Description: create DISJOINT_SET_UNION, TIME 236ms, 8.91%, MEMORY 62.8MB and 77.91%
 */

#ifndef __leet_code_886__
#define __leet_code_886__

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

//#define GREEDY_METHOD // 贪心法，每次都尝试判断该点不友好的点是否能成功，TIME 664ms, 5.24%, MEMORY 79.9MB and 5.07%
//#define DFS_METHOD // 深搜，是基于上述贪心法的改进，TIME 244ms, 10.10%, MEMORY 62.9MB and 82.67%
#define DISJOINT_SET_UNION // 并查集，TIME 236ms, 8.91%, MEMORY 62.8MB and 77.91%

#ifdef GREEDY_METHOD
struct SimplePairHash {
	std::size_t operator()(const std::pair<int, int>& p) const {
		return p.first ^ p.second;
	}
};

class Solution {
public:
	bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {

		std::vector<int> group1;
		std::vector<int> group2;

		std::unordered_set<std::pair<int, int>, SimplePairHash> dislikeSet;
		for (int i = 0; i < dislikes.size(); i++) {
			dislikeSet.emplace(std::pair<int, int>(dislikes[i][0], dislikes[i][1]));
		}

		//for (int i = 1; i <= n; i++) {
		//	bool temp = false;

		//}

		std::unordered_map<int, std::vector<int>> dislikeMap;
		for (int i = 0; i < dislikes.size(); i++) {
			dislikeMap[dislikes[i][0]].push_back(dislikes[i][1]);
			dislikeMap[dislikes[i][1]].push_back(dislikes[i][0]);
		}
		std::unordered_set<int> used;

		for (int i = 1; i <= n; i++) {
			if (used.count(i) == 0) {
				used.emplace(i);
				std::vector<int> temp = dislikeMap[i];
				for (int j = 0; j < temp.size(); j++) {
					used.emplace(temp[j]);
				}
				while (temp.size() > 0) {
					std::vector<int> next;
					for (int j = 0; j < temp.size(); j++) {
						for (int k = j + 1; k < temp.size(); k++) {
							if (dislikeSet.count(std::pair<int, int>(temp[j], temp[k])) != 0) {
								return false;
							}
						}
					}
					for (int j = 0; j < temp.size(); j++) {
						for (int k = 0; k < dislikeMap[temp[j]].size(); k++) {
							if (used.count(dislikeMap[temp[j]][k]) == 0) {
								next.push_back(dislikeMap[temp[j]][k]);
								used.emplace(dislikeMap[temp[j]][k]);
							}
						}
					}
					temp = next;
				}
			}
		}

		return true;
	}
};
#endif // GREEDY_METHOD

#ifdef DFS_METHOD
class Solution {
public:

	bool dfs(int index, int crtGroup) {
		group[index] = crtGroup;
		for (int i = 0; i < pairs[index].size(); i++) {
			int person = pairs[index][i];
			if (group[person] > 0 && group[person] == crtGroup) {
				return false;
			}
			if (group[person] == 0) {
				int nxtGroup = crtGroup == 1 ? 2 : 1;
				if (!dfs(person, nxtGroup)) {
					return false;
				}
			}
		}
		return true;
	}

	bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {

		group = std::vector<int>(n + 1, 0);
		pairs = std::vector<std::vector<int>>(n + 1);
		for (int i = 0; i < dislikes.size(); i++) {
			pairs[dislikes[i][0]].push_back(dislikes[i][1]);
			pairs[dislikes[i][1]].push_back(dislikes[i][0]);
		}
		
		for (int i = 1; i <= n; i++) {
			if (group[i] == 0) {
				if (!dfs(i, 1)) {
					return false;
				}
			}
		}

		return true;
	}

private:
	std::vector<std::vector<int>> pairs;
	std::vector<int> group;
};
#endif // DFS_METHOD

#ifdef DISJOINT_SET_UNION
class Solution {
public:

	int find(int x) {
		return group[x] == -1 ? x : find(group[x]);
	}

	void merge(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		if (rootx == rooty) {
			return;
		}
		group[rooty] = rootx;
	}

	bool isConnect(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		return rootx == rooty;
	}

	bool possibleBipartition(int n, std::vector<std::vector<int>>& dislikes) {

		group = std::vector<int>(n + 1, -1);
		pairs = std::vector<std::vector<int>>(n + 1);
		for (int i = 0; i < dislikes.size(); i++) {
			pairs[dislikes[i][0]].push_back(dislikes[i][1]);
			pairs[dislikes[i][1]].push_back(dislikes[i][0]);
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < pairs[i].size(); j++) {
				merge(pairs[i][0], pairs[i][j]);
				if (isConnect(i, pairs[i][j])) {
					return false;
				}
			}
		}

		return true;
	}

private:
	std::vector<std::vector<int>> pairs;
	std::vector<int> group;
};
#endif // DISJOINT_SET_UNION


#endif // __leet_code_886__