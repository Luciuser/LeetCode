/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-234 12:10:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1460.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-23 12:17:23
 * @Editor: Bingyang Jin
 * @Description: create NORMAL, TIME 20ms, 9.88%, MEMORY 15MB and 22.75%
 */

#ifndef __leet_code_1460__
#define __leet_code_1460__

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

class Solution {
public:
	bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
		std::unordered_map<int, int>nums;
		for (int i = 0; i < target.size(); i++) {
			nums.count(target[i]) == 0 ? nums[target[i]] = 1 : nums[target[i]]++;
		}
		for (int i = 0; i < arr.size(); i++) {
			if (nums.count(arr[i]) == 0) {
				return false;
			}
			nums[arr[i]]--;
			if (nums[arr[i]] < 0) {
				return false;
			}
		}

		return true;
	}
};

#endif // __leet_code_1460__