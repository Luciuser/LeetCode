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
 * @EditTime: 2023-01-06 19:54:00
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_TALL_METHOD, TIME 4ms, 27.232%, MEMORY 5.8MB and 67.32%
 */

#ifndef __leet_code_11__
#define __leet_code_11__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxArea(std::vector<int>& height) {
		std::vector<int> tall = {0};
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
			}
			if (height[i] > max_height) {
				max_height = height[i];
				tall.emplace_back(i);
			}
		}

		return max_area;
	}
};

#endif // __leet_code_11__