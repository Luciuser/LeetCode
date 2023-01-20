/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-15 10:41:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1813.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-20 15:43:23
 * @Editor: Bingyang Jin
 * @Description: create RECURSION_METHOD, TIME 12ms, 0.25%, MEMORY 22.8MB and 5.06%
 */

 /*
 * @EditTime: 2023-01-20 15:57:41
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 0ms, 100.00%, MEMORY 6.8MB and 5.06%
 */

#ifndef __leet_code_1813_h__
#define __leet_code_1813_h__

#include<iostream>
#include<string>
#include<vector>

//#define RECURSION_METHOD // 递归法，从左到右一遍，TIME 12ms, 0.25%, MEMORY 22.8MB and 5.06%
#define DOUBLE_POINTER_METHOD // 双指针法，从左到右一遍，从右到左一遍，TIME 0ms, 100.00%, MEMORY 6.8MB and 5.06%

#ifdef RECURSION_METHOD
class Solution {
public:
	bool areSentencesSimilar(std::string sentence1, std::string sentence2) {

		// 默认从 sentence1 中插入一些句子来得到 sentence2
		if (sentence1.size() > sentence2.size()) {
			std::string temp = sentence1;
			sentence1 = sentence2;
			sentence2 = temp;
		}

		std::vector<std::string> s1;
		std::vector<std::string> s2;
		while (true) {
			int index = sentence1.find_first_of(' ');
			if (index == std::string::npos) {
				s1.push_back(sentence1);
				break;
			}
			std::string temp = sentence1.substr(0, index);
			s1.push_back(temp);
			sentence1 = sentence1.substr(index + 1, sentence1.size() - index - 1);
		}
		while (true) {
			int index = sentence2.find_first_of(' ');
			if (index == std::string::npos) {
				s2.push_back(sentence2);
				break;
			}
			std::string temp = sentence2.substr(0, index);
			s2.push_back(temp);
			sentence2 = sentence2.substr(index + 1, sentence2.size() - index - 1);
		}

		return areSentencesSimilarSimple(s1, s2, 0, 0, false, false);
	}

private:
	bool areSentencesSimilarSimple(std::vector<std::string> s1, std::vector<std::string> s2, int i1, int i2, bool is_first_different, bool is_same_before) {
		if (i1 == s1.size() || i2 == s2.size()) {
			if (i1 == s1.size() && i2 == s2.size()) {
				return true;
			}
			else if (i1 == s1.size() && is_first_different == false) {
				return true;
			}
			return false;
		}

		if (s1[i1] != s2[i2]) {
			if (is_first_different == true && is_same_before == true) {
				return false;
			}
			return areSentencesSimilarSimple(s1, s2, i1, i2 + 1, true, false);
		}
		else {
			if (is_first_different == true && is_same_before == true) {
				return areSentencesSimilarSimple(s1, s2, i1 + 1, i2 + 1, true, true);
			}
			else {
				bool success = areSentencesSimilarSimple(s1, s2, i1, i2 + 1, is_first_different, false) || areSentencesSimilarSimple(s1, s2, i1 + 1, i2 + 1, is_first_different, true);
				return success;
			}
		}

		return false;
	}
};
#endif // RECURSION_METHOD

#ifdef DOUBLE_POINTER_METHOD
class Solution {
public:
	bool areSentencesSimilar(std::string sentence1, std::string sentence2) {

		// 默认从 sentence1 中插入一些句子来得到 sentence2
		if (sentence1.size() > sentence2.size()) {
			std::string temp = sentence1;
			sentence1 = sentence2;
			sentence2 = temp;
		}

		std::vector<std::string> s1;
		std::vector<std::string> s2;
		while (true) {
			int index = sentence1.find_first_of(' ');
			if (index == std::string::npos) {
				s1.push_back(sentence1);
				break;
			}
			std::string temp = sentence1.substr(0, index);
			s1.push_back(temp);
			sentence1 = sentence1.substr(index + 1, sentence1.size() - index - 1);
		}
		while (true) {
			int index = sentence2.find_first_of(' ');
			if (index == std::string::npos) {
				s2.push_back(sentence2);
				break;
			}
			std::string temp = sentence2.substr(0, index);
			s2.push_back(temp);
			sentence2 = sentence2.substr(index + 1, sentence2.size() - index - 1);
		}

		int i = 0, j = 0;
		while (i < s1.size() && s1[i] == s2[i]) {
			i++;
		}
		while (j < s1.size() - i && s1[s1.size() - j - 1] == s2[s2.size() - j - 1]) {
			j++;
		}

		return i + j == s1.size();
	}

};
#endif // DOUBLE_POINTER_METHOD


#endif // __leet_code_1813_h__