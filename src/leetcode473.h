#ifndef __leet_code_473__
#define __leet_code_473__

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<map>

#define VIOLENCE_METHODS	// ����������

#ifdef VIOLENCE_METHODS
class Solution {
public:

	double average;

	bool dfs(int index, std::vector<int> &edges, std::vector<int> &sticks, int len) {
		if (index == sticks.size()) {
			return true;
		}

		for (int i = 0; i < edges.size(); i++) {
			if (edges[i] + sticks[index] <= len) {
				edges[i] += sticks[index];
				if (dfs(index + 1, edges, sticks, len)) {
					return true;
				}
				edges[i] -= sticks[index];
			}
		}

		return false;
	}

	bool makesquare(std::vector<int>& matchsticks) {
		long long sum = 0;
		std::vector<int> temp;
		std::vector<int> edges(4, 0);

		// �����ÿ���ߵ�ƽ������
		for (int i = 0; i < matchsticks.size(); i++) {
			temp.push_back(matchsticks[i]);
			sum += matchsticks[i];
		}

		// �� average �������������޷��ɹ�
		if (sum % 4 != 0) {
			return false;
		}
		average = sum / 4.0;

		std::sort(temp.begin(), temp.end(), [=](int a, int b) {return a > b; });
		// ����һ������ƽ��ֵ��
		if (temp[0] * 4 > sum) {
			return false;
		}

		return dfs(0, edges, temp, sum / 4.0);
	}
};
#endif // VIOLENCE_METHODS

#endif // __leet_code_473__