/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-22 10:13:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode670.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-22 10:45:25
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 3ms, 24.45%, MEMORY 7.07MB and 5.49%
 */

#ifndef __leet_code_670__
#define __leet_code_670__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	int maximumSwap(int num) {
		
		std::string num_string = std::to_string(num);
		
		std::vector<int> number_position(10, -1);
		for (int i = 0; i < num_string.size(); i++) {
			number_position[num_string[i] - '0'] = i;
		}

		bool find = false;
		for (int i = 0; i+1 < num_string.size(); i++) {
			if (find) {
				break;
			}
			for (int j = 9; j > 0; j--) {
				if (j <= num_string[i] - '0') {
					break;
				}
				if (i < number_position[j]) {
					// ½øÐÐ½»»»
					find = true;
					char t = num_string[number_position[j]];
					num_string[number_position[j]] = num_string[i];
					num_string[i] = t;
					break;
				}
			}
		}

		return std::stoi(num_string);
	}
};

#endif // __leet_code_670__