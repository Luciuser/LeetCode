/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-04 14:55:00
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1145.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 10:59:22
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 104ms, 80.43%, MEMORY 65MB and 38.66%
 */

#ifndef __leet_code_1798_h__
#define __leet_code_1798_h__

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

class Solution {
public:
	int getMaximumConsecutive(std::vector<int>& coins) {

		// ���̰�ķ����ǳ����
		// �����Ѿ�ȡ����һ�������������ܹ��� [0, x] �����飬��ô��ȡ��һ�� y����һ�������ٹ��� [y, x+y] ������
		// �� y<=x+1�����ʱһ�����Թ��� [0, x+y] ������
		// Ϊ��������������ÿ�ο��Դ���Сֵȡ��

		std::sort(coins.begin(), coins.end());
		int result = 0;

		for (int i = 0; i < coins.size(); i++) {
			if (coins[i] <= result + 1) {
				result += coins[i];
			}
			else {
				break;
			}
		}

		return result + 1;
	}
};

#endif // __leet_code_1798_h__