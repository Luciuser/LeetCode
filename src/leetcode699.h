#ifndef __leet_code_699__
#define __leet_code_699__

#include<iostream>
#include<vector>

#define VIOLENCE_METHODS // 暴力解法

#ifdef VIOLENCE_METHODS
class Solution {
public:
	std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
		std::vector<int> result; // 结果，当前情况下的最高高度
		std::vector<int> height; // 各个方块的高度

		for (int i = 0; i < positions.size(); i++) {
			int max = positions[i][1];
			for (int j = 0; j < i; j++) {
				if (positions[j][0] + positions[j][1] <= positions[i][0]) {
					// j 的 right 在 i 的 left 的左边
					continue;
				}
				if (positions[j][0] >= positions[i][0] + positions[i][1]) {
					// j 的 left 在 i 的 right 的右边
					continue;
				}

				if (max < height[j] + positions[i][1]) {
					max = height[j] + positions[i][1];
				}
			}

			height.push_back(max);
			if (result.size() == 0) {
				result.push_back(max);
			}
			else {
				if (max > result[result.size() - 1]) {
					result.push_back(max);
				}
				else {
					result.push_back(result[result.size() - 1]);
				}
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHODS

#endif // __leet_code_699__