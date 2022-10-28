/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-28 00:08:36
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode907.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-28 15:29:00
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_SET, TIME 140ms, 5.51%, MEMORY 64.8MB and 5.01%
 */

 /*
 * @EditTime: 2022-10-28 15:43:38
 * @Editor: Bingyang Jin
 * @Description: create MONOTONIC_STACK_DYNAMIC_PROGRAMMING, TIME 76ms, 68.14%, MEMORY 41.3MB and 62.13%
 */

#ifndef __leet_code_907__
#define __leet_code_907__

//#define DYNAMIC_PROGRAMMING_SET // 用 SET 计算单调栈，动态规划进行计算，TIME 140ms, 5.51%, MEMORY 64.8MB and 5.01%
#define MONOTONIC_STACK_DYNAMIC_PROGRAMMING // 单调栈+动态规划，TIME 76ms, 68.14%, MEMORY 41.3MB and 62.13%

#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<algorithm>

#ifdef DYNAMIC_PROGRAMMING_SET
struct pair_comp {
	bool operator() (const std::pair<int, int>& A, const std::pair<int, int>& B) const {
		return A.first < B.first;
	}
};

class Solution {
public:
	int sumSubarrayMins(std::vector<int>& arr) {
		// 动态规划
		// 假设 dp[i] 是所有以第 i 位为结尾的所有连续子数组的最小值和
		// 那么考虑第 dp[i+1] 位，从 dp[i+1] 向前遍历，找到第一个索引 k，满足 arr[k] <= dp[i+1]
		// 则 dp[i+1] = dp[k] + (i+1-k) * arr[i+1]

		// 排序 O(nlogn)
		std::set<std::pair<int, int>, pair_comp> order;
		std::vector<int> minBefore(arr.size(), -1);
		order.emplace(std::pair<int, int>(arr[0], 0));
		minBefore[0] = -1;
		for (int i = 1; i < arr.size(); i++) {
			auto index = order.lower_bound(std::pair<int, int>(arr[i], i));
			if (index == order.begin()) {
				minBefore[i] = -1;
			}
			else {
				index--;
				minBefore[i] = (*index).second;
				index++;
			}

			if (order.size() > 0) {
				order.erase(index, order.end());
			}

			order.emplace(std::pair<int, int>(arr[i], i));
		}
		order.clear();

		long sum = 0;
		std::vector<int> dp(arr.size(), 0);
		dp[0] = arr[0];
		sum += dp[0];
		for (int i = 1; i < arr.size(); i++) {
			dp[i] = (i - minBefore[i])*arr[i];
			if (minBefore[i] > -1) {
				dp[i] += dp[minBefore[i]];
			}
			sum += dp[i];
			while (sum > pow(10, 9) + 7)
			{
				sum -= pow(10, 9) + 7;
			}
		}

		return sum;
	}
};
#endif // DYNAMIC_PROGRAMMING_SET

#ifdef MONOTONIC_STACK_DYNAMIC_PROGRAMMING
class Solution {
public:
	int sumSubarrayMins(std::vector<int>& arr) {
		// 动态规划
		// 假设 dp[i] 是所有以第 i 位为结尾的所有连续子数组的最小值和
		// 那么考虑第 dp[i+1] 位，从 dp[i+1] 向前遍历，找到第一个索引 k，满足 arr[k] <= dp[i+1]
		// 则 dp[i+1] = dp[k] + (i+1-k) * arr[i+1]

		// 单调栈来获得每一位向左遍历第一个小于的索引
		std::stack<int> monotonic;
		std::vector<int> minBefore(arr.size(), -1);
		int i = 0;
		while (true) {
			if (i >= arr.size()) {
				break;
			}
			if (monotonic.size() == 0) {
				minBefore[i] = -1;
			}
			else {
				int index = monotonic.top();
				if (arr[index] < arr[i]) {
					minBefore[i] = index;
				}
				else {
					monotonic.pop();
					continue;
				}
			}
			monotonic.emplace(i);
			i++;
		}

		long sum = 0;
		std::vector<int> dp(arr.size(), 0);
		dp[0] = arr[0];
		sum += dp[0];
		for (int i = 1; i < arr.size(); i++) {
			dp[i] = (i - minBefore[i])*arr[i];
			if (minBefore[i] > -1) {
				dp[i] += dp[minBefore[i]];
			}
			sum += dp[i];
			while (sum > pow(10, 9) + 7)
			{
				sum -= pow(10, 9) + 7;
			}
		}

		return sum;
	}
};
#endif // MONOTONIC_STACK_DYNAMIC_PROGRAMMING

#endif // __leet_code_907__