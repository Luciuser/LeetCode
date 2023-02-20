/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-18 16:41:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode31.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-20 11:16:17
 * @Editor: Bingyang Jin
 * @Description: create POINTER_METHOD, TIME 4ms, 72.07%, MEMORY 11.7MB and 46.17%
 */

#ifndef __leet_code_31_h__ 
#define __leet_code_31_h__

#include<iostream>
#include<vector>

class Solution {
public:
	void nextPermutation(std::vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) {
			return;
		}

		int max = n - 1; // �Ӻ���ǰ����ʱ������һ�������ڵ�λ��
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] > nums[max]) {
				max = i;
			}
			else if (nums[i] < nums[max]) {
				// �� i λ��С�ˣ���ʼ���е���
				for (int j = n - 1; j >= i; j--) {
					if (nums[j] > nums[i]) {
						int temp = nums[i];
						nums[i] = nums[j];
						nums[j] = temp;
						break;
					}
				}
				for (int left = i + 1, right = n - 1; left < right; left++, right--) {
					int temp = nums[left];
					nums[left] = nums[right];
					nums[right] = temp;
				}

				return;
			}
		}

		// �������鶼�ǴӴ�С���У���ֱ�ӷ��ش�С���������
		for (int left = 0, right = n - 1; left < right; left++, right--) {
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
		}
		return;
	}

};

#endif // __leet_code_31_h__