/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 16:47:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode3.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-12 17:11:17
 * @Editor: Bingyang Jin
 * @Description: create PRE_SLIDE_WINDOW，TIME 16ms, 70.04%, MEMORY 9.4MB and 49.45%
 */

#ifndef __leet_code_3__
#define __leet_code_3__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		// 预处理，确定第 i 个字符的左边，距离它最近的相同字符的索引
		std::vector<int> same; // 第 i 个字符左边距离它最近的相同字符的索引，若无则为 -1
		std::unordered_map<char, int> character; // 第 i 个字符当前最大的索引位置
		for (int i = 0; i < s.size(); i++) {
			if (character.count(s[i]) == 0) {
				same.push_back(-1);
				character[s[i]] = i;
			}
			else {
				same.push_back(character[s[i]]);
				character[s[i]] = i;
			}
		}

		int begin = 0; // 当前字符串的起始索引位置
		int length = 0;	// 当前字符串的长度
		int max = 0; // 当前最大的字符串长度
		for (int i = 0; i < s.size(); i++) {
			if (begin <= same[i]) {
				// 在当前字符串内出现重复
				length -= (same[i] + 1 - begin);
				begin = same[i] + 1;
			}
			length++;
			max = length > max ? length : max;
		}
		
		return max;
	}
};

#endif // __leet_code_3__