/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-13 13:43:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2182.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-13 14:16:01
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 128ms, 33.64%, MEMORY 24.58MB and 24.54%
 */

#ifndef __leet_code_2082__
#define __leet_code_2082__

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>

class Solution {
public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
		std::map<char, int, std::greater<char>> freq;
		char min_c = 'z'; // 最小的一个字母，最后处理一下即可
		for (int i = 0; i < s.size(); i++) {
			freq[s[i]]++;
			if (s[i] < min_c) {
				min_c = s[i];
			}
		}

		std::string result = "";
		auto current = freq.begin();
		auto next = freq.begin();
		while (true) {
			// 找到剩下字符中最大的和第二大的
			while ((*current).second == 0){
				current++;
				if (current == freq.end()) {
					break;
				}
			}
			if ((*next).second == 0 || next == current) {
				next++;
			}
			if (next == freq.end()) {
				break;
			}
			
			char key = (*current).first;
			int num = (*current).second;
			char next_key = (*next).first;
			int next_num = (*next).second;

			if (num <= repeatLimit) {
				for (int i = 0; i < num; i++) {
					result += key;
				}
				(*current).second -= num;
			}
			else {
				for (int i = 0; i < repeatLimit; i++) {
					result += key;
				}
				result += next_key;
				(*current).second -= repeatLimit;
				(*next).second -= 1;
			}
		}
		char key = (*current).first;
		int num = (*current).second;
		int len = num < repeatLimit ? num : repeatLimit;
		for (int i = 0; i < len; i++) {
			result += key;
		}

		return result;
    }
};

#endif // __leet_code_2082__