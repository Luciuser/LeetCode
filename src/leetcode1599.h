/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05 15:04:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1599.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-05 15:20:17
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 76ms, 96.77%, MEMORY 79.4MB and 56.45%
 */

#ifndef __leet_code_1599_h__ 
#define __leet_code_1599_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int minOperationsMaxProfit(std::vector<int>& customers, int boardingCost, int runningCost) {

		int current_index = 0;
		int wait_person = 0;
		int max = -std::numeric_limits<int>::max();
		int max_index = -1;
		int current_profit = 0;

		while (true){
			if (current_index >= customers.size()) {
				if (wait_person == 0) {
					break;
				}
			}
			else {
				wait_person += customers[current_index];
			}
			current_index++;
			
			if (wait_person > 4) {
				current_profit += (4 * boardingCost) - runningCost;
				wait_person -= 4;
				if (current_profit > max) {
					max = current_profit;
					max_index = current_index;
				}
			}
			else {
				current_profit += (wait_person * boardingCost) - runningCost;
				wait_person = 0;
				if (current_profit > max) {
					max = current_profit;
					max_index = current_index;
				}
			}
		}

		if (max > 0) {
			return max_index;
		}

		return -1;
	}
};

#endif //__leet_code_1599_h__