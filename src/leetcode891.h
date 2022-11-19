/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-18 08:54:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode831.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-18 10:23:30
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 120ms, 42.62%, MEMORY 52.6MB and 78.69%
 */

#ifndef __leet_code_891__
#define __leet_code_891__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int sumSubseqWidths(std::vector<int>& nums) {
		// 首先需注意一点，改变 nums 数组中元素的顺序，虽然会改变子序列出现的顺序及部分子序列内部的顺序，但子序列的数量不变，且每个子序列的宽度不变
		// 因此可以先对 nums 进行排序，随后进行动态规划
		// 动态规划
		// 设 dp[i] 表示索引到 i 后，前 i+1 个数字所形成的子序列的数量，计算重复，因此有：
		//							dp[0] = 1
		//							dp[i+1] = 2 * dp[i] + 1	
		// 设 max[i] 和 min[i] 分别表示第 i 个子序列中的最大值和最小值
		// 设 Max[i] 和 Min[i] 分别表示索引到 i 后，前 i+1 个数字所形成的 dp[i] 个子序列中的最大值、最小值和，计算重复，因此有：
		//							Max[i] = max[0] + max[1] + …… + max[dp[i] - 1]
		//							Min[i] = min[0] + min[1] + …… + min[dp[i] - 1]
		// 设 s[i] 表示索引到 i 后，前 i+1 个数字所形成的 dp[i] 个子序列的宽度和，计算重复，因此有：
		//							s[i] = (max[0] - min[0]) + (max[1] - min[1]) + …… + (max[dp[i] - 1] - min[dp[i] - 1])		==>
		//							s[i] = Max[i] - Min[i]
		// 对 nums 进行排序后，保证 nums[i] <= nums[i+1]
		// 因此有考虑 Max[i] 和 Min[i] 的动态规划，有：
		//							Min[i+1] = 2 * Min[i] + nums[i+1]
		//							Max[i+1] = Max[i] + dp[i] * nums[i+1] + nums[i+1]
		// 对 s[i] 进行迭代后，s[n] 即为所求答案

		// 排序，O(nlogn)
		std::sort(nums.begin(), nums.end());
		
		// 动态规划，其中 dp、Min、Max、s 均用一个数来表示即可
		long long dp = 1;
		long long Min = nums[0];
		long long Max = nums[0];
		long long s = Max - Min;
		long long MOD = 1e9 + 7;
		for (int i = 1; i < nums.size(); i++) {
			//std::cout << "dp: " << dp << std::endl;
			//std::cout << "Min: " << Min << std::endl;
			//std::cout << "Max : " << Max << std::endl;
			//std::cout << "nums : " << nums[i] << std::endl;

			Min = (2 * Min + nums[i]) % MOD;
			Max = (Max + dp * nums[i] + nums[i]) % MOD;
			dp = (2 * dp + 1) % MOD;
		}

		s = Max - Min;
		if (s < 0) {
			s += MOD;
		}

		return s;
	}
};

#endif // __leet_code_891__