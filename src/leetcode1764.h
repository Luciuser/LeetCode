/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-17 00:05:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1764.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-17 00:17:45
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 48.86%, MEMORY 13.2MB and 89.77%
 */

#ifndef __leet_code_1764__
#define __leet_code_1764__

#include<iostream>
#include<vector>

class Solution {
public:
	bool canChoose(std::vector<std::vector<int>>& groups, std::vector<int>& nums) {
		int ni = 0;
		for (int i = 0; i < groups.size();) {
			if (ni >= nums.size()) {
				return false;
			}
			if (nums[ni] == groups[i][0]) {
				bool isSame = true;
				int temp = ni;
				for (int j = 1; j < groups[i].size(); j++) {
					ni++;
					if (groups[i][j] != nums[ni]) {
						isSame = false;
						break;
					}
				}

				if (isSame) {
					ni++;
					i++;
				}
				else {
					ni = temp + 1;
				}
			}
			else {
				ni++;
			}
		}

		return true;
	}
};

#endif // __leet_code_1764__