/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-19 00:52:38
 * @FilePath: /src/leetcode731.h
  * @Description: create the file
 */
 /*
  * @EditTime: 2022-07-19 12:38:36
  * @Editor: Bingyang Jin
  * @Description: finsih the DIFFERENCE_METHODS, time 212ms and memory 37.6 MB
  */

#ifndef __leet_code_731__
#define __leet_code_731__

#include<map>

//#define DIFFERENCE_METHODS	// 差分数组法
#define SEGMENT_TREE_METHODS // 线段树方法

#ifdef DIFFERENCE_METHODS

class MyCalendarTwo {
public:
	MyCalendarTwo() {
		nums2count.clear();
	}

	bool book(int start, int end) {

		if (nums2count.count(start) == 0) {
			nums2count[start] = 1;
		}
		else {
			nums2count[start]++;
		}

		if (nums2count.count(end) == 0) {
			nums2count[end] = -1;
		}
		else {
			nums2count[end]--;
		}

		int temp = 0;
		for (auto iter = nums2count.begin(); iter != nums2count.end(); iter++) {
			temp += (*iter).second;
			if (temp >= 3) {
				// 出现三重预定
				nums2count[start]--;
				nums2count[end]++;
				return false;
			}
		}

		return true;
	}

private:
	std::map<int, int> nums2count;
};

#endif // DIFFERENCE_METHODS

#ifdef SEGMENT_TREE_METHODS

class MyCalendarTwo {
public:
	MyCalendarTwo() {
		nums2count.clear();
	}

	bool book(int start, int end) {

		if (nums2count.count(start) == 0) {
			nums2count[start] = 1;
		}
		else {
			nums2count[start]++;
		}

		if (nums2count.count(end) == 0) {
			nums2count[end] = -1;
		}
		else {
			nums2count[end]--;
		}

		int temp = 0;
		for (auto iter = nums2count.begin(); iter != nums2count.end(); iter++) {
			temp += (*iter).second;
			if (temp >= 3) {
				// 出现三重预定
				nums2count[start]--;
				nums2count[end]++;
				return false;
			}
		}

		return true;
	}

private:
	std::map<int, int> nums2count;
};

#endif // SEGMENT_TREE_METHODS

#endif // __leet_code_731__
