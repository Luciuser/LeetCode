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
		
		// ��������ӷ�״̬ѹ��+��̬�滮
		// ���������ӹ���10������ÿ��������������1�Σ����������ӽ���״̬ѹ��
		// int mask������ mask �ĴӺ���ǰ�� 10 λ�ֱ��ʾ prime_factor �� 10 ���������Ƿ��Ѿ����� 
		// �� dp[i][m] ��ʾǰ i �������������״̬Ϊ m �ķ��������� dp[i][m] ������ô���ж�̬�滮��
		//			dp[i+1][m] = dp[i-1][m] + sum(dp[i-1][m])
		// ��ʽ���Ҳ��һ��Ϊ������� i ����ʱ��״̬Ϊ m �ķ������ڶ���Ϊ����� i ����ʱ��״̬Ϊ m �ķ���

		const int MOD = 1e9 + 7;
		const int MASK = 10;
		const int MASK_LENGTH = 1 << MASK;
		int n = nums.size();
		std::vector<std::vector<long long>> dp(n, std::vector<long long>(MASK_LENGTH, 0));

		// ��ʼ��
		if (is_wrong_number(nums[0]) == false) {
			int mask = get_mask(nums[0]);
			dp[0][mask] = 1;
		}

		for (int i = 1; i < n; i++) {
			// ���㲻����� i ����ʱ������״̬�ķ���
			for(int j=0;j<MASK_LENGTH; j++){
				dp[i][j] = dp[i - 1][j];
			}
			
			// ����Ƿ���ƽ����
			if (is_wrong_number(nums[i])) {
				continue;
			}

			// ����� i �����������ӷֽ����
			int mask = get_mask(nums[i]);

			// ֻ������ i �����ķ���
			dp[i][mask]++;
			
			// �������� i ����֮��ķ�����
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