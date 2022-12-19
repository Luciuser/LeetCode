/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-18 00:07:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1703.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-17 17:04:10
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOWS_METHOD, out of TIME
 */

 /*
 * @EditTime: 2022-12-17 17:04:10
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_MID_METHOD, TIME 112ms, 70.07%, MEMORY 122.5MB and 23.13%
 */

#ifndef __leet_code_1703__
#define __leet_code_1703__

#include<iostream>
#include<vector>
#include<queue>

#define SLIDE_WINDOWS_METHOD // 滑动窗口法，超时
#define GREEDY_MID_METHOD // 贪心+中位数+前缀和法，具体原理可参见题解，TIME 112ms, 70.07%, MEMORY 122.5MB and 23.13%

#ifdef SLIDE_WINDOWS_METHOD
class Solution {
public:

	int minMovesWithVec(std::vector<int>&ones, int begin, int k) {
		// 通过反证法可证明，若对于 a1<a2<……<ak，且有 begin, begin+1, begin+2,……,bgein+k
		// 那么前后任意两项之差的绝对值之和的最小值，是
		// |a1 - begin| + |a2 - begin - 1| + …… + |ak - begin - k|
		int result = 0;
		for (int i = 0; i < k; i++) {
			result += abs(ones[i] - (begin + i));
		}
		return result;
	}

	int minMovesWithVec(std::queue<int>ones, int begin, int k) {
		// 通过反证法可证明，若对于 a1<a2<……<ak，且有 begin, begin+1, begin+2,……,bgein+k
		// 那么前后任意两项之差的绝对值之和的最小值，是
		// |a1 - begin| + |a2 - begin - 1| + …… + |ak - begin - k|
		int result = 0;
		for (int i = 0; i < k; i++) {
			int temp = ones.front();
			result += abs(temp - (begin + i));
			ones.pop();
		}
		return result;
	}

	int minMoves(std::vector<int>& nums, int k) {
		std::vector<int> ones;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				ones.push_back(i);
			}
		}

		int begin = 0; // 表示当前 [i, i+k] 范围内存在的 1，在 ones 中的索引的首位
		//int end = 0; // 表示当前 [i, i+k] 范围内存在的 1，在 ones 中的索引的末位
		int size = 0; // 表示当前 [i, i+k] 范围内存在的 1 的数目

		int result = std::numeric_limits<int>::max();
		for (int i = 0; i + k <= nums.size(); i++) {
			if (i == 0) {
				// 进行初始化
				for (int j = 0; j < k; j++) {
					if (nums[j] == 1) {
						size++;
					}
				}
			}
			else {
				if (nums[i - 1] == 1) {
					size--;
					begin++;
				}
				if (nums[i + k - 1] == 1) {
					size++;
				}
			}
			if (size < 0) {
				size = 0;
			}
			int times = k - size;
			if (times == 0) {
				result = 0;
				break;
			}

			int tempBegin = begin - times > 0 ? begin - times : 0;
			int tempEnd = begin + k < ones.size() ? begin + k : ones.size();
			std::queue<int> q;
			for (int j = tempBegin; j < tempBegin + k; j++) {
				q.emplace(ones[j]);
			}
			int answer = minMovesWithVec(q, i, k);
			if (answer < result) {
				result = answer;
			}
			for (int j = tempBegin + k; j < tempEnd; j++) {
				q.pop();
				q.emplace(ones[j]);
				answer = minMovesWithVec(q, i, k);
				if (answer < result) {
					result = answer;
				}
			}
		}

		return result;

	}
};
#endif // SLIDE_WINDOWS_METHOD

#ifdef GREEDY_MID_METHOD
class Solution {
public:
	int minMoves(std::vector<int>& nums, int k) {
		std::vector<int> g;
		std::vector<int> preSum(1, 0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				g.emplace_back(i - g.size());
				preSum.emplace_back(preSum.back() + g.back());
			}
		}
		int m = g.size(), res = INT_MAX;
		for (int i = 0; i <= m - k; i++) {
			int mid = i + k / 2;
			res = std::min(res, (1 - k % 2) * g[mid] + \
				(preSum[i + k] - preSum[mid + 1]) - \
				(preSum[mid] - preSum[i]));
		}
		return res;
	}
};
#endif // GREEDY_MID_METHOD



#endif // __leet_code_1703__