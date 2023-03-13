/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6317.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 336
 */

#ifndef __leet_code_6317_h__
#define __leet_code_6317_h__

#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
	long long beautifulSubarrays(std::vector<int>& nums) {
		// 异或遍历
		// 前缀异或数组
		std::vector<int> prefix(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); i++) {
			prefix[i] = prefix[i - 1] ^ nums[i - 1];
		}

		long long result = 0;
		std::unordered_map<int, int> v2f;
		for (int i = 0; i < prefix.size(); i++) {
			if (v2f.count(prefix[i]) == 0) {
				v2f[prefix[i]]++;
			}
			else {
				result += v2f[prefix[i]];
				v2f[prefix[i]]++;
			}
		}

		return result;
	}
};


#endif // __leet_code_6317_h__