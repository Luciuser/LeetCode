#ifndef __leet_code_1162__
#define __leet_code_1162__

#include<iostream>
#include<vector>
#include<queue>

//#define VIOLENCE_METHODS // 暴力 bfs 寻找结果
#define MEMORY_METHODS // 记忆化 bfs

#ifdef VIOLENCE_METHODS
class Solution {
public:

	int max(int a, int b) { return a > b ? a : b; }

	int maxDistance(std::vector<std::vector<int>>& grid) {

		int maxResult = -1;
		int n = grid.size();

		bool allSea = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					allSea = false;
					break;
				}
			}
			if (allSea == false) {
				break;
			}
		}
		if (allSea) { return -1; }

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) {
					// 海洋
					std::vector<std::vector<int>> temp(n, std::vector<int>(n, -1)); // 每个地区是否被遍历过

					std::queue<std::pair<int, int>> seed;
					seed.push(std::pair<int, int>(i, j));

					int a, b;
					bool isFind = false;
					while (seed.size() != 0) {
						auto p = seed.front();
						seed.pop();
						a = p.first;
						b = p.second;

						if (grid[a][b] == 1) {
							isFind = true;
							break;
						}

						// up
						if (a > 0) {
							if (temp[a - 1][b] == -1) {
								seed.push(std::pair<int, int>(a - 1, b));
								temp[a - 1][b] = 0;
							}
						}
						// left
						if (b > 0) {
							if (temp[a][b - 1] == -1) {
								seed.push(std::pair<int, int>(a, b - 1));
								temp[a][b - 1] = 0;
							}
						}
						// down
						if (a < n - 1) {
							if (temp[a + 1][b] == -1) {
								seed.push(std::pair<int, int>(a + 1, b));
								temp[a + 1][b] = 0;
							}
						}
						// right
						if (b < n - 1) {
							if (temp[a][b + 1] == -1) {
								seed.push(std::pair<int, int>(a, b + 1));
								temp[a][b + 1] = 0;
							}
						}
					}
					if (isFind) {
						maxResult = max(maxResult, (abs(a - i) + abs(b - j)));
					}
				}
			}
		}

		return maxResult;
	}
};
#endif // VIOLENCE_METHODS

#ifdef MEMORY_METHODS

class Solution {
public:

	int max(int a, int b) { return a > b ? a : b; }
	int min(int a, int b) { return a < b ? a : b; }

	int maxDistance(std::vector<std::vector<int>>& grid) {

		int maxResult = -1;
		int n = grid.size();

		bool allSea = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					allSea = false;
					break;
				}
			}
			if (allSea == false) {
				break;
			}
		}
		if (allSea) { return -1; }

		std::vector<std::vector<int>> result(n, std::vector<int>(n, -1)); // 每个地区距离最近的陆地的距离

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (result[i][j] != -1) {
					continue;
				}
				if (grid[i][j] == 0) {

					// 海洋
					std::vector<std::vector<int>> temp(n, std::vector<int>(n, -1)); // 每个地区是否被遍历过
					temp[i][j] = 0;

					std::queue<std::pair<int, int>> seed;
					std::vector<std::pair<int, int>> nextSeeds;
					seed.push(std::pair<int, int>(i, j));

					int a, b;
					bool isFind = false;
					int t = std::numeric_limits<int>::max();
					while (seed.size() != 0 || nextSeeds.size() != 0) {
						while (seed.size() != 0) {
							auto p = seed.front();
							seed.pop();
							a = p.first;
							b = p.second;

							if (grid[a][b] == 1) {
								result[a][b] = 0;
							}

							if (result[a][b] != -1) {
								t = min(t, result[a][b] + abs(i - a) + abs(j - b));
								isFind = true;
								continue;
							}

							// up
							if (a > 0) {
								if (temp[a - 1][b] == -1) {
									nextSeeds.push_back(std::pair<int, int>(a - 1, b));
									temp[a - 1][b] = 0;
								}
							}
							// left
							if (b > 0) {
								if (temp[a][b - 1] == -1) {
									nextSeeds.push_back(std::pair<int, int>(a, b - 1));
									temp[a][b - 1] = 0;
								}
							}
							// down
							if (a < n - 1) {
								if (temp[a + 1][b] == -1) {
									nextSeeds.push_back(std::pair<int, int>(a + 1, b));
									temp[a + 1][b] = 0;
								}
							}
							// right
							if (b < n - 1) {
								if (temp[a][b + 1] == -1) {
									nextSeeds.push_back(std::pair<int, int>(a, b + 1));
									temp[a][b + 1] = 0;
								}
							}
						}
						//if (isFind) {
						//	result[i][j] = t;
						//	maxResult = max(maxResult, result[i][j]);
						//	break;
						//}
						//else {
							for (int k = 0; k < nextSeeds.size(); k++) {
								seed.push(nextSeeds[k]);
							}
							nextSeeds.clear();
						//}
					}

					result[i][j] = t;
					maxResult = max(maxResult, result[i][j]);
				}
				else if(grid[i][j] == 1){
					result[i][j] = 0;
				}
			}
		}

		//std::cout << std::endl;
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		std::cout << result[i][j] << " ";
		//	}
		//	std::cout << std::endl;
		//}

		return maxResult;
	}
};
#endif // MEMORY_METHODS



#endif // __leet_code_1162__