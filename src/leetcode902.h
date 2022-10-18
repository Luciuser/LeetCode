/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-18 08:56:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode902.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-18 09:20:54
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 8MB and 12.44%
 */

#ifndef __leet_code_902__
#define __leet_code_902__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int atMostNGivenDigitSet(std::vector<std::string>& digits, int n) {

		int sum = 0;
		std::vector<int> number;
		int temp = n;
		while (temp >= 10) {
			number.push_back(temp % 10);
			temp = temp / 10;
		}
		number.push_back(temp);

		// 计算位数小于n的位数的数
		for (int i = 1; i < number.size(); i++) {
			sum += pow(digits.size(), i);
		}

		// 计算位数等于n的位数的数
		int di = 0;
		int ni = number.size() - 1;
		while (true) {
			if (di >= digits.size()) {
				break;
			}
			if (atoi((digits[di]).c_str()) < number[ni]) {
				sum += pow(digits.size(), ni);
			}
			else if (atoi((digits[di]).c_str()) == number[ni]) {
				if (ni == 0) {
					sum++;
					break;
				}
				else {
					ni--;
					di = 0;
					continue;
				}
			}
			else {
				break;
			}
			di++;
		}

		return sum;
	}
};

#endif // __leet_code_902__