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
		// ��̬�滮������ right �� down �������飬right[i][j] ��ʾ (i, j) ����������ۼӵ� 1 ��������down[i][j] ��ʾ (i, j) ����������ۼӵ� 1 ������
		// Ҫ����߽�ȫ�� 1 ��ɵ������������������Ͻǵ�Ϊ (i, j)���������γ���Ϊ x�������½ǵ�Ϊ (i+x, j+x)
		// ��ֱ�Ҫ����Ϊ��
		//        right[i][j+x] >= x // �����ε��ϱ߽�
		//        down[i+x][j] >= x // �����ε���߽�
		//        right[i+x][j+x] >= x // �����ε��±߽�
		//        down[i+x][j+x] >= x // �����ε��ұ߽�
		// ������ĸ�����ʱ��������������������Ҵ�ʱ��Ԫ������Ϊ (x+1)*(x+1)

		int m = grid.size();
		int n = grid[0].size();
		std::vector<std::vector<int>> right(m, std::vector<int>(n, 0)); // ��ʾ (i, j) ����������ۼӵ� 1 ������
		std::vector<std::vector<int>> down(m, std::vector<int>(n, 0)); // ��ʾ (i, j) ����������ۼӵ� 1 ������

		// ���ж�̬�滮������ right �� down ��������
		// ��һ�е�һ�г�ʼ��
		down[0][0] = grid[0][0];
		right[0][0] = grid[0][0];
		// ��һ�г�ʼ��
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
		// ��̬�滮
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (grid[i][j] == 1) {
					right[i][j] = right[i][j - 1] + 1;
					down[i][j] = down[i - 1][j] + 1;
				}
			}
		}

		int max = 0; // ��ǰ�Ѿ�ȷ������ʵ�ֵ������񳤶ȳ�ʼ����Ĭ��Ϊ 0 
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