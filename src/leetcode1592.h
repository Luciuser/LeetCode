/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-07 10:42:28
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1592.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-07 10:57:36
 * @Editor: Bingyang Jin
 * @Description: create normal method£¬TIME 0ms, 100.00%, MEMORY 6MB and 55.73%
 */

#ifndef __leet_code_1592__
#define __leet_code_1592__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::string reorderSpaces(std::string text) {
		int num = 0;
		std::vector<std::string> words;
		bool isWord = false;
		std::string temp = "";
		for (int i = 0; i < text.size(); i++) {
			if (text[i] == ' ') {
				num++;
				if (isWord) {
					words.push_back(temp);
					temp = "";
					isWord = false;
				}
			}
			else {
				isWord = true;
				temp += text[i];
			}
		}
		if (isWord) {
			words.push_back(temp);
		}

		std::string result;
		int middle = 0;
		int last = 0;
		if (words.size() == 1) {
			middle = 0;
			last = num;
		}
		else {
			middle = num / (words.size() - 1);
			last = num % (words.size() - 1);
		}

		result += words[0];
		for (int i = 1; i < words.size(); i++) {
			for (int j = 0; j < middle; j++) {
				result += " ";
			}
			result += words[i];
		}
		for (int i = 0; i < last; i++) {
			result += " ";
		}

		return result;
	}
};

#endif // __leet_code_1592__