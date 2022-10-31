/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-31 00:29:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode481.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-31 13:18:30
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 0ms, 100.00%, MEMORY 7.8MB and 29%
 */

#ifndef __leet_code_481__
#define __leet_code_481__

#include<iostream>
#include<vector>

class Solution {
public:
	int magicalString(int n) {

		if (n <= 3) {
			return 1;
		}

		std::vector<char> str;
		int index = 0;
		int sum = 0;

		// pattern[0][0] 表示 1 的映射结果为 1
		// pattern[0][1] 表示 11 的映射结果为 2
		// pattern[1][0] 表示 2 的映射结果为 1
		// pattern[1][1] 表示 22 的映射结果为 2
		std::vector<std::vector<char>> pattern(2, std::vector<char>(2));
		pattern[0][0] = '1';
		pattern[0][1] = '2';
		pattern[1][0] = '1';
		pattern[1][1] = '2';

		str.push_back('1');
		str.push_back('2');
		str.push_back('2');
		index = 2;
		int size = 3;

		int i = 0;
		while (true) {
			if (pattern[i][0] == str[index]) {
				str.push_back(i + '1');
				size++;
				if (size > n) {
					break;
				}
				if (i == 0) {
					sum++;
				}
			}
			else {
				str.push_back(i + '1');
				str.push_back(i + '1');

				size++;
				if (size > n) {
					break;
				}
				if (i == 0) {
					sum++;
				}
				size++;
				if (size > n) {
					break;
				}
				if (i == 0) {
					sum++;
				}
			}
			index++;
			i = 1 - i;
		}

		return sum;

	}
};

#endif // __leet_code_481__