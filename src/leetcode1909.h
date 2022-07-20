#ifndef __leet_code_1909__
#define __leet_code_1909__

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	bool canBeIncreasing(vector<int>& nums) {
		int max = -numeric_limits<int>::max();	// the max number now
		int index = -1;	// the index which of number should be deleted
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			else {
				index = i - 1;
				break;
			}
		}
		if (index == -1) {
			return true;
		}

		bool test1 = true;
		for (int i = index + 2; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			else {
				test1 = false;
				break;
			}
		}
		if (test1 == true) {
			return true;
		}

		if (index == 0) {
			max = -numeric_limits<int>::max();
		}
		else {
			max = nums[index - 1];
		}
		for (int i = index+1; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			else {
				return false;
			}
		}

		return true;
	}
};

#endif // !__leet_code_1909__