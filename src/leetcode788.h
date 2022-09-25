/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-25 09:56:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode788.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-24 10:22:14
 * @Editor: Bingyang Jin
 * @Description: create ENUM_METHOD, TIME 12ms, 41.62%, MEMORY 5.9MB and 31.89%
 */

#ifndef __leet_code_788__
#define __leet_code_788__

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>

class Solution {
public:
	int rotatedDigits(int n) {
		int result = 0;
		
		for (int i = 0; i <= n;) {
			std::string str = std::to_string(i);
			int size = str.size();
			int index = 0;
			bool isWrong = false;
			bool isChange = false;
			while (index < size) {
				if (str[index] == '3' || str[index] == '4' || str[index] == '7') {
					isWrong = true;
					break;
				}
				else if (str[index] == '2' || str[index] == '5' || str[index] == '6' || str[index] == '9') {
					isChange = true;
				}
				index++;
			}

			if (isWrong) {
				i += pow(10, (size - index - 1));
				continue;
			}
			if (isChange) {
				result++;
			}
			i++;
		}

		return result;
	}
};

#endif // __leet_code_788__