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
		// ��̬�滮���� dp[i] Ϊǰ i ��Ͷ�����ܹ�Ͷ��������������
		// �ö�ջ���洢������ dp[i] �����������У��Բ�ͬ���������� 1��2��3��4��5��6 Ϊ��β���������������� number_stack ��ʾ
		// �ڵ� dp[i] �� dp[i+1] ת��ʱ��number_queue[0] ����һ��һ���µ��� a��a ��ʾ���н�β��Ϊ 1 �������ڽ�β����һ�� 1 ֮�����õ��������е��ܺͣ���� a = dp[i] - number_sum[0];
		// �ڵ� dp[i] �� dp[i+1] ת��ʱ���� number_queue[0] �� size ������ rollMax[0]��˵�� number_queue[0] ����ͷ����������У����������� 1���õ�һ��������ĩβΪ���� 1 �����У����ֱ�ӳ�ջ��dp[i+1] ��ȥ��Ӧֵ

		long long dp = 6; // �� 1 ��Ϊ 6
		int MOD = 1e9 + 7;
		std::vector<long long> number_sum(6, 1); // ĩβΪ i �����ܹ��ж��ٸ�
		std::vector<std::queue<long long>> number_queue(6); // ����Ϊ n���� vector �����Ϊ x ��ĳ��ջ��ͷ���� i ������ i �� 0 ��ʼ������ʾ dp ���������У�ĩβΪ (n - i) λ (x - 1) ���������ж��ٸ�
		for (int i = 0; i < 6; i++) {
			number_queue[i].emplace(1);
		}

		std::vector<long long>only_one_end(6); // ĩβֻ��һ�� (j + 1) ���ֵ���������
		for (int i = 2; i <= n; i++) {
			// �����
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
			
			// number_all �� dp ������Ӧ����������
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

			// �����У�number_all �� dp ��ȥ��Ӧ��������
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