/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-06 19:39:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode11.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-06 19:54:00
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_TALL_METHOD, out of TIME
 */

 /*
 * @EditTime: 2023-01-19 10:13:41
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 64ms, 90.14%, MEMORY 57.6MB and 26.99%
 */

#ifndef __leet_code_11__
#define __leet_code_11__

#include<iostream>
#include<vector>

//#define VIOLENCE_TALL_METHOD // 暴力求解，out of TIME
#define DOUBLE_POINTER_METHOD // 双指针法，TIME 64ms, 90.14%, MEMORY 57.6MB and 26.99%

#ifdef VIOLENCE_TALL_METHOD
class Solution {
public:
	int maxArea(std::vector<int>& height) {
		std::vector<int> tall = { 0 };
		int max_height = height[0];
		int max_area = 0;
		for (int i = 1; i < height.size(); i++) {
			for (int j = 0; j < tall.size(); j++) {
				int w = i - tall[j];
				int h = height[i] < height[tall[j]] ? height[i] : height[tall[j]];
				int area = w * h;
				if (area > max_area) {
					max_area = area;
				}
				if (height[tall[j]] > height[i]) {
					break;
				}
			}
			if (height[i] > max_height) {
				max_height = height[i];
				tall.emplace_back(i);
			}
		}

		return max_area;
	}
};
#endif // VIOLENCE_TALL_METHOD

#ifdef DOUBLE_POINTER_METHOD
class Solution {
public:
	int maxArea(std::vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max_area = 0;
		while (left < right) {
			int length = right - left;
			int height_min = height[left] > height[right] ? height[right] : height[left];
			int area = length * height_min;
			if (area > max_area) {
				max_area = area;
			}
			if (height[left]>height[right]){
				right--;
			}
			else {
				left++;
			}
		}
		return max_area;
	}
};
#endif // DOUBLE_POINTER_METHOD

#endif // __leet_code_11__