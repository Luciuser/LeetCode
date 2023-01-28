/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-24 14:51:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1814.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-24 15:04:44
 * @Editor: Bingyang Jin
 * @Description: create UNORDERED_MAP_METHOD, TIME 172ms, 15.77%, MEMORY 55.3MB and 83.33%
 */

#ifndef __leet_code_1814_h__
#define __leet_code_1814_h__

#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

class Solution {
private:
	int getRevNum(int x) {
		std::string temp = std::to_string(x);
		int result = 0;
		for (int i = 0; i < temp.size(); i++) {
			result = result * 10 + temp[temp.size() - 1 - i] - '0';
		}

		return result;
	}

public:
	int countNicePairs(std::vector<int>& nums) {
		std::unordered_map<int, int>frequence;
		for (int i = 0; i < nums.size(); i++) {
			int temp = nums[i] - getRevNum(nums[i]);
			frequence[temp]++;
		}

		long long result = 0;
		long long MOD = 1e9 + 7;
		for (auto iter = frequence.begin(); iter != frequence.end(); iter++) {
			long long n = (*iter).second;
			result += n * (n - 1) / 2;
			if (result >= MOD) {
				result = result % MOD;
			}
		}

		return result;
	}
};

#endif // __leet_code_1814_h__