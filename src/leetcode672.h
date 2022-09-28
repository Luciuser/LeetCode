/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-15 15:52:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode672.h
 * @Description: create the file and ITERATROR_METHOD and SLIDE_WINDOW_METHOD
 */

 /*
 * @EditTime: 2022-09-27 11:40:44
 * @Editor: Bingyang Jin
 * @Description: create WRITE_TABLE_METHOD, TIME 0ms, 100.00%, MEMORY 5.8MB and 65.18%
 */

#ifndef __leet_code_672__
#define __leet_code_672__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
	int flipLights(int n, int presses) {
		// ���ڵ� 1 2 3 4 5 6 7 8 9 10 ���� ���ԣ�����7�ŵƸ���1�ŵƣ�6�š�8�ŵƸ���2�ŵƣ�5�ŵơ�9�ŵƸ���3�ŵƣ�10�ŵƸ���4�ŵơ�
		// ��˵� n>4 ʱ��ֻ���ж�ǰ4���Ƽ���

		// �� n>=3 ʱ��presses = 1���� 4 �ֿ���
		// �� n>=3 ʱ��presses = 2���� 7 �ֿ���
		// �� n>=3 ʱ��presses = 3���� 8 �ֿ���
		// �� n>=3 ʱ��presses = 4���� 8 �ֿ���
		// ��˵� n>=3 �� presses >= 3 ʱ���� 8 �ֿ���

		// ͬ����� n == 2 �� n == 1 �Ŀ�����

		if (n >= 3) {
			if (presses == 0) {
				return 1;
			}
			else if (presses == 1) {
				return 4;
			}
			else if (presses == 2) {
				return 7;
			}
			else {
				return 8;
			}
		}
		else if (n == 2) {
			if (presses == 0) {
				return 1;
			}
			else if (presses == 1) {
				return 3;
			}
			else {
				return 4;
			}
		}
		else {
			if (presses == 0) {
				return 1;
			}
			else {
				return 2;
			}
		}


	}
};

#endif // __leet_code_672__