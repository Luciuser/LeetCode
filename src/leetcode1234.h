/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-12 14:21:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1234.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-12 14:44:55
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 16ms, 75.40%, MEMORY 7.7MB and 30.95%
 */

#ifndef __leet_code_1234_h__
#define __leet_code_1234_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	int balancedString(std::string s) {
		std::vector<int> number(4, s.size() / 4);

		for (int i = 0; i < s.size(); i++) {
			switch (s[i]){
			case'Q':number[0]--; break;
			case'W':number[1]--; break;
			case'E':number[2]--; break;
			case'R':number[3]--; break;
			default:
				break;
			}
		}

		int min = s.size();
		int left = 0;
		for (int right = 0; right <= s.size();) {
			if (left > right) {
				break;
			}
			bool is_success = true;
			for (int i = 0; i < 4; i++) {
				if (number[i] < 0) {
					is_success = false;
					break;
				}
			}
			if (is_success) {
				min = min < right - left ? min : right - left;
				switch (s[left]) {
				case'Q':number[0]--; break;
				case'W':number[1]--; break;
				case'E':number[2]--; break;
				case'R':number[3]--; break;
				default:
					break;
				}
				left++;
			}
			else{
				switch (s[right]) {
				case'Q':number[0]++; break;
				case'W':number[1]++; break;
				case'E':number[2]++; break;
				case'R':number[3]++; break;
				default:
					break;
				}
				right++;
			}
		}

		return min;
	}
};

#endif // __leet_code_1234_h__