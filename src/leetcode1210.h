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

//#define MORE_COMPLICATE_METHOD // ������ֻ���������£��˴���Ϊ����������ͬ������
//#define BFS_METHOD // BFS ����TIME 64ms, 12.28%, MEMORY 24.7MB and 8.54%
#define DYNAMIC_PROGRAMMING_METHOD // ��̬�滮��

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {

private:
	// �ж�λ�ú���̬ x y k ���� grid �����Ƿ���Ч
	bool isPositionValid(std::vector<std::vector<int>> const &grid, int x, int y, int k) {
		if (x < grid.size() && y < grid.size() && // β��������Ч 
			grid[x][y] == 0 // β���������ϰ�
			) {
			if ((k == 0 && y + 1 < grid.size() && grid[x][y + 1] == 0) || // ������̬�£�ͷ����Ч
				(k == 1 && x + 1 < grid.size() && grid[x + 1][y] == 0) // ������̬�£�ͷ����Ч
				) {
				return true;
			}
		}
		return false;
	}
	
	// �жϵ�ǰ��Чλ�ú���̬ x y k �� grid �����½�����ת������ת�����Ƿ���Ч
	bool isRotateValid(std::vector<std::vector<int>> const &grid, int x, int y, int k) {
		if (x + 1 < grid.size() && y + 1< grid.size()	) { 
			// ͷ���ռ���Ч 
			if (grid[x + 1][y + 1] == 0) { 
				// ����ռ���Ч
				if ((k == 0 && grid[x + 1][y] == 0) || (k == 1 && grid[x][y + 1] == 0)) {
					// ��ת��Ŀռ���Ч
					return true;
				}
			}
		}
		return false;
	}

	// ͨ����ת���Խ��и���
	void renewByRotate(std::vector<std::vector<int>> const &grid, std::vector<std::vector<std::vector<int>>> &dp, int i, int j) {
		if (dp[i][j][0] == -1 && dp[i][j][1] == -1) {
			// ������̬���޷��õ�����ֱ������
			return;
		}
		else if (dp[i][j][0] == -1) {
			// һ����̬�޷��õ������Խ�����̬ת��
			if (isRotateValid(grid, i, j, 1)) {
				dp[i][j][0] = dp[i][j][1] + 1;
			}
		}
		else if (dp[i][j][1] == -1) {
			// һ����̬�޷��õ������Խ�����̬ת��
			if (isRotateValid(grid, i, j, 0)) {
				dp[i][j][1] = dp[i][j][0] + 1;
			}
		}
		else {
			// ������̬�����Եõ������ϴ��ֵ�ɳ��Խ�����ת����Ϊ��Сֵ+1
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

		// ��̬�滮���� dp[i][j][k] ��ʾ�ߵ�β���� (i, j) λ�ã�����̬Ϊ k ʱ����С���������� k = 0 ��ʾ����k = 1 ��ʾ����
		// ��ʼ����Ϊ��dp[0][0][0] = 0
		// ������תʱ������ dp[i][j][k] = dp[i][j][1-k]+1
		// ��������ʱ������ dp[i][j+1][k] = dp[i][j][k]+1
		// ��������ʱ������ dp[i+1][j][k] = dp[i][j][k]+1
		// ������ʽ���ж�̬�滮

		int n = grid.size();

		std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(n, std::vector<int>(2, -1)));
		// ��ʼ��
		// ��ʼ��һ�е�һ��
		dp[0][0][0] = 0;
		if (isRotateValid(grid, 0, 0, 0)) {
			dp[0][0][1] = 1;
		}
		// ��ʼ����һ��
		for (int i = 1; i < n; i++) {
			for (int k = 0; k < 2; k++) {
				if (dp[0][i - 1][k] != -1 && isPositionValid(grid, 0, i, k)) {
					dp[0][i][k] = dp[0][i - 1][k] + 1;
				}
			}
			renewByRotate(grid, dp, 0, i);
		}
		// ��ʼ����һ��
		for (int i = 1; i < n; i++){
			for (int k = 0; k < 2; k++) {
				if (dp[i - 1][0][k] != -1 && isPositionValid(grid, i, 0, k)) {
					dp[i][0][k] = dp[i - 1][0][k] + 1;
				}
			}
			renewByRotate(grid, dp, i, 0);
		}

		// ʣ��Ĳ��ֽ��ж�̬�滮 
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				// ÿ��״̬���������Ϸ���һ��״̬��������һ��״̬ת�ƶ���
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
		std::vector<std::vector<int>> index_move_change = {{0,1},{1,0} }; // �������ƶ�ʱ��x �� y �ı仯
		std::vector<std::vector<int>> index_k_change = { {0,1},{1,0} }; // ���ڲ�ͬ k ����ͷ�������β x �� y �ı仯
		// BFS ����
		std::vector<std::vector<std::vector<int>>> valid(n, std::vector<std::vector<int>>(n, std::vector<int>(2, 1))); // ��������̬�Ƿ��Ѿ� bfs ����
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
				// �����������ĸ�����ǰ��
				for (int i = 0; i < 2; i++) {
					int tail_x = x + index_move_change[i][0]; // �µ�β������
					int tail_y = y + index_move_change[i][1];
					int head_x = tail_x + index_k_change[k][0]; // �µ�ͷ������
					int head_y = tail_y + index_k_change[k][1];
					if (0 <= tail_x && tail_x < n && 0 <= tail_y && tail_y < n // ��β���������Ч��
						&& 0 <= head_x && head_x < n && 0 <= head_y && head_y < n // ��ͷ���������Ч��
						&& valid[tail_x][tail_y][k] == 1 // ��Ԫ���Ƿ��Ѿ���������
						&& grid[tail_x][tail_y] == 0 && grid[head_x][head_y] == 0 // �ƶ���ĵ�Ԫ�������ϰ�
						) {
						valid[tail_x][tail_y][k] = 0;
						Position *new_position = new Position(tail_x, tail_y, k);
						q.emplace(new_position);
					}
				}
				// ����ı�
				if (0 <= x && x < n - 1 && 0 <= y && y < n - 1 // ���������Ч��
					&& valid[x][y][1 - k] == 1 // ��Ԫ���Ƿ��Ѿ���������
					&& grid[x][y + 1] == 0 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 // �ı䷽���ĵ�Ԫ�������ϰ�
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

		int x_; // β�͵� x ����
		int y_; // β�͵� y ����
		int k_; // ��̬���꣬0 ��ʾ����1 ��ʾ����
	};
};
#endif // BFS_METHOD

#ifdef MORE_COMPLICATE_METHOD
class Solution {
public:
	int minimumMoves(std::vector<std::vector<int>>& grid) {

		int n = grid.size();
		std::vector<std::vector<int>> index_move_change = { {0,-1},{0,1},{-1,0},{1,0} }; // �����������ƶ�ʱ��x �� y �ı仯
		std::vector<std::vector<int>> index_k_change = { {0,1},{1,0} }; // ���ڲ�ͬ k ����ͷ�������β x �� y �ı仯
		// BFS ����
		std::vector<std::vector<std::vector<int>>> valid(n, std::vector<std::vector<int>>(n, std::vector<int>(2, 1))); // ��������̬�Ƿ��Ѿ� bfs ����
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
				// �����������ĸ�����ǰ��
				for (int i = 0; i < 4; i++) {
					int tail_x = x + index_move_change[i][0]; // �µ�β������
					int tail_y = y + index_move_change[i][1];
					int head_x = tail_x + index_k_change[k][0]; // �µ�ͷ������
					int head_y = tail_y + index_k_change[k][1];
					if (0 <= tail_x && tail_x < n && 0 <= tail_y && tail_y < n // ��β���������Ч��
						&& 0 <= head_x && head_x < n && 0 <= head_y && head_y < n // ��ͷ���������Ч��
						&& valid[tail_x][tail_y][k] == 1 // ��Ԫ���Ƿ��Ѿ���������
						&& grid[tail_x][tail_y] == 0 && grid[head_x][head_y] == 0 // �ƶ���ĵ�Ԫ�������ϰ�
						) {
						valid[tail_x][tail_y][k] = 0;
						Position *new_position = new Position(tail_x, tail_y, k);
						q.emplace(new_position);
					}
				}
				// ����ı�
				if (0 <= x && x < n - 1 && 0 < y && y < n - 1 // ���������Ч��
					&& valid[x][y][1 - k] == 1 // ��Ԫ���Ƿ��Ѿ���������
					&& grid[x][y + 1] == 0 && grid[x + 1][y] == 0 && grid[x + 1][y + 1] == 0 // �ı䷽���ĵ�Ԫ�������ϰ�
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

		int x_; // β�͵� x ����
		int y_; // β�͵� y ����
		int k_; // ��̬���꣬0 ��ʾ����1 ��ʾ����
	};
};
#endif // MORE_COMPLICATE_METHOD

#endif // __leet_code_1210_h__