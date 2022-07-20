#ifndef __leet_code_926__
#define __leet_code_926__

#include<iostream>
#include<vector>

//#define REJOINING_METHONDS // ���ò�ͬ���������ǰ׺��
#define DYNAMIC_PROGRAMMING // ��̬�滮

#ifdef REJOINING_METHONDS
class Solution {
public:

	int minFlipsMonoIncr(std::string &s) {
		std::string str = s;

		std::vector<int> sums;
		sums.push_back(0);

		int result = str.size();

		// ����ǰ׺��
		for (int i = 0; i < str.size(); i++) {
			int temp = sums[sums.size() - 1];
			if (str[i] == '0') {
				sums.push_back(temp);
			}
			else if (str[i] == '1') {
				sums.push_back(temp + 1);
			}
		}

		// ����ÿ���ָ�㣬���㷭ת�Ĵ���
		int n = sums.size();
		for (int i = 0; i < n; i++) {
			int tempResult = sums[i] + (n - 1 - i) - (sums[n - 1] - sums[i]);
			if (tempResult < result) {
				result = tempResult;
			}
		}

		return result;
	}
};
#endif // REJOINING_METHONDS

#ifdef DYNAMIC_PROGRAMMING
class Solution {
public:
	// TODO��������⣬��û�о�����ϰ

};
#endif // DYNAMIC_PROGRAMMING

#endif // __leet_code_926__