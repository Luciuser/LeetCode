/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-31 14:53:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1632.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-31 16:06:33
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, OUT OF TIME
 */

 /*
 * @EditTime: 2023-01-31 16:17:31
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_OPTIMIZE_METHOD, TIME 1500ms, 5.25%, MEMORY 119.2MB and 75.62%
 */

#ifndef __leet_code_1632_h__
#define __leet_code_1632_h__

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

//#define VIOLENCE_METHOD // 暴力法，超时
#define VIOLENCE_OPTIMIZE_METHOD // 暴力法优化测试，对于不变的行列不再进行计算，TIME 1500ms, 5.25%, MEMORY 119.2MB and 75.62%

#ifdef VIOLENCE_OPTIMIZE_METHOD
class Solution {
private:
	void print(std::vector<std::vector<int>> &matrix) {
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				std::cout << matrix[i][j] << "    ";
			}
			std::cout << std::endl;
		}
	}

public:
	std::vector<std::vector<int>> matrixRankTransform(std::vector<std::vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		// 构建每一行和每一列的索引排序情况，索引排序依据从小到大进行
		std::vector<std::map<int, std::vector<int>>> row_sort;
		std::vector<std::map<int, std::vector<int>>> column_sort;

		for (int i = 0; i < m; i++) {
			std::map<int, std::vector<int>>temp;
			for (int j = 0; j < n; j++) {
				temp[matrix[i][j]].emplace_back(j);
			}
			row_sort.emplace_back(temp);
		}
		for (int i = 0; i < n; i++) {
			std::map<int, std::vector<int>>temp;
			for (int j = 0; j < m; j++) {
				temp[matrix[j][i]].emplace_back(j);
			}
			column_sort.emplace_back(temp);
		}

		std::vector<std::vector<int>> result(m, std::vector<int>(n, 1));
		bool is_change = true;
		std::vector<int> is_row_change(m, 1);
		std::vector<int> is_column_change(n, 1);

		// 对每一行和每一列进行判断
		while (is_change) {
			is_change = false;

			print(result);

			// 判断每一行
			for (int i = 0; i < m; i++) {
				if (is_row_change[i] == 0) {
					continue;
				}
				is_row_change[i] = 0;
				int before = -std::numeric_limits<int>::max();
				for (auto iter = row_sort[i].begin(); iter != row_sort[i].end(); iter++) {
					// 寻找到在原数组中，该行元素中大小相同的所有位置，在新数组中的最大值，并将所有位置都更改为该最大值
					int current = before + 1;
					// 找最大值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (current < result[i][index]) {
							current = result[i][index];
						}
					}
					// 整体赋值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (result[i][index] < current) {
							result[i][index] = current;
							is_column_change[index] = 1;
							is_change = true;
						}
					}
					// 更改前一个 before
					before = current;
				}
			}
			// 判断每一列
			for (int i = 0; i < n; i++) {
				if (is_column_change[i] == 0) {
					continue;
				}
				is_column_change[i] = 0;
				int before = -std::numeric_limits<int>::max();
				for (auto iter = column_sort[i].begin(); iter != column_sort[i].end(); iter++) {
					// 寻找到在原数组中，该行元素中大小相同的所有位置，在新数组中的最大值，并将所有位置都更改为该最大值
					int current = before + 1;
					// 找最大值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (current < result[index][i]) {
							current = result[index][i];
						}
					}
					// 整体赋值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (result[index][i] < current) {
							result[index][i] = current;
							is_row_change[index] = 1;
							is_change = true;
						}
					}
					// 更改前一个 before
					before = current;
				}
			}

		}

		print(result);

		return result;
	}
};
#endif // VIOLENCE_OPTIMIZE_METHOD

#ifdef VIOLENCE_METHOD
class Solution {
private:
	void print(std::vector<std::vector<int>> &matrix) {
		std::cout << "----------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------------------" << std::endl;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				std::cout << matrix[i][j] << "    ";
			}
			std::cout << std::endl;
		}
	}

public:
	std::vector<std::vector<int>> matrixRankTransform(std::vector<std::vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		// 构建每一行和每一列的索引排序情况，索引排序依据从小到大进行
		std::vector<std::map<int, std::vector<int>>> row_sort;
		std::vector<std::map<int, std::vector<int>>> column_sort;

		for (int i = 0; i < m; i++) {
			std::map<int, std::vector<int>>temp;
			for (int j = 0; j < n; j++) {
				temp[matrix[i][j]].emplace_back(j);
			}
			row_sort.emplace_back(temp);
		}
		for (int i = 0; i < n; i++) {
			std::map<int, std::vector<int>>temp;
			for (int j = 0; j < m; j++) {
				temp[matrix[j][i]].emplace_back(j);
			}
			column_sort.emplace_back(temp);
		}

		std::vector<std::vector<int>> result(m, std::vector<int>(n, 1));

		bool is_change = true;

		// 对每一行和每一列进行判断
		while (is_change) {
			is_change = false;

			// 判断每一行
			for (int i = 0; i < m; i++) {
				int before = -std::numeric_limits<int>::max();
				for (auto iter = row_sort[i].begin(); iter != row_sort[i].end(); iter++) {
					// 寻找到在原数组中，该行元素中大小相同的所有位置，在新数组中的最大值，并将所有位置都更改为该最大值
					int current = before + 1;
					// 找最大值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (current < result[i][index]) {
							current = result[i][index];
						}
					}
					// 整体赋值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (result[i][index] < current) {
							result[i][index] = current;
							is_change = true;
						}
					}
					// 更改前一个 before
					before = current;
				}
			}
			// 判断每一列
			for (int i = 0; i < n; i++) {
				int before = -std::numeric_limits<int>::max();
				for (auto iter = column_sort[i].begin(); iter != column_sort[i].end(); iter++) {
					// 寻找到在原数组中，该行元素中大小相同的所有位置，在新数组中的最大值，并将所有位置都更改为该最大值
					int current = before + 1;
					// 找最大值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (current < result[index][i]) {
							current = result[index][i];
						}
					}
					// 整体赋值
					for (int j = 0; j < (*iter).second.size(); j++) {
						int index = (*iter).second[j];
						if (result[index][i] < current) {
							result[index][i] = current;
							is_change = true;
						}
					}
					// 更改前一个 before
					before = current;
				}
			}

		}

		print(result);

		return result;
	}
};
#endif // VIOLENCE_METHOD

#endif // __leet_code_1632_h__