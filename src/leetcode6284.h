/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-08
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6284.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 327
 */

#ifndef __leet_code_6284_h__
#define __leet_code_6284_h__

#include<iostream>
#include<string>
#include<map>

class Solution {
public:
	bool isItPossible(std::string word1, std::string word2) {
		std::map<char, int> map1;
		std::map<char, int> map2;

		for (int i = 0; i < word1.size(); i++) {
			map1[word1[i]]++;
		}
		for (int i = 0; i < word2.size(); i++) {
			map2[word2[i]]++;
		}

		int n1 = map1.size();
		int n2 = map2.size();
		std::cout << n1 << " " << n2 << std::endl;
		if (abs(n1 - n2) > 2) {
			return false;
		}
		for (int i = 0; i < 26; i++) {
			char c1 = 'a' + i;
			if (map1.count(c1) == 0) {
				continue;
			}
			for (int j = 0; j < 26; j++) {
				char c2 = 'a' + j;
				if (map2.count(c2) == 0) {
					continue;
				}

				if (c1 == c2) {
					if (map1.size() == map2.size()) {
						return true;
					}
				}
				else {
					int temp1 = n1;
					int temp2 = n2;
					if (map1[c1] == 1) {
						temp1--;
					}
					if (map2[c2] == 1) {
						temp2--;
					}
					if (map1.count(c2) == 0) {
						temp1++;
					}
					if (map2.count(c1) == 0) {
						temp2++;
					}
					if (temp1 == temp2) {
						return true;
					}
				}

			}
		}

		return false;
	}
};

#endif // __leet_code_6284_h__