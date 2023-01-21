/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-21 10:26:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1824.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-21 11:50:07
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 748ms, 11.52%, MEMORY 313.1MB and 10.99%
 */

#ifndef __leet_code_1824_h__
#define __leet_code_1824_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int minSideJumps(std::vector<int>& obstacles) {
		// ��̬�滮���� dp[i][j] ��ʾ���� i �� j+1 �ܵ�ʱ�����ٵĲ�������
		// ��ʼ����£��У�dp[0][0] = 1, dp[0][1] = 0, dp[0][2] = 1
		// ���� i ����ĵ� j ���ܵ����ϰ���� dp[i][j] = MAX // -1 ��ʾ������
		// ���� i - 1 ����ĵ� j ���ܵ��������ϰ���� dp[i][j] ������ dp[i-1][j] ת�ƶ���
		// ���� i ����ĵ� j ���ܵ��͵� k ���ܵ����ϰ���� dp[i][j] ������ dp[i][k] ת�ƶ���

		std::vector<std::vector<int>> dp(obstacles.size(), std::vector<int>(3, std::numeric_limits<int>::max()));
		dp[0][0] = 1;
		dp[0][1] = 0;
		dp[0][2] = 1;

		for (int i = 1; i < obstacles.size(); i++) {
			for (int j = 0; j < 3; j++) {
				if (obstacles[i] == j + 1) {
					continue;
				}
				
				// �� i - 1 �� i ����״̬ת��
				if (obstacles[i - 1] != j + 1) {
					dp[i][j] = dp[i - 1][j];
				}
			}
			// ���в���ת��
			for (int j = 0; j < 3; j++) {
				int min_step = dp[i][j];
				for (int k = 0; k < 3; k++) {
					if (j == k || dp[i][k] == std::numeric_limits<int>::max()) {
						continue;
					}
					min_step = min_step < dp[i][k] + 1 ? min_step : dp[i][k] + 1;
				}
				dp[i][j] = min_step;
			}
		}

		int n = obstacles.size();
		int result = dp[n - 1][0] < dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
		result = result < dp[n - 1][2] ? result : dp[n - 1][2];

		return result;
	}
};

#endif // __leet_code_1824_h__