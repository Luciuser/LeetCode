/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-01 09:08:21
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode769.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-01 09:23:14
 * @Editor: Bingyang Jin
 * @Description: create MIN_MAX_METHOD, TIME 0ms, 100.00%, MEMORY 6.9MB and 67.02%
 */

#ifndef __leet_code_769__
#define __leet_code_769__

#include<iostream>
#include<vector>
#include<string>

//#define MIN_MAX_METHOD // 用最小值最大值双指针进行求解，TIME 0ms, 100.00%, MEMORY 6.9MB and 67.02%
#define MAX_METHOD // 用最大值指针进行求解，TIME 0ms, 100.00%, MEMORY 7MB and 70.00%

#ifdef MIN_MAX_METHOD
class Solution {
public:
	int maxChunksToSorted(std::vector<int>& arr) {
		int sum = 0;
		int max = -1;
		int min = -1;
		int current = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == current && max == -1) {
				sum++;
				current++;
				continue;
			}

			if (max == -1) {
				min = arr[i];
				max = arr[i];
			}
			else {
				min = min <= arr[i] ? min : arr[i];
				max = max >= arr[i] ? max : arr[i];
				if (min == current && max == i) {
					sum++;
					current = i + 1;
					min = -1;
					max = -1;
				}
			}

		}

		return sum;
	}
};
#endif // MIN_MAX_METHOD

#ifdef MAX_METHOD
class Solution {
public:
	int maxChunksToSorted(std::vector<int>& arr) {
		int m = 0, res = 0;
		for (int i = 0; i < arr.size(); i++) {
			m = m > arr[i] ? m : arr[i];
			if (m == i) {
				res++;
			}
		}
		return res;
	}
};
#endif // MAX_METHOD

#endif // __leet_code_769__