#ifndef __leet_code_434__
#define __leet_code_434__

#include<iostream>

class Solution {
public:
	int countSegments(std::string s) {
		if (s.size() == 0) {
			return 0;
		}

		int sum = 0;
		char before = s[0];
		
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' && before != ' ') {
				sum++;
			}
			before = s[i];
		}
		if (s[s.size() - 1] != ' ') {
			sum++;
		}

		return sum;
	}
};

#endif // __leet_code_434__