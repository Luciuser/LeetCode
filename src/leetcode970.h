/*
 * @Author: Bingyang Jin
 * @Date: 2023-05-02 19:08:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode970.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-05-02 19:27:53
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_PROGTAMMING_METHOD, TIME 4ms, 42.36%, MEMORY 6.5MB and 43.23%
 */

#ifndef __leet_code_970_h__ 
#define __leet_code_970_h__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
	std::vector<int> powerfulIntegers(int x, int y, int bound) {
		
		std::vector<int> result;
		if (bound < 2) {
			return result;
		}
		if (x > y) {
			int temp = x;
			x = y;
			y = temp;
		}
		if (x == 1 && y == 1) {
			result.push_back(2);
			return result;
		}
		else if (x == 1) {
			int j = 0;
			int sum = pow(y, j) + 1;
			std::unordered_set<int> s;
			while (sum<=bound) {
				s.insert(sum);
				j++;
				sum = pow(y, j) + 1;
			}
			for (auto iter : s) {
				result.emplace_back(iter);
			}
		}
		else {
			int i = 0;
			int j = 0;
			std::unordered_set<int> s;
			int sum = pow(y, j) + pow(x, i);
			while (sum <= bound) {
				while (sum <= bound) {
					s.insert(sum);
					i++;
					sum = pow(y, j) + pow(x, i);
				}
				i = 0;
				j++;
				sum = pow(y, j) + pow(x, i);
			}
			for (auto iter : s) {
				result.emplace_back(iter);
			}
		}

		return result;
	}
};

#endif // __leet_code_970_h__