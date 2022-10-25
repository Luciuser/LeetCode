/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-25 08:50:32
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode934.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-25 09:36:20
 * @Editor: Bingyang Jin
 * @Description: create DFS_BFS_METHOD, TIME 40ms, 50.98%, MEMORY 17.8MB and 94.13%
 */

#ifndef __leet_code_934__
#define __leet_code_934__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:

	// ������һ��С��������1ȫ�����2
	int dfsTo2(std::vector<std::vector<int>>& grid, std::pair<int, int>position, std::queue<std::pair<int, int>> &boundary) {
		// ���ݸ�λ�õ�������д���
		if (grid[position.first][position.second] == 1) {
			// С������������ݹ�
			grid[position.first][position.second] = 2;

			for (int i = 0; i < 4; i++) {
				int x = position.first + next[i][0];
				int y = position.second + next[i][1];
				if (0 <= x && x < grid.size() && 0 <= y && y < grid.size()) {
					dfsTo2(grid, std::pair<int, int>(x, y), boundary);
				}
			}
		}
		else if (grid[position.first][position.second] == 0) {
			// ˮ�����������߽磬��ֹͣ�õ�����ݹ�
			grid[position.first][position.second] = -1;
			boundary.push(position);
		}
		
		return 0;
	}

	int shortestBridge(std::vector<std::vector<int>>& grid) {

		int n = grid.size();
		std::queue<std::pair<int, int>> boundary; // С�� 2 �ı߽�λ��
		// ������һ��С��������1ȫ�����2
		bool find = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					dfsTo2(grid, std::pair<int, int>(i, j), boundary);
					find = true;
					break;
				}
			}
			if (find) {
				break;
			}
		}

		// �ӱ߽�λ�ý��� bfs��һ�������µ�С���ͽ���
		int result = 1;
		int queSIze = boundary.size();
		while (true) {
			if (queSIze == 0) {
				// bfs ������һ��
				queSIze = boundary.size();
				result++;
			}

			if (boundary.size() == 0) {
				break;
			}

			std::pair<int, int>position = boundary.front();
			boundary.pop();
			queSIze--;

			// ��ʼ����
			for (int i = 0; i < 4; i++) {
				int x = position.first + next[i][0];
				int y = position.second + next[i][1];
				if (0 <= x && x < n && 0 <= y && y < n && (grid[x][y] == 0 || grid[x][y] == 1)) {
					// ����С��1��ֱ������
					if (grid[x][y] == 1) {
						return result;
					}
					grid[x][y] = -1;
					boundary.emplace(std::pair<int, int>(x, y));
				}
			}
		}

		return result;
	}

private:
	std::vector<std::vector<int>>next = { {-1,0},{1,0},{0,-1},{0,1} };
};

#endif // __leet_code_934__