/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-17 10:27:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1139.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-17 13:22:54
 * @Editor: Bingyang Jin
 * @Description: create PREFIX_DYNAMIC_PROGRAMMING_METHOD, TIME 20ms, 65.71%, MEMORY 11.4MB and 48.57%
 */

#ifndef __leet_code_1139_h__ 
#define __leet_code_1139_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int largest1BorderedSquare(std::vector<std::vector<int>>& grid) {
		// 动态规划，制作 right 和 down 两个数组，right[i][j] 表示 (i, j) 点从左往右累加的 1 的数量，down[i][j] 表示 (i, j) 点从上往下累加的 1 的数量
		// 要满足边界全由 1 组成的正方形子网格，设左上角点为 (i, j)，且正方形长度为 x，则右下角点为 (i+x, j+x)
		// 充分必要条件为：
		//        right[i][j+x] >= x // 正方形的上边界
		//        down[i+x][j] >= x // 正方形的左边界
		//        right[i+x][j+x] >= x // 正方形的下边界
		//        down[i+x][j+x] >= x // 正方形的右边界
		// 满足此四个条件时，正方形子网格成立，且此时有元素数量为 (x+1)*(x+1)

		int m = grid.size();
		int n = grid[0].size();
		std::vector<std::vector<int>> right(m, std::vector<int>(n, 0)); // 表示 (i, j) 点从左往右累加的 1 的数量
		std::vector<std::vector<int>> down(m, std::vector<int>(n, 0)); // 表示 (i, j) 点从上往下累加的 1 的数量

		// 进行动态规划，构建 right 和 down 两个数组
		// 第一行第一列初始化
		down[0][0] = grid[0][0];
		right[0][0] = grid[0][0];
		// 第一列初始化
		for (int i = 1; i < m; i++) {
			if (grid[i][0] == 1) {
				right[i][0] = 1;
				down[i][0] = down[i - 1][0] + 1;
			}
		}
		for (int j = 1; j < n; j++) {
			if (grid[0][j] == 1) {
				down[0][j] = 1;
				right[0][j] = right[0][j - 1] + 1;
			}
		}
		// 动态规划
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (grid[i][j] == 1) {
					right[i][j] = right[i][j - 1] + 1;
					down[i][j] = down[i - 1][j] + 1;
				}
			}
		}

		int max = 0; // 当前已经确定可以实现的子网格长度初始长度默认为 0 
		bool is_all_zero = true;
		for (int i = 0; i + max < m; i++) {
			for (int j = 0; j + max < n; j++) {
				if (grid[i][j] == 1) {
					is_all_zero = false;
					for (int x = max; x < m && x < n; x++) {
						if (i + x >= m || j + x >= n) {
							break;
						}
						if (right[i][j + x] >= x && down[i + x][j] >= x && right[i + x][j + x] >= x && down[i + x][j + x] >= x) {
							max = x;
						}
					}
				}
			}
		}

		return  is_all_zero ? 0 : (max + 1) * (max + 1);
	}
};

#endif // __leet_code_1139_h__