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

		int max = n - 1; // 从后向前遍历时，最大的一个数所在的位置
		for (int i = n - 2; i >= 0; i--) {
			if (nums[i] > nums[max]) {
				max = i;
			}
			else if (nums[i] < nums[max]) {
				// 第 i 位数小了，开始进行调换
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

		// 整个数组都是从大到小排列，则直接返回从小到大的排列
		for (int left = 0, right = n - 1; left < right; left++, right--) {
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
		}
		return;
	}

};

#endif // __leet_code_31_h__