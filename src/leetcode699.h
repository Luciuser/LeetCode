#ifndef __leet_code_699__
#define __leet_code_699__

#include<iostream>
#include<vector>

#define VIOLENCE_METHODS // �����ⷨ

#ifdef VIOLENCE_METHODS
class Solution {
public:
	std::vector<int> fallingSquares(std::vector<std::vector<int>>& positions) {
		std::vector<int> result; // �������ǰ����µ���߸߶�
		std::vector<int> height; // ��������ĸ߶�

		for (int i = 0; i < positions.size(); i++) {
			int max = positions[i][1];
			for (int j = 0; j < i; j++) {
				if (positions[j][0] + positions[j][1] <= positions[i][0]) {
					// j �� right �� i �� left �����
					continue;
				}
				if (positions[j][0] >= positions[i][0] + positions[i][1]) {
					// j �� left �� i �� right ���ұ�
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