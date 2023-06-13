/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-13 08:36:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2475.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-13 09:00:38
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_PROGTAMMING_METHOD, TIME 32ms, 66.67%, MEMORY 17.2MB and 5.36%
 */

 /*
 * @EditTime: 2023-06-13 09:07:59
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 0ms, 100.00%, MEMORY 8.4MB and 25.29%
 */

#ifndef __leet_code_2475_h__ 
#define __leet_code_2475_h__

#include<iostream>
#include<vector>
#include<unordered_map>

//#define NORMAL_PROGTAMMING_METHOD // 先遍历，再哈希，TIME 32ms, 66.67%, MEMORY 17.2MB and 5.36%
#define HASH_METHOD // 哈希法，TIME 0ms, 100.00%, MEMORY 8.4MB and 25.29%

#ifdef HASH_METHOD
class Solution {
public:
	int unequalTriplets(std::vector<int>& nums) {

		std::unordered_map<int, int>frequene;
		for (int i = 0; i < nums.size(); i++) {
			frequene[nums[i]]++;
		}

		int sum = 0;
		int before = 0;
		int n = nums.size();
		for (auto iter = frequene.begin(); iter != frequene.end(); iter++) {
			int current = (*iter).second;
			sum += before * current*(n - before - current);
			before += current;
		}

		return sum;
	}
};
#endif // HASH_METHOD

#ifdef NORMAL_PROGTAMMING_METHOD
class Solution {
public:
	int unequalTriplets(std::vector<int>& nums) {

		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			std::unordered_map<int, int> frequence;
			int use_sum = 0;
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[j] == nums[i]) {
					continue;
				}
				int temp = use_sum;
				use_sum++;

				if (frequence.count(nums[j]) == 0) {
					frequence[nums[j]]++;
				}
				else {
					temp -= frequence[nums[j]];
					frequence[nums[j]]++;
				}

				sum += temp;
			}
		}

		return sum;
	}
};
#endif // NORMAL_PROGTAMMING_METHOD

#endif // __leet_code_2475_h__