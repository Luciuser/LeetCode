/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-28 09:45:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1750.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-28 10:00:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 24ms, 31.21%, MEMORY 12.5MB and 38.30%
 */

#ifndef __leet_code_1750__
#define __leet_code_1750__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumLength(std::string s) {
		int i = 0;
		int j = s.size() - 1;
		while (true) {
			if (i >= j || s[i] != s[j]) {
				break;
			}
			else{
				char temp = s[i];
				i++;
				j--;
				while (i <= j){
					if (s[i] != temp && s[j] != temp) {
						break;
					}
					if (s[i] == temp) {
						i++;
					}
					if (s[j] == temp) {
						j--;
					}
				}
			}
		}

		if (i <= j) {
			return j - i + 1;
		}
		else {
			return 0;
		}

	}
};

#endif // __leet_code_1750__