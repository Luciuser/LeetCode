/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-27 00:16:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition0102.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-27 00:24:23
 * @Editor: Bingyang Jin
 * @Description: create SORT_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 82.82%
 */

 /*
 * @EditTime: 2022-09-27 00:28:44
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD , TIME 0ms, 100.00%, MEMORY 5.9MB and 65.99%
 */

#ifndef __leet_code_audition_01_02__
#define __leet_code_audition_01_02__

#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

//#define SORT_METHOD // 先排序，再直接比较，时间复杂度 O(nlogn)，空间复杂度 O(1)，TIME 0ms, 100.00%, MEMORY 5.9MB and 82.82%
#define HASH_MAP_METHOD // 哈希表映射，时间复杂度 O(n)，空间复杂度 O(n)，TIME 0ms, 100.00%, MEMORY 5.9MB and 65.99%

#ifdef SORT_METHOD
class Solution {
public:
	bool CheckPermutation(std::string s1, std::string s2) {

		if (s1.size() != s2.size()) {
			return false;
		}

		std::sort(s1.begin(), s1.end(), [=](char a, char b) {
			return a < b;
		});
		std::sort(s2.begin(), s2.end(), [=](char a, char b) {
			return a < b;
		});

		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				return false;
			}
		}

		return true;
	}
};
#endif // SORT_METHOD

#ifdef HASH_MAP_METHOD
class Solution {
public:
	bool CheckPermutation(std::string s1, std::string s2) {

		if (s1.size() != s2.size()) {
			return false;
		}

		std::unordered_map<char, int> character;
		for (int i = 0; i < s1.size(); i++) {
			character[s1[i]]++;
		}

		for (int i = 0; i < s2.size(); i++) {
			char c = s2[i];
			if (character.count(c) == 0) {
				return false;
			}
			character[c]--;
			if (character[c] < 0) {
				return false;
			}
		}

		return true;
	}
};
#endif // HASH_MAP_METHOD

#endif // __leet_code_audition_01_02__