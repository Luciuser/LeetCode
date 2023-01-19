/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-14 11:09:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1819.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-14 15:53:59
 * @Editor: Bingyang Jin
 * @Description: create UNORDERED_SET_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-01-14 16:58:00
 * @Editor: Bingyang Jin
 * @Description: create ANSWER_METHOD, TIME 204ms, 84.16%, MEMORY 70.3MB and 43.56%
 */

#ifndef __leet_code_1819_h__
#define __leet_code_1819_h__

#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>

class Solution {
private:
	// д╛хохон╙ a>b
	int gcd(int a, int b) {
		int t = a % b;
		if (t == 0) {
			return b;
		}
		return gcd(b, t);
	}
public:
	int countDifferentSubsequenceGCDs(std::vector<int>& nums) {
		
		std::unordered_set<int> different_number;
		for (int i = 0; i < nums.size(); i++) {
			different_number.emplace(nums[i]);
		}
		
		std::unordered_set<int> results;
		for (auto i = different_number.begin(); i != different_number.end(); i++) {
			std::unordered_set<int> add_gcd_number;
			for (auto iter = results.begin(); iter != results.end(); iter++) {
				int a = *iter;
				int b = *i;
				if (a < b) {
					int t = a;
					a = b;
					b = t;
				}
				int gcd_result = gcd(a, b);
				if (different_number.count(gcd_result) == 0) {
					add_gcd_number.emplace(gcd_result);
				}
			}
			for (auto iter = add_gcd_number.begin(); iter != add_gcd_number.end(); iter++) {
				results.emplace(*iter);
			}
			results.emplace(*i);
		}

		return results.size();
	}
};

#endif // __leet_code_1819_h__