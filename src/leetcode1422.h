/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-23 13::36:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1422.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-22 13:57:44
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMING_COMPLICATE, TIME 0ms, 100.00%, MEMORY 6.1MB and 69.04%
 */

 /*
 * @EditTime: 2022-08-22 14:05:11
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMING_SIMPLE, TIME 0ms, 100.00%, MEMORY 6.2MB and 28.99%
 */

#ifndef __leet_code_1422__
#define __leet_code_1422__

#include<iostream>
#include<vector>
#include<string>

//#define DYNAMIC_PROGRAMING_COMPLICATE // 我的动态规划，比较复杂，但只需要一次遍历，TIME 0ms, 100.00%, MEMORY 6.1MB and 69.04%
#define DYNAMIC_PROGRAMING_SIMPLE	// 简单动态规划，需要两次遍历，TIME 0ms, 100.00%, MEMORY 6.2MB and 28.99%

#ifdef DYNAMIC_PROGRAMING_COMPLICATE
class Solution {
public:
	int maxScore(std::string s) {
		int max = 0;
		int zeroNum = 0;
		s[0] == '0' ? zeroNum++, max++ : max = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == '0') {
				if (i == s.size() - 1) {
					max = max < zeroNum ? zeroNum : max;
				}
				zeroNum++;
			}
			else {
				max = max < zeroNum ? zeroNum : max;
				max++;
			}
		}

		return max;
	}
};
#endif // DYNAMIC_PROGRAMING_COMPLICATE

#ifdef DYNAMIC_PROGRAMING_SIMPLE
class Solution {
public:
	int maxScore(std::string s) {
		int max = 0;
		int ones = 0;

		for (int i = 0; i < s.size(); i++) {
			s[i] == '1' ? ones++ : ones;
		}
		
		for (int i = 0; i < s.size() - 1; i++) {
			s[i] == '0' ? ones++: ones--;
			max < ones ? max = ones : max;
		}

		return max;
	}
};
#endif // DYNAMIC_PROGRAMING_SIMPLE



#endif // __leet_code_1422__