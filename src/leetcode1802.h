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

		// 由对称性，可以将 index 映射至左半数组范围内
		// 这样永远左边先到达边界，右侧后到达边界
		if ( 1.0 * index >= 1.0 * n / 2) {
			index = n - 1 - index;
		}
		long long t = index;

		// 最小情况下，整个数组均为 1
		long long sum = n;
		long long add = maxSum - sum; // 需要增加的数字
		int max = 1; // 最终结果

		// 计算当左侧数字增长到 0 序号时，整个数组增加的数字和
		// 左侧共计 index 个数字，根据递增数列求和公式可得
		long long left_left = (1 + t) * t / 2; // 左侧数字总共增加的和
		long long left_middle = index + 1; // 第 index 个数字增加的和
		long long left_sum = left_left * 2 + left_middle;
		if (left_sum > add) {
			// 已经超过，因此在左侧尚未达到 0 序号时，即已经超过，遍历来计算结果即可
			long long temp_sum = -1;
			while (add >= 0) {
				max++;
				temp_sum += 2;
				add -= temp_sum;
			}
			max--;
			return max;
		}

		// 计算当右侧数字增长到 n-1 序号时，整个数组增加的数字和
		// 右侧此时增长到 2 * index + 1，根据递增数列求和公式可得
		add -= left_sum;
		max = index + 2;
		long long right_sum = ((2 * t + 2) + n) * (n - (2 * t + 2) + 1) / 2;
		if (right_sum > add) {
			// 已经超过，因此在右侧尚未达到 n-1 序号时，即已经超过，遍历来计算结果即可
			long long temp_sum = 2 * index + 1;
			while (add >= 0) {
				max++;
				temp_sum += 1;
				add -= temp_sum;
			}
			max--;
			return max;
		}

		// 最后，每次增加固定的数值 n，直接相除得到结果即可
		add -= right_sum;
		max += (n - (2 * index) - 2 + 1);
		max = max + add / n;
		return max;
	}
};

#endif // __leet_code_1802__