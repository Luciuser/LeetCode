/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-15 15:52:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode672.h
 * @Description: create the file and ITERATROR_METHOD and SLIDE_WINDOW_METHOD
 */

 /*
 * @EditTime: 2022-09-27 11:40:44
 * @Editor: Bingyang Jin
 * @Description: create WRITE_TABLE_METHOD, TIME 0ms, 100.00%, MEMORY 5.8MB and 65.18%
 */

#ifndef __leet_code_672__
#define __leet_code_672__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
	int flipLights(int n, int presses) {
		// 对于灯 1 2 3 4 5 6 7 8 9 10 …… 而言，其中7号灯跟着1号灯；6号、8号灯跟着2号灯；5号灯、9号灯跟着3号灯；10号灯跟着4号灯。
		// 因此当 n>4 时，只需判断前4个灯即可

		// 当 n>=3 时，presses = 1，有 4 种可能
		// 当 n>=3 时，presses = 2，有 7 种可能
		// 当 n>=3 时，presses = 3，有 8 种可能
		// 当 n>=3 时，presses = 4，有 8 种可能
		// 因此当 n>=3 且 presses >= 3 时，有 8 种可能

		// 同理计算 n == 2 和 n == 1 的可能性

		if (n >= 3) {
			if (presses == 0) {
				return 1;
			}
			else if (presses == 1) {
				return 4;
			}
			else if (presses == 2) {
				return 7;
			}
			else {
				return 8;
			}
		}
		else if (n == 2) {
			if (presses == 0) {
				return 1;
			}
			else if (presses == 1) {
				return 3;
			}
			else {
				return 4;
			}
		}
		else {
			if (presses == 0) {
				return 1;
			}
			else {
				return 2;
			}
		}


	}
};

#endif // __leet_code_672__