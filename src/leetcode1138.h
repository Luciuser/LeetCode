/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-12 10:37:49
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1138.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-12 11:03:26
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.1MB and 19.19%
 */

#ifndef __leet_code_1138_h__
#define __leet_code_1138_h__

#include<iostream>
#include<string>

class Solution {
public:
	std::string alphabetBoardPath(std::string target) {
		int current_x = 0;
		int current_y = 0;
		int target_x = 0;
		int target_y = 0;

		std::string result = "";
		for (int i = 0; i < target.size(); i++) {
			target_x = (target[i] - 'a') % 5;
			target_y = (target[i] - 'a') / 5;
			if (current_x == 0 && current_y == 5) {
				if (target_y > current_y) {
					result += std::string(target_y - current_y, 'D');
				}
				else if (target_y < current_y) {
					result += std::string(current_y - target_y, 'U');
				}
				if (target_x > current_x) {
					result += std::string(target_x - current_x, 'R');
				}
				else if (target_x < current_x) {
					result += std::string(current_x - target_x, 'L');
				}
			}
			else {
				if (target_x > current_x) {
					result += std::string(target_x - current_x, 'R');
				}
				else if (target_x < current_x) {
					result += std::string(current_x - target_x, 'L');
				}
				if (target_y > current_y) {
					result += std::string(target_y - current_y, 'D');
				}
				else if (target_y < current_y) {
					result += std::string(current_y - target_y, 'U');
				}
			}
			result += '!';

			current_x = target_x;
			current_y = target_y;
		}

		return result;
	}
};

#endif // __leet_code_1138_h__