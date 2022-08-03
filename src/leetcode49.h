/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-03 16:21:11
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode49.h
 * @Description: create the file and hash method, TIME 72 ms, MEMORY 27.2 MB
 */

#ifndef __leet_code_49__
#define __leet_code_49__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::unordered_map<std::string, int> pattern2index;	// 每个单词拥有的字符量构成的string，与该字符量所对应的vector的索引
		std::vector<std::vector<std::string>> result;

		for (int i = 0; i < strs.size(); i++) {
			std::map<char, int> char2num;
			for (int j = 0; j < strs[i].size(); j++) {
				if (char2num.count(strs[i][j]) == 0) {
					char2num[strs[i][j]] = 1;
				}
				else {
					char2num[strs[i][j]]++;
				}
			}
			std::string pattern = "";
			for (auto iter = char2num.begin(); iter != char2num.end(); iter++) {
				pattern += (*iter).first;
				pattern += std::to_string((*iter).second);
			}
			
			if (pattern2index.count(pattern) == 0) {
				pattern2index[pattern] = result.size();
				
				std::vector<std::string> temp;
				temp.push_back(strs[i]);
				result.push_back(temp);
			}
			else {
				result[pattern2index[pattern]].push_back(strs[i]);
			}
		}

		return result;
	}
};

#endif // __leet_code_49__