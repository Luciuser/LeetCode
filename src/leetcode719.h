#ifndef __leet_code_719__
#define __leet_code_719__

#include<iostream>
#include<vector>
#include<algorithm>

//#define DICHOTOY_DOUBLE_PTR_METHOD // 二分法套双指针
#define DICHOTOY_DICHOTOY_METHOD	// 二分法套二分法

class Solution {
public:

	// 数对距离比dis小的数对的数量
	int calculateKWithDistancePair(std::vector<int>& nums, int dis) {

#ifdef DICHOTOY_DOUBLE_PTR_METHOD
		// 双指针法
		int i = 0, j = 1;
		int sum = 0;
		while (true) {
			if (nums[j] - nums[i] < dis) {
				sum += j - i;
				j++;
			}
			else {
				i++;
				if (i >= j) {
					j++;
				}
			}
			if (j == nums.size()) {
				break;
			}
		}
		return sum;
#endif // DICHOTOY_DOUBLE_PTR_METHOD

#ifdef DICHOTOY_DICHOTOY_METHOD
		int i = 0; 
		int j = 1;
		int sum = 0;
		for (; j < nums.size(); j++) {
			i = std::lower_bound(nums.begin(), nums.begin() + j, nums[j] - dis + 1) - nums.begin();
			if (i < j) {
				sum += j - i;
			}
		}
		return sum;
#endif // DICHOTOY_DICHOTOY_METHOD

		return 0;
	}

	int smallestDistancePair(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums[nums.size() - 1] - nums[0];
		while (true) {
			if (left == right) {
				break;
			}
			if (right - left == 1) {
				int sumLeft = calculateKWithDistancePair(nums, left);
				int sumRight = calculateKWithDistancePair(nums, right);
				if (sumRight < k) {
					return right;
				}
				break;
			}
			int mid = (left + right) / 2;
			int sum = calculateKWithDistancePair(nums, mid);
			if (sum < k) {
				left = mid;
			}
			else if(sum >= k){
				right = mid;
			}
		}

		return left;
	}
};

#endif // __leet_code_719__