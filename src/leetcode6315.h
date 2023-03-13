/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6315.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 336
 */

#ifndef __leet_code_6315_h__
#define __leet_code_6315_h__

#include<iostream>
#include<queue>
#include<vector>

class Solution {
public:
	int vowelStrings(std::vector<std::string>& words, int left, int right) {

		int sum = 0;
		for (int i = left; i <= right; i++) {
			int n = words[i].size();
			if ((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') &&
				(words[i][n - 1] == 'a' || words[i][n - 1] == 'e' || words[i][n - 1] == 'i' || words[i][n - 1] == 'o' || words[i][n - 1] == 'u')) {
				sum++;
			}
		}
		return sum;

	}
};

#endif // __leet_code_6315_h__