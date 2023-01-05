/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-04 12:40:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1802.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-04 13:22:20
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 4ms, 53.04%, MEMORY 5.8MB and 55.25%
 */

#ifndef __leet_code_1802__
#define __leet_code_1802__

#include<iostream>

class Solution {
public:
	int maxValue(int n, int index, int maxSum) {

		// �ɶԳ��ԣ����Խ� index ӳ����������鷶Χ��
		// ������Զ����ȵ���߽磬�Ҳ�󵽴�߽�
		if ( 1.0 * index >= 1.0 * n / 2) {
			index = n - 1 - index;
		}
		long long t = index;

		// ��С����£����������Ϊ 1
		long long sum = n;
		long long add = maxSum - sum; // ��Ҫ���ӵ�����
		int max = 1; // ���ս��

		// ���㵱������������� 0 ���ʱ�������������ӵ����ֺ�
		// ��๲�� index �����֣����ݵ���������͹�ʽ�ɵ�
		long long left_left = (1 + t) * t / 2; // ��������ܹ����ӵĺ�
		long long left_middle = index + 1; // �� index ���������ӵĺ�
		long long left_sum = left_left * 2 + left_middle;
		if (left_sum > add) {
			// �Ѿ�����������������δ�ﵽ 0 ���ʱ�����Ѿ�����������������������
			long long temp_sum = -1;
			while (add >= 0) {
				max++;
				temp_sum += 2;
				add -= temp_sum;
			}
			max--;
			return max;
		}

		// ���㵱�Ҳ����������� n-1 ���ʱ�������������ӵ����ֺ�
		// �Ҳ��ʱ������ 2 * index + 1�����ݵ���������͹�ʽ�ɵ�
		add -= left_sum;
		max = index + 2;
		long long right_sum = ((2 * t + 2) + n) * (n - (2 * t + 2) + 1) / 2;
		if (right_sum > add) {
			// �Ѿ�������������Ҳ���δ�ﵽ n-1 ���ʱ�����Ѿ�����������������������
			long long temp_sum = 2 * index + 1;
			while (add >= 0) {
				max++;
				temp_sum += 1;
				add -= temp_sum;
			}
			max--;
			return max;
		}

		// ���ÿ�����ӹ̶�����ֵ n��ֱ������õ��������
		add -= right_sum;
		max += (n - (2 * index) - 2 + 1);
		max = max + add / n;
		return max;
	}
};

#endif // __leet_code_1802__