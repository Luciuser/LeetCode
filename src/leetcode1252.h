#ifndef __leet_code_1252__
#define __leet_code_1252__

#include<iostream>
#include<vector>

//#define VIOLENCE_METHOD
#define CALCULATE_METHOD

#ifdef VIOLENCE_METHOD
class Solution {
public:
	int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
		std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

		for (int i = 0; i < indices.size(); i++) {
			int ri = indices[i][0];
			int ci = indices[i][1];
			for (int j = 0; j < n; j++) {
				matrix[ri][j]++;
			}
			for (int j = 0; j < m; j++) {
				matrix[j][ci]++;
			}
		}

		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] % 2 == 1) {
					result++;
				}
			}
		}
		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef CALCULATE_METHOD
class Solution {
public:
	int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
		std::vector<int> row(m, 0);
		std::vector<int> column(n, 0);

		for (int i = 0; i < indices.size(); i++) {
			int ri = indices[i][0];
			int ci = indices[i][1];
			row[ri]++;
			column[ci]++;
		}

		int result = 0;
		int rowRight = 0;
		int rowWrong = 0;
		for (int i = 0; i < row.size(); i++) {
			if (row[i] % 2 == 1) {
				rowRight++;
			}
			else {
				rowWrong++;
			}
		}
		result = rowRight * n;

		for (int i = 0; i < column.size(); i++) {
			if (column[i] % 2 == 1) {
				result = result - rowRight + rowWrong;
			}
		}

		return result;
	}
};
#endif // CALCULATE_METHOD

#endif // __leet_code_1252__