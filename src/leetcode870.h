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

		std::vector<int> ni1; // ��������˳���ʾ nums1 �����Ĵ�С 
		std::vector<int> ni2; // ��������˳���ʾ nums2 �����Ĵ�С

		// ��ֵ��O(n)
		int n = nums1.size();
		for (int i = 0; i < n; i++) {
			ni1.push_back(i);
			ni2.push_back(i);
		}

		// ���� nums1 �� nums2 �Ĵ�С�������������У�O(nlogn)
		std::sort(ni1.begin(), ni1.end(), [&nums1](int i, int j) {return nums1[i] > nums1[j]; });
		std::sort(ni2.begin(), ni2.end(), [&nums2](int i, int j) {return nums2[i] > nums2[j]; });

		// �жϣ�O(n)
		std::vector<int> result(n, 0);
		int i1_begin = 0, i1_end = n - 1; // ni1 ��ǰ��ָ��
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