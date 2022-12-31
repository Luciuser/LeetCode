/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-31 10:17:07
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2037.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-30 14:49:19
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 9.50%, MEMORY 17.7MB and 19.46%
 */

#ifndef __leet_code_2037__
#define __leet_code_2037__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
		std::sort(seats.begin(), seats.end(), [&](int a, int b) {
			return a < b;
		});
		std::sort(students.begin(), students.end(), [&](int a, int b) {
			return a < b;
		});

		int sum = 0;
		for (int i = 0; i < seats.size(); i++) {
			sum += abs(students[i] - seats[i]);
		}

		return sum;
	}
};

#endif // __leet_code_2037__