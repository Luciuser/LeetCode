/*
 * @Author: Bingyang Jin
 * @Date: 2024-02-01 09:42:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/lcp24.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-02-01 11:40:45
 * @Editor: Bingyang Jin
 * @Description: create ANSWER_METHOD, TIME 79ms, 100.00%, MEMORY 70.89MB and 22.22%
 */

#ifndef __lcp_24_h__ 
#define __lcp_24_h__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
	std::vector<int> numsGame(std::vector<int>& nums) {

		int n = nums.size();
		std::vector<int> result(n, 0);
		int MOD = 1000000007;

		// 题解内容：
		// 化简一：通过各个位置的加减操作使得 nums 满足 nums[i] + 1 = nums[i+1] 时，设最终结果 nums[0] = k，则有 nums[i] = k + i
		//                     操作数 s[k] = sum(nums[i] - k - i) = sum((nums[i] - i) - k) = sum(x[i] - k)，其中 x[i] = nums[i] - i。
		//               因此将 nums 进行操作满足条件 nums[0] = k，nums[i] + 1 = nums[i+1] 时的操作数 s[k]，与对 x 进行操作，使得 x[i] = k 的操作数完全相同
		//               故进行第一次化简，对 nums 进行预处理，构造 x 数组，将问题转换为构造相同数字数组的问题
		for (int i = 0; i < n; i++) {
			nums[i] -= i;
		}
		// 化简二：对于化简后的数组 nums 而言，通过各个位置的加减操作使得 nums 满足 nums[i] == k 时，
		//                     操作数为 s[k] = sum(nums[i] - k) 
		//               对 nums 按大小进行排序，并首尾各取一个构成一对，因此构成各队形式如：[a0, an-1]，[a1, an-2]，[a2, an-3]……
		//               显然，当 k 属于 [a0, an-1] 时的操作数 s[k] 要小于 k 不属于 [a0, an-1] 时的操作数，且后一个区间是前一个区间的子区间，可依次递推
		//               若 nums 的数量为偶数，且最后一个区间为 [az, az+1]，显然当 k 属于区间 [az, az+1] 的操作数最小，且该区间内处处相等
		//               若 nums 的数量为奇数，且最后一个区间为 [az]，显然当 k == az 时的操作数最小
		//               因此构造相同数字数组时的最优解，该相同数字为该数组中位数，考虑到 k 为整数，因此可取 k == az 时，取到最优解

		// 通过两个优化队列，动态求解 nums 数组前 i 位的中位数
		// 保证 left 是中位数左侧，right 是中位数右侧，且偶数个数时，left 与 right 的 size 相同，奇数个数时，left 比 right 多一个，可取最优解 k = left.top()，
		// 此时 left 所有数想要构造成 k 的操作数为 k*left.size() - left_sum，right 所有数想要构造成 k 的操作数为 right_sum - k*right.size()，
		// 当 nums 的数量为偶数时，left.size() == right.size()，总操作数 s = right_sum - k*right.size() + k*left.size() - left_sum = right_sum - left_sum，
		// 当 nums 的数量为奇数时，left.size() == right.size() + 1，
		//       总操作数 s = right_sum - k*right.size() + k*left.size() - left_sum = right_sum - k*right.size() + k*right.size() + k - left_sum = right_sum - left_sum + left.top()。
		std::priority_queue<int, std::vector<int>> left;
		std::priority_queue<int, std::vector<int>, std::greater<int>> right;
		long long left_sum = 0;
		long long right_sum = 0;

		left.emplace(nums[0]);
		left_sum += nums[0];
		for (int i = 1; i < n; i++) {
			if (nums[i] < left.top()) {
				left.emplace(nums[i]);
				left_sum += nums[i];
			}
			else {
				right.emplace(nums[i]);
				right_sum += nums[i];
			}

			if (left.size() < right.size()) {
				int temp = right.top();
				right.pop();
				left.emplace(temp);
				left_sum += temp;
				right_sum -= temp;
			}
			else if (left.size() > right.size() + 1) {
				int temp = left.top();
				left.pop();
				right.emplace(temp);
				left_sum -= temp;
				right_sum += temp;
			}

			long long temp = ((i + 1) % 2 == 0) ? right_sum - left_sum : right_sum - left_sum + left.top();
			if (temp > MOD) {
				temp %= MOD;
			}

			result[i] = temp;
		}


		return result;
	}
};

#endif // __lcp_24_h__