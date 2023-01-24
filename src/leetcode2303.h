/* 
 * @Author: Bingyang Jin
 * @Date: 2023-01-23 15:29:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2303.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-23 15:38:58
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 94.92%, MEMORY 13MB and 50.28%
 */

#ifndef __leet_code_2303_h__
#define __leet_code_2303_h__

#include<iostream>
#include<vector>

class Solution {
public:
	double calculateTax(std::vector<std::vector<int>>& brackets, int income) {
		double result = 0;
		if (income < brackets[0][0]) {
			return 1.0 * income * brackets[0][1] / 100;
		}
		else {
			result += 1.0 * brackets[0][0] * brackets[0][1] / 100;
		}
		for (int i = 1; i < brackets.size(); i++) {
			if (income <= brackets[i][0]) {
				result += 1.0 * (income - brackets[i - 1][0])*brackets[i][1] / 100;
				break;
			}
			result += 1.0 * (brackets[i][0] - brackets[i - 1][0])*brackets[i][1] / 100;
		}

		return result;
	}
};

#endif // __leet_code_2303_h__