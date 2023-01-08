/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-07 09:27:36
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1658.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-07 10:08:24
 * @Editor: Bingyang Jin
 * @Description: create BFS_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-01-07 10:36:04
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 132ms, 61.59%, MEMORY 96.2MB and 57.62%
 */

#ifndef __leet_code_1658__
#define __leet_code_1658__

#include<iostream>
#include<numeric>
#include<stack>
#include<unordered_map>
#include<vector>

//#define BFS_METHOD // BFS 遍历，超时
#define SLIDE_WINDOW_METHOD // 滑动窗口法

#ifdef DEBUG
class Solution {
public:

	struct PairHash {
		template <typename T, typename U>
		std::size_t operator()(const std::pair<T, U> &x) const {
			return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
		}
	};

	int minOperations(std::vector<int>& nums, int x) {

		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum < x) {
			return -1;
		}

		// BFS 方法
		int n = nums.size();
		std::stack<std::vector<int>> positions;
		std::vector<int> begin = { 0, n - 1, x };
		positions.emplace(begin);

		while (positions.size() > 0) {
			std::unordered_map<std::pair<int, int>, int, PairHash> new_positions;
			while (positions.size() > 0) {
				int left = positions.top()[0];
				int right = positions.top()[1];
				int value = positions.top()[2];
				positions.pop();

				// 当 left 和 right 相同时
				if (left == right) {
					if (value - nums[left] == 0) {
						return n;
					}
					else {
						continue;
					}
				}

				// 减去 nums[left] 和 nums[right] 进行尝试
				int subtract_left = value - nums[left];
				int subtract_right = value - nums[right];
				if (subtract_left == 0 || subtract_right == 0) {
					return n - (right - left);
				}
				if (subtract_left > 0) {
					new_positions[std::pair<int, int>(left + 1, right)] = subtract_left;
				}
				if (subtract_right > 0) {
					new_positions[std::pair<int, int>(left, right - 1)] = subtract_right;
				}
			}

			for (auto iter = new_positions.begin(); iter != new_positions.end(); iter++) {
				std::vector<int> temp = { (*iter).first.first, (*iter).first.second, (*iter).second };
				positions.emplace(temp);
			}
		}

		return -1;
	}
};
#endif // DEBUG

#ifdef SLIDE_WINDOW_METHOD
class Solution {
public:
	int minOperations(std::vector<int>& nums, int x) {
		int n = nums.size();
		int left = -1, right = 0; // (left, right) 表示剩余的部分
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum < x) {
			return -1;
		}

		int result = -1;
		for (; left < n; left++) {
			if (left != -1) {
				sum += nums[left];
			}
			if (right == n && sum > x) {
				break;
			}
			while (right <= n && sum > x) {
				sum -= nums[right];
				right++;
			}

			if (sum == x) {
				int temp = (left + 1) + (n - right);
				if (result == -1) {
					result = temp;
				}
				else if (result > temp) {
					result = temp;
				}
			}

		}
		
		return result;
	}
};
#endif // SLIDE_WINDOW_METHOD

#endif // __leet_code_1658__