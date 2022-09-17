/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-15 15:52:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode672.h
 * @Description: create the file and ITERATROR_METHOD and SLIDE_WINDOW_METHOD
 */

 /*
 * @EditTime: 2022-09-15 15:20:50
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 680ms, 9.02%, MEMORY 420.9MB and 5.16%
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

		// 用 int 来表示前 4 号灯的情况，最小值为0，最大值为15
		std::unordered_set<int> result;	// 最终出现的结果
		std::vector<int>lightIndex(16, -1);
		std::vector<int>lightIndexNext(16, -1);

		int open[4] = { 15, 5, 10, 9 };
		int time = presses;
		// 第一次操作
		for (int j = 0; j < 4; j++) {
			int light = 15 ^ open[j]; // 进行异或操作取反
			if (time % 2 == 0) {
				result.emplace(light);
			}
			lightIndex[light] = time - 1;
		}
		time--;
		if (time == -1) {
			return 1;
		}
		else if (time == 0) {
			return result.size();
		}

		// 后面的多次循环
		while (true) {
			for (int i = 0; i < 16; i++) {
				if (lightIndex[i] == -1) {
					continue;
				}  
				for (int j = 0; j < 4; j++) {
					int light = i ^ open[j]; // 进行异或操作取反
					if (time % 2 == 0) {
						
					}
				}
			}

		}

		return result.size();
	}
};

#endif // __leet_code_672__