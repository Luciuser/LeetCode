#ifndef __leet_code_1051__
#define __leet_code_1051__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int heightChecker(std::vector<int>& heights) {
		int sum = 0;

		std::vector<int> result = heights;
		std::sort(heights.begin(), heights.end());

		for (int i = 0; i < heights.size(); i++) {
			if (result[i] != heights[i]) {
				sum++;
			}
		}
		return sum;
	}
};

#endif // __leet_code_1051__