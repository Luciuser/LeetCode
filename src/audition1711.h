#ifndef __leet_code_audition_17_11__
#define __leet_code_audition_17_11__

#include<iostream>
#include<vector>

class Solution {
public:
	int findClosest(std::vector<std::string>& words, std::string word1, std::string word2) {
		int i1 = -1;
		int i2 = -1;
		int min = std::numeric_limits<int>::max();
		for (int i = 0; i < words.size(); i++) {
			if (words[i] == word1) {
				i1 = i;
				if (i2 != -1) {
					int temp = i1 - i2;
					if (temp < min) {
						min = temp;
					}
				}
			}
			if (words[i] == word2) {
				i2 = i;
				if (i1 != -1) {
					int temp = i2 - i1;
					if (temp < min) {
						min = temp;
					}
				}
			}
		}

		return min;
	}
};

#endif // __leet_code_audition_17_11__