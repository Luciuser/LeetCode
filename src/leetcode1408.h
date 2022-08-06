/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-06 10:39:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1408.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-06 10:56:04
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 24 ms and 6.17%, MEMORY 15.9 MB and 5.35%
 */

 /*
 * @EditTime: 2022-08-06 11:03:04
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 8 ms and 48.56%, MEMORY 8.2 MB and 76.13%
 */

#ifndef __leet_code_1408__
#define __leet_code_1408__

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

//#define HASH_METHOD // 用哈希表存储每一个可能的子串
#define VIOLENCE_METHOD // 暴力法 

#ifdef VIOLENCE_METHOD
class Solution {
public:
	std::vector<std::string> stringMatching(std::vector<std::string>& words) {

		std::vector<std::string> result;
		
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (i != j && words[j].find(words[i]) != std::string::npos) {
					result.push_back(words[i]);
					break;
				}
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHOD


#ifdef HASH_METHOD
class Solution {
public:
	std::vector<std::string> stringMatching(std::vector<std::string>& words) {

		std::sort(words.begin(), words.end(), [](std::string a, std::string b) {return a.size() > b.size(); });
		std::unordered_map<std::string, int> stringExist;

		std::vector<std::string> result;
		for (int i = 0; i < words.size(); i++) {
			if (stringExist.count(words[i]) != 0) {
				result.push_back(words[i]);
			}
			else {
				for (int j = 0; j < words[i].size(); j++) {
					for (int k = 0; k < words[i].size() - j; k++) {
						std::string remain = words[i].substr(j, words[i].size() - j - k);
						stringExist[remain] = 1;
					}
				}
			}
		}

		return result;
	}
};
#endif // HASH_METHOD



#endif // __leet_code_1408__