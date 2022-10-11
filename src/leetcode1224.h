/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-11 08:56:43
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1224.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-11 10:07:42
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 140ms, MEMORY 43.7MB
 */

#ifndef __leet_code_1224__
#define __leet_code_1224__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:

	int maxEqualFreq(std::vector<int>& nums) {

		std::unordered_map<int, int> freq, count;
		int res = 0, maxFreq = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (count[nums[i]] > 0) {
				freq[count[nums[i]]]--;
			}
			count[nums[i]]++;
			if (count[nums[i]] > maxFreq) {
				maxFreq = count[nums[i]];
			}
			freq[count[nums[i]]]++;
			bool ok = maxFreq == 1 ||
				freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
				freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
			if (ok) {
				res = i + 1;
			}
		}
		return res;
	}
};

#endif // __leet_code_1224__