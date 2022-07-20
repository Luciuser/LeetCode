#ifndef __leet_code_747__
#define __leet_code_747__

#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
	int dominantIndex(std::vector<int>& nums) {

		if (nums.size() == 0) {
			return -1;
		}
		if (nums.size() == 1) {
			return 0;
		}

		int max = 0;
		int max2 = 0;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[max]) {
				max2 = max;
				max = i;
			}
			if (nums[i] > nums[max2] && nums[i] < nums[max]) {
				max2 = i;
			}
			if (nums[i] < nums[max2] && max == max2) {
				max2 = i;
			}
		}

		if (nums[max] / 2 >= nums[max2]) {
			return max;
		}
		
		return -1;
	}
};



#endif // !__leet_code_668__