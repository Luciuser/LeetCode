/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-23 10:51:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1238.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-22 13:14:11
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 60.47%, MEMORY 17.2MB and 61.24%
 */

#ifndef __leet_code_1238_h__ 
#define __leet_code_1238_h__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> circularPermutation(int n, int start) {
		// 先构建从 0 开始的循环排列
		std::vector<int> temp(1 << n, 0);
		// 每次建立的时候，按照上一次建立的结果，倒序再复刻一遍即可
		for (int i = 0; i < n; i++) {
			int begin = 1 << i;
			for (int j = 0; j < begin; j++) {
				temp[begin + j] = temp[begin - j - 1] + begin;
			}
		}

		std::vector<int> result(1 << n, 0);
		int index = -1;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == start) {
				index = i;
				break;
			}
		}

		for (int i = 0; i < temp.size(); i++) {
			if (i < index) {
				result[temp.size() - index + i] = temp[i];
			}
			else {
				result[i - index] = temp[i];
			}
		}

		return result;
	}
};

#endif // __leet_code_1238_h__