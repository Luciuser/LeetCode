/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-10 11:15:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode640.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-10 11:46:49
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 0ms, 100%, MEMORY 6.1MB and 8.66%
 */

#ifndef __leet_code_640__
#define __leet_code_640__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	std::string solveEquation(std::string equation) {
		// 将方程化简为 ax + b = cx + d
		int a = 0, b = 0;
		int c = 0, d = 0;
		int temp = 0;
		int sign = 1;
		bool isLeft = true;
		bool isX = false;
		bool hasNumber = false;
		for (int i = 0; i < equation.size(); i++) {
			if (equation[i] == '=') {
				isX ? a += temp * sign : b += temp * sign;
				temp = 0;
				sign = 1;
				isX = false;
				isLeft = false;
				hasNumber = false;
				continue;
			}

			if (equation[i] == '+') {
				if (isLeft) {
					isX ? a += temp * sign : b += temp * sign;
				}
				else {
					isX ? c += temp * sign : d += temp * sign;
				}
				temp = 0;
				sign = 1;
				isX = false;
				hasNumber = false;
			}
			else if (equation[i] == '-') {
				if (isLeft) {
					isX ? a += temp * sign : b += temp * sign;
				}
				else {
					isX ? c += temp * sign : d += temp * sign;
				}
				temp = 0;
				sign = -1;
				isX = false;
				hasNumber = false;
			}
			else if (equation[i] == 'x') {
				if (hasNumber == false) {
					temp == 0 ? temp = 1 : temp;
				}
				isX = true;
			}
			else {
				temp = temp * 10 + equation[i] - '0';
				hasNumber = true;
			}
		}
		isX ? c += temp * sign : d += temp * sign;

		// 转化为 Ax = B 的形式
		int A = a - c;
		int B = d - b;

		std::string result = "";
		if (A==0 && B==0)	{
			result = "Infinite solutions";
		}
		else if (A == 0 && B != 0) {
			result = "No solution";
		}
		else {
			int answer = B / A;
			result = "x=" + std::to_string(answer);
		}

		return result;
	}
};

#endif // __leet_code_640__