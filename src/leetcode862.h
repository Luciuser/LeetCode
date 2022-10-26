/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-26 00:18:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode862.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-25 09:48:15
 * @Editor: Bingyang Jin
 * @Description: create SINGLE_ERGODIC_METHOD, TIME 4ms, 43.49%, MEMORY 7.5MB and 93.74%
 */

#ifndef __leet_code_862__
#define __leet_code_862__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {

		// 令前缀和 S[i][j] = a[i] + a[i+1] + …… + a[j-2] + a[j-1]，共计 j - i 个数之和
		// 则题目所求为所有的 S[i][j] = k 中，j - i 最小的一个
		// 可计算前缀和 S[0][i] = a[0] + a[1] + …… + a[j-2] + a[j-1]，则 S[i][j] = S[0][j] - S[0][i] = k   ==>   S[0][i] = S[0][j] - k

		// 计算前缀和，O(n)
		std::vector<int> prefix(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}
		// 处理前缀和，当 存在 i<j 同时 prefix[i] > prefix[j] 时，可以直接删去 prefix[i]
		// 因为遍历至某个 k，当 i<j<k 时，若需满足 prefix[k] - prefix[m] > k，则当 i 成立时，j 一定成立。但此时 k-j < k-i，故无需考虑第 i 个前缀和
		//int prefixSize = 0;
		std::vector<bool> isDelete(prefix.size(), false);
		int before = prefix[prefix.size() - 1];
		for (int i = 1; i + 1 < prefix.size(); i++) {
			int current = prefix[prefix.size() - i - 1];
			if (current > before) {
				isDelete[prefix.size() - i - 1] = true;
			}
			else {
				before = current;
			}
		}
		std::vector<int> order;
		for (int i = 0; i < prefix.size(); i++) {
			if (isDelete[i] == false) {
				order.push_back(prefix[i]);
				//prefix[prefixSize] = prefix[i];
				//prefixSize++;
			}
		}

		// 二分法一次遍历
		bool find = false;
		int min = std::numeric_limits<int>::max();

		for (int i = 0; i < prefix.size(); i++) {
			int destination = prefix[i] - k;
			int index = std::lower_bound(order.begin(), order.end(), destination, std::less<>()) - order.begin();
			if (index < i && i - index < min) {
				find = true;
				min = i - index;
			}
		}

		if (find) {
			return min;
		}

		return -1;
	}
};

#endif // __leet_code_862__