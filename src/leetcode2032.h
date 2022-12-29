/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-29 10:07:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2032.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-29 10:17:15
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 38.43%, MEMORY 25.4MB and 36.11%
 */

#ifndef __leet_code_2032__
#define __leet_code_2032__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
	std::vector<int> twoOutOfThree(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3) {
		std::unordered_map<int, int>freq;
		for (int i = 0; i < nums1.size(); i++) {
			if (freq.count(nums1[i]) == 0) {
				freq[nums1[i]] = 1;
			}
		}

		for (int i = 0; i < nums2.size(); i++) {
			if (freq.count(nums2[i]) == 0) {
				freq[nums2[i]] = 2;
			}
			else if (freq[nums2[i]] == 1) {
				freq[nums2[i]] = -1;
			}
		}

		for (int i = 0; i < nums3.size(); i++) {
			if (freq.count(nums3[i]) != 0) {
				freq[nums3[i]] = -1;
			}
		}

		std::vector<int> result;
		for (auto iter = freq.begin(); iter != freq.end(); iter++) {
			if ((*iter).second == -1) {
				result.push_back((*iter).first);
			}
		}
		return result;
	}
};

#endif // __leet_code_2032__