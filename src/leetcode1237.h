/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-17 10:28:36
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1237.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-17 10:53:19
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 0ms, 100.00%, MEMORY 6.2MB and 73.12%
 */

#ifndef __leet_code_1137_h__ 
#define __leet_code_1137_h__

#include<iostream>
#include<vector>

// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y) {
		return x * x + y * y;
	}
};

class Solution {
public:
	std::vector<std::vector<int>> findSolution(CustomFunction& customfunction, int z) {

		// x 单调递增，枚举每一个 x，去寻找对应的 y

		std::vector<std::vector<int>> result;

		int x = 1, y = 1;
		bool is_y_add = true; // 表示每次 y 的状态是增加还是减少
		while (x <= 1000 && 1 <= y && y <= 1000) {
			int answer = customfunction.f(x, y);
			if (answer == z) {
				// 找到了
				result.emplace_back(std::vector<int>{x, y});
				x++;
				is_y_add = false;
			}
			else {
				if (is_y_add == true) {
					if (answer < z) {
						y++;
					}
					else {
						// 此时说明结果经过了先小后大，因此此 x 不合适
						x++;
						is_y_add = false;
					}
				}
				else {
					if (answer < z) {
						// 此时说明结果经过了先大后小，因此此 x 不合适
						x++;
						is_y_add = customfunction.f(x, y) < z;
					}
					else {
						y--;
					}
				}
			}
		}

		return result;
	}
};

#endif // __leet_code_1137_h__