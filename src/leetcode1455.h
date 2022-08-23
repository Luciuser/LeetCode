/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-23 13::14:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1455.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-23 13:24:16
 * @Editor: Bingyang Jin
 * @Description: create ERGODIC_ONLY_ONE, TIME 0ms, 100.00%, MEMORY 6MB and 45.94%
 */

 /*
 * @EditTime: 2022-08-23 13:31:42
 * @Editor: Bingyang Jin
 * @Description: create ERGODIC_TWO, TIME 0ms, 100.00%, MEMORY 6MB and 52.38%
 */

#ifndef __leet_code_1455__
#define __leet_code_1455__

#include<iostream>
#include<vector>
#include<string>

#define ERGODIC_TWO	// 遍历两次
//#define ERGODIC_ONLY_ONE	// 只遍历一遍

#ifdef ERGODIC_ONLY_ONE
class Solution {
public:
	int isPrefixOfWord(std::string sentence, std::string searchWord) {
		//std::string temp = "";
		int wordIndex = 1;
		int searchIndex = 0;
		bool isSame = true;
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == ' ') {
				if (isSame && searchIndex >= searchWord.size()) {
					return wordIndex;
				}
				wordIndex++;
				isSame = true;
				searchIndex = 0;
			}
			else {
				if (isSame && searchIndex < searchWord.size() && searchWord[searchIndex] != sentence[i]) {
					isSame = false;
				}
				searchIndex++;
			}
		}

		if (isSame) {
			return wordIndex;
		}

		return -1;
	}
};
#endif // ERGODIC_ONLY_ONE

#ifdef ERGODIC_TWO
class Solution {
public:
	int isPrefixOfWord(std::string sentence, std::string searchWord) {
		std::string temp = "";
		int wordIndex = 1;
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == ' ') {
				if (temp.size() < searchWord.size()) {
					wordIndex++;
					temp = "";
					continue;
				}
				bool isSame = true;
				for (int j = 0; j < searchWord.size(); j++) {
					if (searchWord[j] != temp[j]) {
						wordIndex++;
						isSame = false;
						break;
					}
				}
				if (isSame == false) {
					temp = "";
					continue;
				}
				return wordIndex;
			}
			else {
				temp += sentence[i];
			}
		}

		if (temp.size() >= searchWord.size()) {
			bool isSame = true;
			for (int j = 0; j < searchWord.size(); j++) {
				if (searchWord[j] != temp[j]) {
					isSame = false;
					break;
				}
			}
			if (isSame) {
				return wordIndex;
			}
		}

		return -1;
	}
};
#endif // ERGODIC_TWO

#endif // __leet_code_1455__