/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-08
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6283.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 327
 */

#ifndef __leet_code_6283_h__
#define __leet_code_6283_h__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:

	long long maxKelements(std::vector<int>& nums, int k) {

		std::map<long long, long long, std::greater<long long>> number;
		for (int i = 0; i < nums.size(); i++) {
			number[nums[i]]++;
		}

		long long result = 0;

		for (auto iter = number.begin(); iter != number.end() && k != 0; iter++) {
			if ((*iter).first == 1) {
				result += k;
				break;
			}
			if ((*iter).second >= k) {
				result += (*iter).first * k;
				break;
			}
			else {
				result += (*iter).first * (*iter).second;
				k -= (*iter).second;
				long long new_key = (*iter).first / 3;
				if ((*iter).first % 3 > 0) {
					new_key++;
				}
				int new_value = (*iter).second;
				(*iter).second = 0;
				number[new_key] += new_value;
			}
		}

		return result;
	}
};


#endif // __leet_code_6283_h__