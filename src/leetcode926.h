#ifndef __leet_code_926__
#define __leet_code_926__

#include<iostream>
#include<vector>

//#define REJOINING_METHONDS // 设置不同情况，计算前缀和
#define DYNAMIC_PROGRAMMING // 动态规划

#ifdef REJOINING_METHONDS
class Solution {
public:

	int minFlipsMonoIncr(std::string &s) {
		std::string str = s;

		std::vector<int> sums;
		sums.push_back(0);

		int result = str.size();

		// 计算前缀和
		for (int i = 0; i < str.size(); i++) {
			int temp = sums[sums.size() - 1];
			if (str[i] == '0') {
				sums.push_back(temp);
			}
			else if (str[i] == '1') {
				sums.push_back(temp + 1);
			}
		}

		// 对于每个分割点，计算翻转的次数
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
	// TODO，看了题解，还没有具体练习

};
#endif // DYNAMIC_PROGRAMMING

#endif // __leet_code_926__