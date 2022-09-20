/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-20 08:55:05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode698.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-20 10:16:10
 * @Editor: Bingyang Jin
 * @Description: create SYSTEM_PRUNE, TIME 36ms, 44.49%, MEMORY 17.6MB and 18.97%
 */

#ifndef __leet_code_698__
#define __leet_code_698__

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<numeric>

class Solution {
public:

	bool dfs(int setindex, int numindex) {
		
		if (sets[setindex] + numbers[numindex] > average) {
			return false;
		}
		sets[setindex] += numbers[numindex];
		isNumberUsed[numindex] = 1;

		bool result = true;
		std::unordered_set<int> setsSame;
		std::unordered_set<int> numSame;
		for (int i = 0; i < sets.size(); i++) {
			if (sets[i] < average && setsSame.count(sets[i]) == 0) {
				result = false;
				setsSame.emplace(sets[i]);
				if (dfs(i, numindex + 1)) {
					return true;
				}
			}
		}

		sets[setindex] -= numbers[numindex];
		isNumberUsed[numindex] = 0;
		return result;
	}

	bool canPartitionKSubsets(std::vector<int>& nums, int k) {
		int sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (sum%k != 0) {
			return false;
		}

		average = sum / k;
		sets = std::vector<int>(k, 0);
		isNumberUsed = std::vector<int>(nums.size(), 0);
		numbers = nums;
		std::sort(numbers.begin(), numbers.end(), [=](int a, int b) {return a > b; });
		
		return dfs(0, 0);
	}
private:
	int average;
	std::vector<int>numbers;
	std::vector<int> sets;
	std::vector<int> isNumberUsed;
};

#endif // __leet_code_698__