/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-22 15:53:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2376.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-14 14:40:11
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, out of TIME
 */

 /*
 * @EditTime: 2024-01-14 10:49:31
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 12ms, 30.08%, MEMORY 11.6MB and 82.9%
 */

#ifndef __leet_code_2376__
#define __leet_code_2376__

#include<iostream>
#include<vector>

class Solution {
public:
	int countSpecialNumbers(int n) {

		std::vector<int> numbers;
		int t = n;
		while (t>=10) {
			int number = t % 10;
			numbers.push_back(number);
			t = t / 10;
		}
		numbers.push_back(t);

		// 假设数字为 m 位，那么 [1,10^(m)-1]这部分，可以直接通过公式计算，剩余部分可以通过递归迭代计算
		int m = numbers.size();
		if (m == 1) {
			return n;
		}
		int sum = 1;
		t = m;
		for (int i = 1; i < m; i++) {
			sum *= 10 - i;
		}

		// 根据数位进行迭代计算
		for (int i = m - 1; i >= 0; i--) {

		}

	}
};

#endif // __leet_code_2376__
