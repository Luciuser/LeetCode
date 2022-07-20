#ifndef __leet_code_1021__
#define __leet_code_1021__

#include<iostream>
#include<assert.h>

class Solution {
public:
	std::string removeOuterParentheses(std::string s) {
		int temp = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				if (temp == 0) {
					s.erase(s.begin() + i);
					i--;
				}
				temp++;
			}
			else if (s[i] == ')') {
				if (temp == 1) {
					s.erase(s.begin() + i);
					i--;
				}
				temp--;
			}
			else {
				assert(false);
				return "";
			}
		}
		return s;
	}
};

#endif