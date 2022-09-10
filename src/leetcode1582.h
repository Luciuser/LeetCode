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
 * @Description: create NORMAL_METHOD，TIME 20ms, 47.44%, MEMORY 12.6MB and 62.94%
 */

#ifndef __leet_code_1582__
#define __leet_code_1582__

#include<iostream>
#include<vector>

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

#endif // __leet_code_1582__
