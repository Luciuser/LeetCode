/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-234 12:21:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1450.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-23 12:25:13
 * @Editor: Bingyang Jin
 * @Description: create NORMAL, TIME 0ms, 100.00%, MEMORY 10.6MB and 42.19%
 */

#ifndef __leet_code_1450__
#define __leet_code_1450__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) {
		int result = 0;
		for (int i = 0; i < startTime.size(); i++) {
			if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
				result++;
			}
		}
		return result;
	}
};

#endif // __leet_code_1450__