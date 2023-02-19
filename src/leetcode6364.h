/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6365.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-19
 * @Editor: Bingyang Jin
 * @Description: create STATE_COMPRESSION_DYNAMIC_PROGRAMMING_METHOD, TIME 0ms, MEMORY 6MB
 */

#ifndef __leet_code_6364_h__ 
#define __leet_code_6364_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int squareFreeSubsets(std::vector<int>& nums) {
		
		// 题解质因子法状态压缩+动态规划
		// 由于质因子共计10个，且每个质因子最多出现1次，基于质因子进行状态压缩
		// int mask，其中 mask 的从后向前的 10 位分别表示 prime_factor 的 10 个质因子是否已经出现 
		// 设 dp[i][m] 表示前 i 个数组成质因子状态为 m 的方案共计有 dp[i][m] 个，那么进行动态规划：
		//			dp[i+1][m] = dp[i-1][m] + sum(dp[i-1][m])
		// 上式中右侧第一项为不加入第 i 个数时，状态为 m 的方案；第二项为加入第 i 个项时，状态为 m 的方案

		const int MOD = 1e9 + 7;
		const int MASK = 10;
		const int MASK_LENGTH = 1 << MASK;
		int n = nums.size();
		std::vector<std::vector<long long>> dp(n, std::vector<long long>(MASK_LENGTH, 0));

		// 初始化
		if (is_wrong_number(nums[0]) == false) {
			int mask = get_mask(nums[0]);
			dp[0][mask] = 1;
		}

		for (int i = 1; i < n; i++) {
			// 计算不加入第 i 个数时，各个状态的方案
			for(int j=0;j<MASK_LENGTH; j++){
				dp[i][j] = dp[i - 1][j];
			}
			
			// 检察是否是平方数
			if (is_wrong_number(nums[i])) {
				continue;
			}

			// 计算第 i 个数的质因子分解情况
			int mask = get_mask(nums[i]);

			// 只包含第 i 个数的方案
			dp[i][mask]++;
			
			// 计算加入第 i 个数之后的方案数
			for (int j = 0; j < MASK_LENGTH; j++) {
				int new_mask = mask | j;
				int compare = mask & j;
				if (compare == 0) {
					dp[i][new_mask] += dp[i - 1][j];
					if (dp[i][new_mask] > MOD) {
						dp[i][new_mask] = dp[i][new_mask] % MOD;
					}
				}
			}
		}

		long long sum = 0;
		for (int i = 0; i < MASK_LENGTH; i++) {
			sum += dp[n - 1][i];
			if (sum > MOD) {
				sum = sum % MOD;
			}
		}

		return sum;
	}

private:
	bool is_wrong_number(const int number) {
		for (int i = 0; i < wrong_number_.size(); i++) {
			if (wrong_number_[i] == number) {
				return true;
			}
		}
		return false;
	}

	int get_mask(const int number) {
		int mask = 0;
		if (number == 1) {
			return 0;
		}
		for (int i = 0; i < prime_factor_.size(); i++) {
			if (number%prime_factor_[i] == 0) {
				mask += (1 << i);
			}
		}
		return mask;
	}

	std::vector<int> wrong_number_ = { 4,8,12,16,20,24,28,9,18,27,25 };
	std::vector<int> prime_factor_ = { 2,3,5,7,11,13,17,19,23,29 };
};
#endif // __leet_code_6364_h__