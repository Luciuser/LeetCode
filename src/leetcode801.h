/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-10 13:06:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode801.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-10 13:43:41
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_METHOD, TIME 140ms, 71.48%, MEMORY 88MB and 91.41%
 */

#ifndef __leet_code_801__
#define __leet_code_801__

#include<iostream>
#include<vector>

class Solution {
public:
	int minSwap(std::vector<int>& nums1, std::vector<int>& nums2) {
		
		// �� dp[i][0] ��ʾǰ i ���������� i ����������ʱ�����ܵ����ٽ���������dp[i][1] ��ʾǰ i ���������� i ��������ʱ�����ܵ����ٽ���������
		// ������ĳһ�����ʱ��dp[i][0] = std::numeric_limits<int>::max() ���� dp[i][1] = std::numeric_limits<int>::max()
		// ��ÿһ�� i����ǰ�� i-1 ֻ������״̬�������߲���������Ӧһ�� dp[i-1][0] �� dp[i-1][1]
		// ��˶�̬�滮�Ĺ�ʽΪ��
		// ���� dp[i-1][j] < 0 ���ԣ�dp[i][0] = -1; dp[i][1] = -1;
		// ���� dp[i-1][j] > 0 ���ԣ��жϽ���ǰ�������Ƿ�����
		// ����������洢��ֻ���������� int ����
		
		int n = nums1.size();
		int dp_0 = 0; // �洢 dp[i-1][0]��ǰһ����������
		int dp_1 = 1; // �洢 dp[i-1][1]��ǰһ��������
		int intMax = std::numeric_limits<int>::max(); // �����״̬�޷�ʵ��

		for (int i = 1; i < n; i++) {
			// ���� dp_0 ���м���
			int dp_00 = intMax;
			int dp_10 = intMax;
			if (dp_0 < intMax) {
				if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
					// ���������������
					dp_00 = dp_0;
				}
				if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1]) {
					// �������������
					dp_10 = dp_0 + 1;
				}
			}

			// ���� dp_1 ���м���
			int dp_01 = intMax;
			int dp_11 = intMax;
			if (dp_1 < intMax) {
				if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
					// ���������������
					dp_01 = dp_1;
				}
				if (nums2[i] > nums2[i - 1] && nums1[i] > nums1[i - 1]) {
					// �������������
					dp_11 = dp_1 + 1;
				}
			}

			// ���� dp_0 �� dp_1
			dp_0 = dp_00 < dp_01 ? dp_00 : dp_01;
			dp_1 = dp_10 < dp_11 ? dp_10 : dp_11;
		}

		return dp_0 < dp_1 ? dp_0 : dp_1;
	}
};

#endif // __leet_code_801__