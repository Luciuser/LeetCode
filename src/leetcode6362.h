/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6362.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-19
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 12ms, MEMORY 10.7MB
 */

#ifndef __leet_code_6362_h__ 
#define __leet_code_6362_h__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
		int i = 0, j = 0;

		std::vector<std::vector<int>> result;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i][0] < nums2[j][0]) {
				std::vector<int> temp{ nums1[i][0], nums1[i][1] };
				result.emplace_back(temp);
				i++;
			}
			else if (nums1[i][0] > nums2[j][0]) {
				std::vector<int> temp{ nums2[j][0], nums2[j][1] };
				result.emplace_back(temp);
				j++;
			}
			else {
				std::vector<int> temp{ nums2[j][0], nums2[j][1] + nums1[i][1] };
				result.emplace_back(temp);
				i++;
				j++;
			}
		}

		if (i < nums1.size()) {
			for (; i < nums1.size(); i++) {
				std::vector<int> temp{ nums1[i][0], nums1[i][1] };
				result.emplace_back(temp);
			}
		}
		if (j < nums2.size()) {
			for (; j < nums2.size(); j++) {
				std::vector<int> temp{ nums2[j][0], nums2[j][1] };
				result.emplace_back(temp);
			}
		}

		return result;
	}
};

#endif // __leet_code_6362_h__