#ifndef __leet_code_1781__
#define __leet_code_1781__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int beautySum(std::string s) {
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			std::vector<int> count(26, 0);
			for (int j = i; j < s.size(); j++) {
				count[s[j] - 'a']++;
				
				int min = 501, max = 0;
				for (int k = 0; k < 26; k++) {
					if (count[k] != 0 && count[k] > max) {
						max = count[k];
					}
					if (count[k] != 0 && count[k] < min) {
						min = count[k];
					}
				}
				sum += max - min;
			}
		}
		return sum;
	}
};

#endif // __leet_code_1781__