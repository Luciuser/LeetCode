/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-24 10:02:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2865.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-24 10:42:36
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 30ms, 53.60%, MEMORY 26.44MB and 8.07%
 */

 /*
 * @EditTime: 2024-01-24 11:16:02
 * @Editor: Bingyang Jin
 * @Description: create MONOTONIC_STACK_METHOD, TIME 16ms, 86.74%, MEMORY 28.62MB and 7.20%
 */

#ifndef __leet_code_2865__
#define __leet_code_2865__

//#define VIOLENCE_METHOD // TIME 30ms, 53.60%, MEMORY 26.44MB and 8.07%
#define MONOTONIC_STACK_METHOD // TIME 16ms, 86.74%, MEMORY 28.62MB and 7.20%

#include<iostream>
#include<stack>
#include<vector>

#ifdef VIOLENCE_METHOD
class Solution {
public:
	long long maximumSumOfHeights(std::vector<int>& maxHeights) {
		long long max = 0;
		int n = maxHeights.size();

		// 山峰位于 i 处，基于已有的 sum 进行计算求和
		for (int i = 0; i < n; i++) {
			int top = maxHeights[i];
			long long sum = 0;

			int before = top;
			sum += top;
			for (int j = i - 1; j >= 0; j--) {
				if (maxHeights[j] <= before) {
					sum += maxHeights[j];
					before = maxHeights[j];
				}
				else {
					sum += before;
				}
			}
			before = top;
			for (int j = i + 1; j < n; j++) {
				if (maxHeights[j] <= before) {
					sum += maxHeights[j];
					before = maxHeights[j];
				}
				else {
					sum += before;
				}
			}
			if (sum > max) {
				max = sum;
			}
		}


		return max;
	}
};
#endif // VIOLENCE_METHOD

#ifdef MONOTONIC_STACK_METHOD
class Solution {
public:
	long long maximumSumOfHeights(std::vector<int>& maxHeights) {
		int n = maxHeights.size();

		std::vector<long long> prefix(n);
		std::vector<long long> sufffix(n);

		// 构建左侧非递减数列
		std::stack<int> temp;
		for (int i = 0; i < n; i++) {
			long long t = maxHeights[i];
			while (true) {
				if (temp.size() == 0) {
					prefix[i] = (i + 1)*t;
					temp.push(i);
					break;
				}
				int top = temp.top();
				if (maxHeights[top] <= maxHeights[i]) {
					prefix[i] = prefix[top] + (i - top)*t;
					temp.push(i);
					break;
				}
				else {
					temp.pop();
				}
			}
		}
		// 构建右侧非递增数列
		while (temp.size() > 0) {
			temp.pop();
		}
		for (int i = n-1; i >=0; i--) {
			long long t = maxHeights[i];
			while (true) {
				if (temp.size() == 0) {
					sufffix[i] = (n - i)*t;
					temp.push(i);
					break;
				}
				int top = temp.top();
				if (maxHeights[top] <= maxHeights[i]) {
					sufffix[i] = sufffix[top] + (top - i)*t;
					temp.push(i);
					break;
				}
				else {
					temp.pop();
				}
			}
		}

		long long max = 0;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			std::cout << i << " " << prefix[i] << " " << sufffix[i] << std::endl;
			sum = prefix[i] + sufffix[i] - maxHeights[i];
			if (sum > max) {
				max = sum;
			}
		}

		return max;
	}
};
#endif // MONOTONIC_STACK_METHOD

#endif // __leet_code_2865__ 