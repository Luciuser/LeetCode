/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-16 14:55:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode15.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 15:35:11
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 120ms, 37.27%, MEMORY 25.2MB and 13.16%
 */

#ifndef __leet_code_15_h__ 
#define __leet_code_15_h__

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());

		std::vector<std::vector<int>> result;
		for (int i = 0; i < nums.size() - 2;) {
			if (nums[i] + nums[i + 1] + nums[i + 2] > 0) {
				break;
			}
			else if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) {
				i++;
				continue;
			}

			// ˫ָ�뷨
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right && left < nums.size()) {
				int sum = nums[i] + nums[left] + nums[right];
				if ( sum == 0) {
					std::vector<int> temp = { nums[i], nums[left], nums[right] };
					result.emplace_back(temp);
					left++;
					while (left < nums.size() && nums[left - 1] == nums[left]) {
						left++;
					}
					right--;
				}
				else if (sum > 0) {
					right--;
				}
				else if (sum < 0) {
					left++;
				}
			}

			i++;
			while (i < nums.size() && nums[i - 1] == nums[i]) {
				i++;
			}
		}

		return result;
	}
};

#endif // __leet_code_15_h__