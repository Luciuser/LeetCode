/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-06 17:10:11
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode982.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-05 12:29:20
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGTAMMING_METHOD, TIME 68ms, 80.39%, MEMORY 21.5MB and 81.37%
 */

#ifndef __leet_code_982_h__ 
#define __leet_code_982_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int countTriplets(std::vector<int>& nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				for (int k = j; k < n; k++) {
					if ((nums[i] & nums[j] & nums[k]) == 0) {
						if (i == j || i == k || j == k) {
							if (i == j && i == k) {
								// 三个数全部相同
								sum++;
							}
							else {
								// 只存在两个数相同
								sum += 3;
							}
						}
						else {
							// 三个数均不相同
							sum += 6;
						}
					}
				}
			}
		}

		return sum;
	}
};

#endif // __leet_code_982_h__