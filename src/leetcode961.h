#ifndef __leet_code_436__
#define __leet_code_436__

#include<iostream>
#include<vector>
#include<map>

#define VIOLENCE_METHOD

#ifdef VIOLENCE_METHOD
class Solution {
public:
	int repeatedNTimes(std::vector<int>& nums) {
		std::map<int, int> numCount;
		for (int i = 0; i < nums.size(); i++) {
			if (numCount.count(nums[i]) == 0) {
				numCount[nums[i]] = 1;
			}
			else {
				return nums[i];
			}
		}
		return -1;
	}
};
#endif // VIOLENCE_METHOD

#endif