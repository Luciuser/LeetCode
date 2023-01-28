/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-28 10:12:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1664.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-28 10:29:25
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 108ms, 60.42%, MEMORY 92.1MB and 65.62%
 */

#ifndef __leet_code_1664_h__
#define __leet_code_1664_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int waysToMakeFair(std::vector<int>& nums) {
		
		int result = 0;
		std::vector<int> sum_left(2, 0); // �ָ�����������±���Լ�ż���±��
		std::vector<int> sum_right(2, 0); // �ָ���Ҳ�������±���Լ�ż���±��
		for (int i = 0; i < nums.size(); i++) {
			sum_right[i % 2] += nums[i];
		}

		int before = 0;
		for (int i = 0; i < nums.size(); i++) {
			// ÿ�θ���ָ��ʱ����� index ����һ����һ���ָ������Ҳ��ȥ��ǰ�ָ���
			sum_left[(i + 1) % 2] += before;
			sum_right[i % 2] -= nums[i];
			before = nums[i];

			if (sum_left[0] + sum_right[1] == sum_left[1] + sum_right[0]) {
				result++;
			}
		}

		return result;
	}
};

#endif // __leet_code_1664_h__