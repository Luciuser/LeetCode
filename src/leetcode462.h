#ifndef __leet_code_462__
#define __leet_code_462__

#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
	int minMoves2(std::vector<int>& nums) {
		// 对 nums 排序后，对于a0和a1，将其移动到a0-a1之间一点，所需步数相同，均为a1-a0；将其移动至外部一点，所需步数增加
		// 因此最小移动数，则寻找 nums 的中位数，将所有数移动到中位数即可
		int result = 0;

		std::sort(nums.begin(), nums.end(), [=](int a, int b)->bool {
			return a < b;
		});

		int i = 0;
		int j = nums.size() - 1;
		while (true) {
			if (i >= j) {
				break;
			}
			result += nums[j] - nums[i];
			i++;
			j--;
		}

		return result;
	}
	
};

#endif // !__leet_code_462__