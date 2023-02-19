/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6365.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-19
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 0ms, MEMORY 6MB
 */

#ifndef __leet_code_6365_h__ 
#define __leet_code_6365_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int minOperations(int n) {
		std::vector<int> ones;
		while (n >= 2) {
			ones.emplace_back(n % 2);
			n = n / 2;
		}
		ones.emplace_back(n);
		ones.emplace_back(0);
		ones.emplace_back(0);

		int sum = 0;
		int continue_one = 0;
		for (int i = 0; i < ones.size(); i++) {
			if (ones[i] == 1) {
				continue_one++;
			}
			else {
				if (continue_one == 0) {
					continue;
				}
				else if (continue_one == 1) {
					continue_one = 0;
					sum++;
				}
				else {
					continue_one = 1;
					sum++;
				}
			}
		}

		return sum;
	}
};

#endif // __leet_code_6362_h__