/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-08 12:43:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode870.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-07 13:04:20
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 180ms, 27.09%, MEMORY 61.3MB and 31.12%
 */

#ifndef __leet_code_870__
#define __leet_code_870__

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

class Solution {
public:
	std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2) {

		std::vector<int> ni1; // 用索引的顺序表示 nums1 里数的大小 
		std::vector<int> ni2; // 用索引的顺序表示 nums2 里数的大小

		// 赋值，O(n)
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			ni1.push_back(i);
			ni2.push_back(i);
		}

		// 根据 nums1 和 nums2 的大小对索引进行排列，O(nlogn)
		std::sort(ni1.begin(), ni1.end(), [&nums1](int i, int j) {return nums1[i] > nums1[j]; });
		std::sort(ni2.begin(), ni2.end(), [&nums2](int i, int j) {return nums2[i] > nums2[j]; });

		// 判断，O(n)
		std::vector<int> result(n, 0);
		int i1_begin = 0, i1_end = n - 1; // ni1 的前后指针
		for (int i2 = 0; i2 < n; i2++) {
			if (nums1[ni1[i1_begin]] > nums2[ni2[i2]]) {
				result[ni2[i2]] = nums1[ni1[i1_begin]];
				i1_begin++;
			}
			else {
				result[ni2[i2]] = nums1[ni1[i1_end]];
				i1_end--;
			}
		}

		return result;

	}
};

#endif // __leet_code_870__