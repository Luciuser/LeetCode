/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 18:07:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode4.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-12 17:11:17
 * @Editor: Bingyang Jin
 * @Description: create PRE_SLIDE_WINDOW，TIME 16ms, 70.04%, MEMORY 9.4MB and 49.45%
 */

#ifndef __leet_code_4__
#define __leet_code_4__

#include<iostream>
#include<vector>

#define MERGE_SORT_METHOD // 采用归并排序，O(m+n)，

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

		std::vector<int> *pNums;
		if (i1 == nums1.size()) {
			pNums = &nums2;
		}
		else if (i2 == nums2.size()) {
			pNums = &nums1;
		}

		bool isOdd = (nums1.size() + nums2.size()) % 2 == 0 ? false : true;
		int middle = (nums1.size() + nums2.size()) / 2;
		int a, b;
		if (middle < nums.size()) {
			a = nums[middle];
		}
		else {
			a = (*pNums)[middle - nums.size() - 1];
		}
		if (isOdd == false) {
			if (middle + 1 < nums.size()) {
				a = nums[middle + 1];
			}
			else {
				a = (*pNums)[middle - nums.size()];
			}
			return 1.0 * (a + b) / 2;
		}
		else
		{
			return a;
		}

	}
};
#endif // MERGE_SORT_METHOD


class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

		int num1 = nums1.size();
		int num2 = nums2.size();
		if (num1 == 0) {
			if (num2 % 2 == 0) {
				return 1.0*(nums2[num2 / 2 - 1] + nums2[num2 / 2]) / 2;
			}
			else {
				return nums2[num2 / 2];
			}
		// 由于总数是奇数或者偶数时计算方案不同，此处固定为偶数进行计算
		bool isOdd = false;
		if ((num1 + num2) % 2 == 1) {
			// 删去 nums1 的最小值
			isOdd = true;
			num1--;
			nums1.erase(nums1.begin());
		}

		int leftNum = 0;
		int rightNum = 0;
		int left1 = 0;
		int right1 = num1 - 1;
		int left2 = 0;
		int right2 = num2 - 1;
		int middle1, middle2;

		// 寻找数 a 和 b，使得 a 左侧共计有（num1+num2 - 2）/ 2 个数，b 右侧共计有（num1+num2 - 2）/ 2 个数
		while (true) {
			middle1 = (right1 - left1) / 2 + left1;
			middle2 = (right2 - left2) / 2 + left2;

			if (nums1[middle1] > nums2[middle2]) {
				leftNum += middle2 - left2;
				rightNum += right1 - middle1;
				// nums1 向左二分；nums2 向右二分
				right1 = middle1;
				left2 = middle2;
			}
			else if (nums1[middle1] < nums2[middle2]) {
				leftNum += middle1 - left1;
				rightNum += right2 - middle2;
				// nums1 向右二分；nums2 向左二分
				right2 = middle2;
				left1 = middle1;
			}
			else {
				break;
			}
			
		}


	}
};

#endif // __leet_code_4__