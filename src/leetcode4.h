/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 18:07:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode4.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-23 10:40:29
 * @Editor: Bingyang Jin
 * @Description: create MERGE_SORT_WINDOW，TIME 32ms, 42.15%, MEMORY 87.6MB and 10.90%
 */

 /*
 * @EditTime: 2022-12-23 11:17:27
 * @Editor: Bingyang Jin
 * @Description: create NUMBER_K_METHOD，TIME 28ms, 60.86%, MEMORY 86.9MB and 38.01%
 */

#ifndef __leet_code_4__
#define __leet_code_4__

#include<iostream>
#include<vector>

//#define MERGE_SORT_METHOD // 采用归并排序，O(m+n)，TIME 32ms, 42.15%, MEMORY 87.6MB and 10.90%
#define NUMBER_K_METHOD // 寻找第k大的数，O(log(m+n))，TIME 32ms, 42.15%, MEMORY 87.6MB and 10.90%

#ifdef MERGE_SORT_METHOD
class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		std::vector<int> nums;
		int i1 = 0, i2 = 0;
		while (i1 < nums1.size() && i2 < nums2.size()) {
			if (nums1[i1] < nums2[i2]) {
				nums.push_back(nums1[i1]);
				i1++;
			}
			else {
				nums.push_back(nums2[i2]);
				i2++;
			}
		}

		if (i1 >= nums1.size()) {
			for (; i2 < nums2.size(); i2++) {
				nums.push_back(nums2[i2]);
			}
		}
		else if (i2 >= nums2.size()) {
			for (; i1 < nums1.size(); i1++) {
				nums.push_back(nums1[i1]);
			}
		}

		int n = nums1.size() + nums2.size();
		bool isOdd = n % 2 == 0 ? false : true;
		if (isOdd) {
			return nums[n / 2];
		}
		else {
			return 1.0 * (nums[n / 2 - 1] + nums[n / 2]) / 2;
		}

	}
};
#endif // MERGE_SORT_METHOD

#ifdef NUMBER_K_METHOD
class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		if (n % 2 == 0) {
			int a = findKSortedArrays(nums1, nums2, 0, 0, n / 2);
			int b = findKSortedArrays(nums1, nums2, 0, 0, n / 2 + 1);
			return 1.0*(a + b) / 2;
		}
		else {
			return findKSortedArrays(nums1, nums2, 0, 0, n / 2 + 1);
		}
	}
private:
	double findKSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2, int i1, int i2, int k) {
		if (i1 >= nums1.size()) {
			return nums2[i2 + k - 1];
		}
		else if (i2 >= nums2.size()) {
			return nums1[i1 + k - 1];
		}

		if (k == 1) {
			if (nums1[i1] < nums2[i2]) {
				return nums1[i1];
			}
			else {
				return nums2[i2];
			}
		}

		int temp = k / 2;
		int begin1 = i1 + temp - 1 >= nums1.size() ? nums1.size() - 1 : i1 + temp - 1;
		int del1 = begin1 - i1 + 1;
		int begin2 = i2 + temp - 1 >= nums2.size() ? nums2.size() - 1 : i2 + temp - 1;
		int del2 = begin2 - i2 + 1;
		if (nums1[begin1] < nums2[begin2]) {
			return findKSortedArrays(nums1, nums2, begin1 + 1, i2, k - del1);
		}
		else {
			return findKSortedArrays(nums1, nums2, i1, begin2 + 1, k - del2);
		}

	}
};
#endif // NUMBER_K_METHOD

#endif // __leet_code_4__