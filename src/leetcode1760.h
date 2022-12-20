/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-20 00:04:05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1760.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-20 09:53:36
 * @Editor: Bingyang Jin
 * @Description: create AVERAGE_ADD_METHOD, OUT OF TIME
 */

 /*
 * @EditTime: 2022-12-20 10:18:50
 * @Editor: Bingyang Jin
 * @Description: create DISJOINT_SET_UNION_METHOD, TIME 236ms, 8.59%, MEMORY 54.6MB and 44.53%
 */

#ifndef __leet_code_1760__
#define __leet_code_1760__

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

//#define AVERAGE_ADD_METHOD // 从average开始累加，超时
#define DICHOTOMY_METHOD // 二分法，TIME 236ms, 8.59%, MEMORY 54.6MB and 44.53%

#ifdef AVERAGE_ADD_METHOD
class Solution {
public:

	int minimumSize(std::vector<int>& numSort, int index, int maxOperations) {
		long long sum = 0;
		for (int i = index; i < numSort.size(); i++) {
			sum += numSort[i];
		}
		int average = sum / (numSort.size() - index + maxOperations);
		if (sum % (numSort.size() - index + maxOperations) != 0) {
			average++;
		}

		while (true)
		{
			int operations = 0; // 当前操作总数
			int maxIndex = -1; // 第一个比 average 大的数的索引
			for (int i = index; i < numSort.size(); i++) {
				if (numSort[i] > average) {
					operations += numSort[i] / average - 1;
					if (numSort[i] % average != 0) {
						operations++;
					}
					if (maxIndex == -1) {
						maxIndex = i;
					}
				}
			}
			if (operations <= maxOperations) {
				break;
			}
			if (maxIndex == index) {
				average++;
			}
			else {
				average = minimumSize(numSort, maxIndex, maxOperations);
				break;
			}
		}

		return average;
	}


	int minimumSize(std::vector<int>& nums, int maxOperations) {

		std::sort(nums.begin(), nums.end(), [=](int a, int b) { return a < b; });
		int average = minimumSize(nums, 0, maxOperations);
		return average;
	}
};
#endif // AVERAGE_ADD_METHOD

#ifdef DICHOTOMY_METHOD
class Solution {
public:

	int minimumSize(std::vector<int>& nums, int maxOperations) {

		int left = 1;
		int right = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > right) {
				right = nums[i];
			}
		}

		// 二分法找对应值
		int result = std::numeric_limits<int>::max();
		while (left <= right) {
			int mid = (left + right) / 2;
			int operations = 0; // 当前操作总数
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] > mid) {
					operations += nums[i] / mid - 1;
					if (nums[i] % mid != 0) {
						operations++;
					}
				}
			}
			if (operations <= maxOperations) {
				if (mid < result) {
					result = mid;
				}
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		return result;
	}
};
#endif // DICHOTOMY_METHOD

#endif // __leet_code_1760__