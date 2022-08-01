/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-01 10:57:02
 * @FilePath: /src/leetcode1374.h
  * @Description: create the file and hash method, TIME 4 ms, MEMORY 5.9 MB
 */

#ifndef __leet_code_1374__
#define __leet_code_1374__

#include<iostream>
#include<string>

class Solution {
public:
	std::string generateTheString(int n) {
		std::string result;
		if (n % 2 == 0) {
			for (int i = 0; i < n - 1; i++) {
				result += "a";
			}
			result += "b";
		}
		else {
			for (int i = 0; i < n; i++) {
				result += "a";
			}
		}
		return result;
	}
};

#endif // __leet_code_1374__