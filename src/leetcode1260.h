/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-20 01:06:19
 * @FilePath: /src/leetcode731.h
  * @Description: create the file and consider the column and row for every k
 */

#ifndef __leet_code_1260__
#define __leet_code_1260__

//#define COLUMN_ROW_METHOD
#define ONE_DIMESION_METHOD

#include<iostream>
#include<vector>

#ifdef COLUMN_ROW_METHOD
class Solution {
public:
	std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {

		int m = grid.size();
		int n = grid[0].size();

		int answer = k / n;
		int mod = k % n;

		// ���� mod �Ĵ����������������ƽ�
		std::vector<std::vector<int>> first(m, std::vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int k = (j + mod) % n;
				first[i][k] = grid[i][j];
			}
		}

		// ���� answer �Ĵ����������־�������ѹ
		std::vector<std::vector<int>> second(m, std::vector<int>(n, 0));

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				int k = answer + i;
				if (j < mod) {
					k++;
				}
				k = k % m;
				second[k][j] = first[i][j];
			}
		}

		return second;
	}
};
#endif // COLUMN_ROW_METHOD

#ifdef ONE_DIMESION_METHOD
// ���ߣ�LeetCode - Solution
// ���ӣ�https ://leetcode.cn/problems/shift-2d-grid/solution/er-wei-wang-ge-qian-yi-by-leetcode-solut-ploz/
// ��Դ�����ۣ�LeetCode��
// ����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
class Solution {
public:
	std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k) {
		int m = grid.size(), n = grid[0].size();
		std::vector<std::vector<int>> ret(m, std::vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int index1 = (i * n + j + k) % (m * n);
				ret[index1 / n][index1 % n] = grid[i][j];
			}
		}
		return ret;
	}
};


#endif // ONE_DIMESION_METHOD



#endif // __leet_code_1260__