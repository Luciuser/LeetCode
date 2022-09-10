/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-08 09:30:41
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode667.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-08 09:42:55
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD£¬TIME 0ms, 100.00%, MEMORY 7.5MB and 22.85%
 */

#ifndef __leet_code_667__
#define __leet_code_667__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> constructArray(int n, int k) {
		std::vector<int> result;
		result.push_back(1);

		int temp = 1;
		int before = 1;
		for (int i = 0; i < k; i++) {
			before += temp * (k - i);
			temp *= -1;
			result.push_back(before);
		}
		for (int i = k + 2; i <= n; i++) {
			result.push_back(i);
		}
		return result;
	}
};

#endif // __leet_code_667__