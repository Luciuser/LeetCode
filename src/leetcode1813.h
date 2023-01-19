/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-15 10:41:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1813.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-15 10:05:16
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 8ms, 54.88%, MEMORY 9.5MB and 79.07%
 */

#ifndef __leet_code_1813_h__
#define __leet_code_1813_h__

#include<iostream>
#include<string>
#include<vector>

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
		bool is_first_different = false; // 是否已经出现过不相同的情况
		bool is_same_before = false; // 前一个单词是否相同
		while (true) {

			if (i >= s1.size() || j >= s2.size()) {
				break;
			}

			// 判断第 i 个单词和第 j 个单词是否相同
			bool is_same = true;
			if (s1[i] != s2[j]) {
				is_same = false;
			}
			
			if (!is_same) {
				if (is_first_different == true && is_same_before == true) {
					return false;
				}
				is_first_different = true;
				is_same_before = false;
				j++;
				continue;
			}
			
			i++;
			j++;
			is_same_before = true;
		}

		if (i == s1.size() && j == s2.size()) {
			return true;
		}
		else if(i == s1.size() && j<s2.size() && is_first_different == false){
			return true;
		}

		return false;
	}
};

#endif // __leet_code_1813_h__