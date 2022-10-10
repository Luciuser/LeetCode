/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-10 13:06:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode801.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-10 13:43:41
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_METHOD, TIME 140ms, 71.48%, MEMORY 88MB and 91.41%
 */

#ifndef __leet_code_801__
#define __leet_code_801__

#include<iostream>
#include<vector>

class Solution {
public:
	int minSwap(std::vector<int>& nums1, std::vector<int>& nums2) {
		
		// 令 dp[i][0] 表示前 i 个数，当第 i 个数不交换时，可能的最少交换次数；dp[i][1] 表示前 i 个数，当第 i 个数交换时，可能的最少交换次数；
		// 当其中某一项不成立时，dp[i][0] = std::numeric_limits<int>::max() 或者 dp[i][1] = std::numeric_limits<int>::max()
		// 对每一个 i，其前序 i-1 只有两个状态，换或者不换，均对应一个 dp[i-1][0] 和 dp[i-1][1]
		// 因此动态规划的公式为：
		// 对于 dp[i-1][j] < 0 而言，dp[i][0] = -1; dp[i][1] = -1;
		// 对于 dp[i-1][j] > 0 而言，判断交换前后增序是否满足
		// 无需用数组存储，只需额外的两个 int 即可
		
		int n = nums1.size();
		int dp_0 = 0; // 存储 dp[i-1][0]，前一个数不交换
		int dp_1 = 1; // 存储 dp[i-1][1]，前一个数交换
		int intMax = std::numeric_limits<int>::max(); // 如果该状态无法实现

		for (int i = 1; i < n; i++) {
			// 基于 dp_0 进行计算
			int dp_00 = intMax;
			int dp_10 = intMax;
			if (dp_0 < intMax) {
				if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
					// 不交换的情况满足
					dp_00 = dp_0;
				}
				if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1]) {
					// 交换的情况满足
					dp_10 = dp_0 + 1;
				}
			}

			// 基于 dp_1 进行计算
			int dp_01 = intMax;
			int dp_11 = intMax;
			if (dp_1 < intMax) {
				if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
					// 不交换的情况满足
					dp_01 = dp_1;
				}
				if (nums2[i] > nums2[i - 1] && nums1[i] > nums1[i - 1]) {
					// 交换的情况满足
					dp_11 = dp_1 + 1;
				}
			}

			// 更新 dp_0 和 dp_1
			dp_0 = dp_00 < dp_01 ? dp_00 : dp_01;
			dp_1 = dp_10 < dp_11 ? dp_10 : dp_11;
		}

		return dp_0 < dp_1 ? dp_0 : dp_1;
	}
};

#endif // __leet_code_801__