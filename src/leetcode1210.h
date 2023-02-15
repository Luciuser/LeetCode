/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-15 13:37:47
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1210.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-15 14:51:10
 * @Editor: Bingyang Jin
 * @Description: create BFS_METHOD, TIME 64ms, 12.28%, MEMORY 24.7MB and 8.54%
 */

 /*
 * @EditTime: 2023-02-15 15:50:37
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 116ms, 5.52%, MEMORY 20.7MB and 16.93%
 */

#ifndef __leet_code_1210_h__
#define __leet_code_1210_h__

#include<iostream>
#include<queue>
#include<vector>

//#define MORE_COMPLICATE_METHOD // 题意中只能向右向下，此代码为可上下左右同步进行
//#define BFS_METHOD // BFS 法，TIME 64ms, 12.28%, MEMORY 24.7MB and 8.54%
#define DYNAMIC_PROGRAMMING_METHOD // 动态规划法

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {

private:
	// 判断位置和姿态 x y k 对于 grid 数组是否有效
	bool isPositionValid(std::vector<std::vector<int>> const &grid, int x, int y, int k) {
		if (x < grid.size() && y < grid.size() && // 尾部索引有效 
			grid[x][y] == 0 // 尾部不存在障碍
			) {
			if ((k == 0 && y + 1 < grid.size() && grid[x][y + 1] == 0) || // 横向姿态下，头部有效
				(k == 1 && x + 1 < grid.size() && grid[x + 1][y] == 0) // 纵向姿态下，头部有效
				) {
				return true;
			}
		}
		return false;
	}
	
	// 判断当前有效位置和姿态 x y k 在 grid 数组下进行旋转，该旋转操作是否有效
	bool isRotateValid(std::vector<std::vector<int>> const &grid, int x, int y, int k) {
		if (x + 1 < grid.size() && y + 1< grid.size()	) { 
			// 头部空间有效 
			if (grid[x + 1][y + 1] == 0) { 
				// 额外空间有效
				if ((k == 0 && grid[x + 1][y] == 0) || (k == 1 && grid[x][y + 1] == 0)) {
					// 旋转后的空间有效
					return true;
				}
			}
		}
		return false;
	}

	// 通过旋转尝试进行更新
	void renewByRotate(std::vector<std::vector<int>> const &grid, std::vector<std::vector<std::vector<int>>> &dp, int i, int j) {
		if (dp[i][j][0] == -1 && dp[i][j][1] == -1) {
			// 两种姿态均无法得到，则直接跳过
			return;
		}
		else if (dp[i][j][0] == -1) {
			// 一种姿态无法得到，尝试进行姿态转换
			if (isRotateValid(grid, i, j, 1)) {
				dp[i][j][0] = dp[i][j][1] + 1;
			}
		}
		else if (dp[i][j][1] == -1) {
			// 一种姿态无法得到，尝试进行姿态转换
			if (isRotateValid(grid, i, j, 0)) {
				dp[i][j][1] = dp[i][j][0] + 1;
			}
		}
		else {
			// 两种姿态均可以得到，但较大的值可尝试进行旋转，改为较小值+1
			if (dp[i][j][1] > dp[i][j][0] + 1 && isRotateValid(grid, i, j, 0)) {
				dp[i][j][1] = dp[i][j][0] + 1;
			}
			else if (dp[i][j][0] > dp[i][j][1] + 1 && isRotateValid(grid, i, j, 1)) {
				dp[i][j][0] = dp[i][j][1] + 1;
			}
		}
	}

public:
	int minimumMoves(std::vector<std::vector<int>>& grid) {

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid.size(); j++) {
				std::cout << grid[i][j] << " ";
			}
			std::cout << std::endl;
		}

		// 动态规划，令 dp[i][j][k] 表示蛇的尾巴在 (i, j) 位置，且姿态为 k 时的最小步数，其中 k = 0 表示横向，k = 1 表示纵向
		// 初始条件为：dp[0][0][0] = 0
		// 当蛇旋转时，满足 dp[i][j][k] = dp[i][j][1-k]+1
		// 当蛇向右时，满足 dp[i][j+1][k] = dp[i][j][k]+1
		// 当蛇向右时，满足 dp[i+1][j][k] = dp[i][j][k]+1
		// 根据上式进行动态规划

		int n = grid.size();

		std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>(2, -1)));
		// 初始化
		// 初始第一行第一个
		dp[0][0][0] = 0;
		if (isRotateValid(grid, 0, 0, 0)) {
			dp[0][0][1] = 1;
		}
		// 初始化第一行
		for (int i = 1; i < n; i++) {
			for (int k = 0; k < 2; k++) {
				if (dp[0][i - 1][k] != -1 && isPositionValid(grid, 0, i, k)) {
					dp[0][i][k] = dp[0][i - 1][k] + 1;
				}
			}
			renewByRotate(grid, dp, 0, i);
		}
		// 初始化第一列
		for (int i = 1; i < n; i++){
			for (int k = 0; k < 2; k++) {
				if (dp[i - 1][0][k] != -1 && isPositionValid(grid, i, 0, k)) {
					dp[i][0][k] = dp[i - 1][0][k] + 1;
				}
			}
			renewByRotate(grid, dp, i, 0);
		}

		// 剩余的部分进行动态规划 
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				// 每个状态都可以由上方的一个状态或者左侧的一个状态转移而来
				for (int k = 0; k < 2; k++) {
					if (isPositionValid(grid, i, j, k)) {
						if (dp[i - 1][j][k] != -1) {
							dp[i][j][k] = dp[i - 1][j][k] + 1;
						}
						if (dp[i][j - 1][k] != -1) {
							if (dp[i][j][k] == -1) {
								dp[i][j][k] = dp[i][j - 1][k] + 1;
							}
							else {
								dp[i][j][k] = std::min(dp[i][j][k], dp[i][j - 1][k] + 1);
							}
						}
					}
				}
				renewByRotate(grid, dp, i, j);
			}
		}

		return dp[n - 1][n - 2][0];
	}
};
#endif // DYNAMIC_PROGRAMMING_METHOD

#ifdef BFS_METHOD
class Solution {
public:
	int minimumMoves(std::vector<std::vector<int>>& grid) {

		//for (int i = 0; i < grid.size(); i++) {
		//	for (int j = 0; j < grid.size(); j++) {
		//		std::cout << grid[i][j] << " ";
		//	}
		//	std::cout << std::endl;
		//}

		int n = grid.size();
		std::vector<std::vector<int>> index_move_change = {{0,1},{1,0} }; // 向右下移动时，x 和 y 的变化
		std::vector<std::vector<int>> index_k_change = { {0,1},{1,0} }; // 对于不同 k ，蛇头相对于蛇尾 x 和 y 的变化
		// BFS 方法
		std::vector<std::vector<std::vector<int>>> valid(n, std::vector<std::vector<int>>(n, std::vector<int>(2, 1))); // 该网格姿态是否已经 bfs 到了
		std::queue<Position*> q;
		Position *begin = new Position(0, 0, 0);
		q.emplace(begin);

		int min = 0;
		while (true) {
			int size = q.size();
			if (size == 0) {
				break;
			}
			while (true) {
				if (size == 0) {
					break;
				}
				Position* current_position = q.front();
				int x = current_position->x_;
				int y = current_position->y_;
				int k = current_position->k_;
				if (x == n - 1 && y == n - 2 && k == 0) {
					return min;
				}
				q.pop();
				// 向上下左右四个方向前进
				for (int i = 0; i < 2; i++) {
					int tail_x = x + index_move_change[i][0]; // 新的尾部坐标
					int tail_y = y + index_move_change[i][1];
					int head_x = tail_x + index_k_change[k][0]; // 新的头部坐标
					int head_y = tail_y + index_k_change[k][1];
					if (0 <= tail_x && tail_x < n && 0 <= tail_y && tail_y < n // 新尾部坐标的有效性
						&& 0 <= head_x && head_x < n && 0 <= head_y && head_y < n // 新头部坐标的有效性
						&& valid[tail_x][tail_y][k] == 1 // 单元格是否已经被遍历过
						&& grid[tail_x][tail_y] == 0 && grid[head_x][head_y] == 0 // 移动后的单元格不能是障碍
						) {
						valid[tail_x][tail_y][k] = 0;
						Position *new_position = new Position(tail_x, tail_y, k);
						q.emplace(new_position);
					}
				}
				// 方向改变
				if (0 <= x && x < n - 1 && 0 <= y && y < n - 1 // 新坐标的有效性
					&& valid[x][y][1 - k] == 1 // 单元格是否已经被遍历过
					&& grid[x][y + 1] == 0 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 // 改变方向后的单元格不能是障碍
					) {
					valid[x][y][1 - k] = 0;
					Position *new_position = new Position(x, y, 1 - k);
					q.emplace(new_position);
				}

				size--;
			}
			min++;
		}

		return -1;
	}
private:
	class Position {
	public:
		Position(int x, int y, int k) {
			x_ = x;
			y_ = y;
			k_ = k;
		}

		int x_; // 尾巴的 x 坐标
		int y_; // 尾巴的 y 坐标
		int k_; // 姿态坐标，0 表示横向，1 表示纵向
	};
};
#endif // BFS_METHOD

#ifdef MORE_COMPLICATE_METHOD
class Solution {
public:
	int minimumMoves(std::vector<std::vector<int>>& grid) {

		int n = grid.size();
		std::vector<std::vector<int>> index_move_change = { {0,-1},{0,1},{-1,0},{1,0} }; // 向上下左右移动时，x 和 y 的变化
		std::vector<std::vector<int>> index_k_change = { {0,1},{1,0} }; // 对于不同 k ，蛇头相对于蛇尾 x 和 y 的变化
		// BFS 方法
		std::vector<std::vector<std::vector<int>>> valid(n, std::vector<std::vector<int>>(n, std::vector<int>(2, 1))); // 该网格姿态是否已经 bfs 到了
		std::queue<Position*> q;
		Position *begin = new Position(0, 0, 0);
		q.emplace(begin);

		int min = 0;
		while (true) {
			int size = q.size();
			if (size == 0) {
				break;
			}
			while (true) {
				if (size == 0) {
					break;
				}
				Position* current_position = q.front();
				int x = current_position->x_;
				int y = current_position->y_;
				int k = current_position->k_;
				if (x == n - 1 && y == n - 2 && k == 0) {
					return min;
				}
				q.pop();
				// 向上下左右四个方向前进
				for (int i = 0; i < 4; i++) {
					int tail_x = x + index_move_change[i][0]; // 新的尾部坐标
					int tail_y = y + index_move_change[i][1];
					int head_x = tail_x + index_k_change[k][0]; // 新的头部坐标
					int head_y = tail_y + index_k_change[k][1];
					if (0 <= tail_x && tail_x < n && 0 <= tail_y && tail_y < n // 新尾部坐标的有效性
						&& 0 <= head_x && head_x < n && 0 <= head_y && head_y < n // 新头部坐标的有效性
						&& valid[tail_x][tail_y][k] == 1 // 单元格是否已经被遍历过
						&& grid[tail_x][tail_y] == 0 && grid[head_x][head_y] == 0 // 移动后的单元格不能是障碍
						) {
						valid[tail_x][tail_y][k] = 0;
						Position *new_position = new Position(tail_x, tail_y, k);
						q.emplace(new_position);
					}
				}
				// 方向改变
				if (0 <= x && x < n - 1 && 0 < y && y < n - 1 // 新坐标的有效性
					&& valid[x][y][1 - k] == 1 // 单元格是否已经被遍历过
					&& grid[x][y + 1] == 0 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 // 改变方向后的单元格不能是障碍
					) {
					valid[x][y][1 - k] = 0;
					Position *new_position = new Position(x, y, 1 - k);
					q.emplace(new_position);
				}

				size--;
			}
			min++;
		}

		return -1;
	}
private:
	class Position {
	public:
		Position(int x, int y, int k) {
			x_ = x;
			y_ = y;
			k_ = k;
		}

		int x_; // 尾巴的 x 坐标
		int y_; // 尾巴的 y 坐标
		int k_; // 姿态坐标，0 表示横向，1 表示纵向
	};
};
#endif // MORE_COMPLICATE_METHOD

#endif // __leet_code_1210_h__