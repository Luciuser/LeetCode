/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-08 09:56:09
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1582.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-08 10:18:24
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD，TIME 20ms, 47.44%, MEMORY 12.6MB and 62.94%
 */

 /*
 * @EditTime: 2022-10-10 14:17:56
 * @Editor: Bingyang Jin
 * @Description: create COLUMN_TAG_METHOD，TIME 16ms, 85.26%, MEMORY 12.4MB and 99.01%
 */

#ifndef __leet_code_1582__
#define __leet_code_1582__

#include<iostream>
#include<vector>

//#define VIOLENCE_METHOD // 蛮力法，暴力求解，TIME 20ms, 47.44%, MEMORY 12.6MB and 62.94%
//#define ENUM_METHOD // 枚举法，先计算每行每列的和，再枚举，TIME 20ms, 47.55%, MEMORY 12.8MB and 7.22%
#define COLUMN_TAG_METHOD // 列标记法，TIME 16ms, 85.26%, MEMORY 12.4MB and 99.01%

#ifdef VIOLENCE_METHOD
class Solution {
public:
	int numSpecial(std::vector<std::vector<int>>& mat) {
		int result = 0;

		std::vector<int> cols(mat[0].size(), 0); // 每一列有几个1

		for (int i = 0; i < mat.size(); i++) {
			int temp = -1; // 每一行出现的第一个 1 的位置，temp = -1 表示没有1，temp = -2 表示有2个以上1
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1) {
					if (temp == -1) {
						temp = j;
					}
					else {
						temp = -2;
					}
					cols[j]++;
				}
			}

			if (temp >= 0) {
				// 这一行有且仅有一个 1 
				if (cols[temp] == 1) {
					// 在已记录的列中，只有1个1
					bool success = true;
					for (int j = i + 1; j < mat.size(); j++) {
						if (mat[j][temp] == 1) {
							success = false;
							break;
						}
					}
					if (success) {
						result++;
					}
				}
			}

		}

		return result;
	}
};
#endif // NORMAL_METHOD

#ifdef ENUM_METHOD
class Solution {
public:
	int numSpecial(std::vector<std::vector<int>>& mat) {
		int result = 0;

		std::vector<int> rowSum(mat.size(), 0);
		std::vector<int> columnSum(mat[0].size(), 0);
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				columnSum[j] += mat[i][j];
				rowSum[i] += mat[i][j];
			}
		}

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1 && columnSum[j] == 1 && rowSum[i] == 1) {
					result++;
				}
			}
		}
		
		return result;
	}
};
#endif // ENUM_METHOD

#ifdef COLUMN_TAG_METHOD
class Solution {
public:
	int numSpecial(std::vector<std::vector<int>>& mat) {
		int m = mat.size(), n = mat[0].size();
		for (int i = 0; i < m; i++) {
			int cnt1 = 0;
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == 1) {
					cnt1++;
				}
			}
			if (i == 0) {
				cnt1--;
			}
			if (cnt1 > 0) {
				for (int j = 0; j < n; j++) {
					if (mat[i][j] == 1) {
						mat[0][j] += cnt1;
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (mat[0][i] == 1) {
				sum++;
			}
		}
		return sum;
	}
};
#endif // COLUMN_TAG_METHOD


#endif // __leet_code_1582__
