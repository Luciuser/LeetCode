/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-24 09:24:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1754.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-24 10:27:25
 * @Editor: Bingyang Jin
 * @Description: create MERGE_METHOD£¬TIME 188ms, 29.17%, MEMORY 390.3MB and 35.72%
 */

#ifndef __leet_code_1754__
#define __leet_code_1754__

#include<iostream>
#include<string>

class Solution {
public:
	std::string largestMerge(std::string word1, std::string word2) {
		std::string merge;
		int i = 0, j = 0;
		while (i < word1.size() || j < word2.size()) {
			if (i < word1.size() && word1.substr(i) > word2.substr(j)) {
				merge.push_back(word1[i++]);
			}
			else {
				merge.push_back(word2[j++]);
			}
		}
		return merge;
	}
};

#endif // __leet_code_1754__