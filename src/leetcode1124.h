/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-14 00:03:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1124.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-14 16:13:31
 * @Editor: Bingyang Jin
 * @Description: create PREFIX_MONOTONIC_METHOD, TIME 20ms, 89.33%, MEMORY 22.1MB and 62.33%
 */

 /*
 * @EditTime: 2023-02-14 16:39:49
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 32ms, 29.00%, MEMORY 23.1MB and 19.34%
 */

#ifndef __leet_code_1124_h__
#define __leet_code_1124_h__

#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>

//#define PREFIX_MONOTONIC_METHOD // 前缀和+单调栈法，TIME 20ms, 89.33%, MEMORY 22.1MB and 62.33%
#define HASH_METHOD // 哈希表法

#ifdef HASH_METHOD
class Solution {
public:

	int longestWPI(std::vector<int>& hours) {

		// 建立前缀和数组
		std::vector<int>prefix(hours.size() + 1, 0); // 前缀和数组
		for (int i = 0; i < hours.size(); i++) {
			if (hours[i] > 8) {
				prefix[i + 1] = prefix[i] + 1;
			}
			else {
				prefix[i + 1] = prefix[i] - 1;
			}
		}
		// 一边建立哈希表，一边从哈希表中取值
		std::unordered_map<int, int> value_to_index;// 某个前缀和的值所对应的最小索引
		int max = 0;
		for (int right = 0; right < hours.size() + 1; right++) {
			if (prefix[right] > 0) {
				max = right > max ? right : max;
			}
			else {
				if (value_to_index.count(prefix[right] - 1) != 0) {
					int length = right - value_to_index[prefix[right] - 1];
					max = length > max ? length : max;
				}
				if (value_to_index.count(prefix[right]) == 0) {
					value_to_index[prefix[right]] = right;
				}
			}
		}

		return max;
	}
};
#endif // HASH_METHOD

#ifdef PREFIX_MONOTONIC_METHOD
class Solution {
public:

	int longestWPI(std::vector<int>& hours) {

		// 根据单调栈思想建立单调递减栈，存储前缀和数组中可能地左侧边界
		std::vector<int>prefix(hours.size() + 1, 0); // 前缀和数组
		std::stack<int> left_monotonic_stack; // 左侧边界的单调栈
		int before = 0;
		left_monotonic_stack.emplace(0);
		for (int i = 0; i < hours.size(); i++) {
			if (hours[i] > 8) {
				prefix[i + 1] = prefix[i] + 1;
			}
			else {
				prefix[i + 1] = prefix[i] - 1;
				if (prefix[i + 1] < before) {
					before = prefix[i + 1];
					left_monotonic_stack.emplace(i + 1);
				}
			}
		}

		int max = 0;
		for (int right = hours.size(); right >= 0; right--) {
			if (right < max) {
				break;
			}
			while (true) {
				if (left_monotonic_stack.size() == 0) {
					break;
				}
				int left = left_monotonic_stack.top();
				if (left >= right) {
					left_monotonic_stack.pop();
				}
				else if (prefix[left] < prefix[right]) {
					if (max < right - left) {
						max = right - left;
					}
					left_monotonic_stack.pop();
				}
				else {
					break;
				}
			}
		}

		return max;
	}
};
#endif // PREFIX_MONOTONIC_METHOD

#endif // __leet_code_1124_h__