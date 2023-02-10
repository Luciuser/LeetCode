/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-10 13:38:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1223.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-10 14:37:29
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 16ms, 81.52%, MEMORY 8.4MB and 73.91%
 */

#ifndef __leet_code_1223_h__
#define __leet_code_1223_h__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
	int dieSimulator(int n, std::vector<int>& rollMax) {
		// 动态规划，令 dp[i] 为前 i 次投骰子能够投出来的总序列数
		// 用堆栈来存储，上述 dp[i] 个总序列数中，以不同数量连续的 1，2，3，4，5，6 为结尾的总序列数，如下 number_stack 所示
		// 在第 dp[i] 向 dp[i+1] 转移时，number_queue[0] 塞入一个一个新的数 a，a 表示所有结尾不为 1 的数，在结尾增加一个 1 之后所得到的新序列的总和，因此 a = dp[i] - number_sum[0];
		// 在第 dp[i] 向 dp[i+1] 转移时，若 number_queue[0] 的 size 超过了 rollMax[0]，说明 number_queue[0] 队列头所代表的序列，不能再增加 1，得到一个更长的末尾为连续 1 的序列，因此直接出栈，dp[i+1] 减去相应值

		long long dp = 6; // 第 1 次为 6
		int MOD = 1e9 + 7;
		std::vector<long long> number_sum(6, 1); // 末尾为 i 的数总共有多少个
		std::vector<std::queue<long long>> number_queue(6); // 长度为 n，在 vector 的序号为 x 的某个栈从头向后第 i 个数（ i 从 0 开始），表示 dp 个总序列中，末尾为 (n - i) 位 (x - 1) 的序列数有多少个
		for (int i = 0; i < 6; i++) {
			number_queue[i].emplace(1);
		}

		std::vector<long long>only_one_end(6); // 末尾只有一个 (j + 1) 数字的新序列数
		for (int i = 2; i <= n; i++) {
			// 入队列
			for (int j = 0; j < 6; j++) {
				only_one_end[j] = dp - number_sum[j];
				while (only_one_end[j] < 0) {
					only_one_end[j] += MOD;
				}
				if (only_one_end[j] > MOD) {
					only_one_end[j] = only_one_end[j] % MOD;
				}
				number_queue[j].emplace(only_one_end[j]);
			}
			
			// number_all 和 dp 增加相应的新序列数
			for (int j = 0; j < 6; j++) {
				dp += only_one_end[j];
				if (dp > MOD) {
					dp = dp % MOD;
				}
				number_sum[j] += only_one_end[j];
				if (number_sum[j] > MOD) {
					number_sum[j] = number_sum[j] % MOD;
				}
			}

			// 出队列，number_all 和 dp 减去相应的序列数
			for (int j = 0; j < 6; j++) {
				if (number_queue[j].size() > rollMax[j]) {
					int delete_number = number_queue[j].front();
					number_queue[j].pop();
					dp -= delete_number;
					if (dp < 0) {
						dp += MOD;
					}
					number_sum[j] -= delete_number;
					if (number_sum[j] < 0) {
						number_sum[j] += MOD;
					}
				}
			}
		}

		return dp;
	}
};

#endif // __leet_code_1223_h__