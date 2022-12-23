/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-22 12:06:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1799.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-21 00:36:46
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 30.39%, MEMORY 5.7MB and 99.02%
 */

#ifndef __leet_code_1799__
#define __leet_code_1799__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int maxScore(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end(), [=](int a, int b) {
			return a < b;
		});



	}
private:
	// хон╙ a<b
	int gcd(int a, int b) {
		while (true) {
			int temp = b % a;
			if (temp == 0) {
				return a;
			}
			b = a;
			a = temp;
		}
	}
};

#endif // __leet_code_1799__