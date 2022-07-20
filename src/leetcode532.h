#ifndef __leet_code_532__
#define __leet_code_532__

#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
#include<algorithm>

//#define DICHOTOY_METHOD	// 二分法
#define HASH_METHOD // 哈希法

#ifdef DICHOTOY_METHOD
class Solution {
public:
	int findPairs(std::vector<int>& nums, int k) {
		if (nums.size() == 1) {
			return 0;
		}
		std::sort(nums.begin(), nums.end());

		int sum = 0;
		std::map<std::pair<int, int>, int> exist;
		for (int j = 1; j < nums.size(); j++) {
			int i = std::lower_bound(nums.begin(), nums.begin() + j, nums[j] - k) - nums.begin();
			if (nums[j] - nums[i] == k && i != j && exist.count(std::pair<int, int>(nums[i], nums[j])) == 0) {
				sum++;
				exist[std::pair<int, int>(nums[i], nums[j])] = 1;
			}
		}
		return sum;
	}
};
#endif // DICHOTOY_METHOD

#ifdef HASH_METHOD
class Solution {
public:
	int findPairs(std::vector<int>& nums, int k) {
		std::unordered_set<int> result;
		std::unordered_set<int> temp;
		for (int i = 0; i < nums.size(); i++) {
			if (temp.count(nums[i] - k) != 0) {
				result.emplace(nums[i] - k);
			}
			if (temp.count(nums[i] + k) != 0) {
				result.emplace(nums[i]);
			}
			temp.emplace(nums[i]);
		}
		return result.size();
	}
};
#endif // HASH_METHOD


#endif // __leet_code_532__