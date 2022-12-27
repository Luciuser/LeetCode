/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-26 00:18:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode862.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-26 16:14:15
 * @Editor: Bingyang Jin
 * @Description: create PREFIX_DEQUE_METHOD, TIME 224ms, 24.05%, MEMORY 102.4MB and 32.32%
 */

#ifndef __leet_code_862__
#define __leet_code_862__

#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {
		// 令前缀和 S[i][j] = a[i] + a[i+1] + …… + a[j-2] + a[j-1]，共计 j - i 个数之和
		// 则题目所求为所有的 S[i][j] = k 中，j - i 最小的一个
		// 可计算前缀和 S[0][i] = a[0] + a[1] + …… + a[j-2] + a[j-1]，则 S[i][j] = S[0][j] - S[0][i] = k   ==>   S[0][i] = S[0][j] - k
		// 可从左往右遍历 S[0][j]，若存在 S[0][i] 满足 S[0][i] = S[0][j] - k，则有一个符合题意的解，此时判断 min 与 j-i 即可
		//	之后将 S[0][j] 加入 map 中，为保证 j-i 最小，每次可直接替换 map 中的索引，将其改为最大值即可


	// 计算前缀和，O(n)
		std::vector<int> prefix(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		// 一次遍历
		bool find = false;
		int min = std::numeric_limits<int>::max();
		std::unordered_map<int, int> prefixIndex; // 前缀和出现在第几个索引处
		for (int i = 0; i < prefix.size(); i++) {
			int destination = prefix[i] - k;
			if (prefixIndex.count(destination) != 0) {
				int j = prefixIndex[destination];
				find = true;
				if (i - j < min) {
					min = i - j;
				}
			}
			prefixIndex[prefix[i]] = i;
		}

		if (find) {
			return min;
		}

		return -1;
	}
};

#endif // __leet_code_862__