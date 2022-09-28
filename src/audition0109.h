/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-29 00:05:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition0109.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-28 00:21:44
 * @Editor: Bingyang Jin
 * @Description: create VECTOR_METHOD, TIME 8ms, 19.95%, MEMORY 7.6MB and 71.60%
 */

 /*
 * @EditTime: 2022-09-28 00:25:28
 * @Editor: Bingyang Jin
 * @Description: create FINDSUBSTRING_METHOD, TIME 8ms, 19.95%, MEMORY 7.8MB and 26.88%
 */

#ifndef __leet_code_audition_01_09__
#define __leet_code_audition_01_09__

#include<iostream>
#include<vector>
#include<string>

//#define VECTOR_METHOD // 将s2切为多个链，分别判断，TIME 8ms, 19.95%, MEMORY 7.6MB and 71.60%
#define FINDSUBSTRING_METHOD // 寻找一次子字符串，TIME 8ms, 19.95%, MEMORY 7.8MB and 26.88%

#ifdef VECTOR_METHOD
class Solution {
public:
	bool isFlipedString(std::string s1, std::string s2) {
		if (s1.size() != s2.size()) {
			return false;
		}
		int n = s1.size();
		if (n == 0) {
			return true;
		}
		std::vector<int> begins;
		for (int i = 0; i < n; i++) {
			if (s2[i] == s1[0]) {
				begins.push_back(i);
			}
		}

		for (int i = 0; i < begins.size(); i++) {
			int i1 = 0;
			int i2 = begins[i];
			while (true) {
				if (i1 == n) {
					return true;
				}
				if (i2 >= n) {
					i2 -= n;
				}
				if (s1[i1] == s2[i2]) {
					i1++;
					i2++;
				}
				else {
					break;
				}
			}
		}

		return false;
	}
};
#endif // VECTOR_METHOD

#ifdef FINDSUBSTRING_METHOD
class Solution {
public:
	bool isFlipedString(std::string s1, std::string s2) {
		return (s1.size() == s2.size()) && (s1 + s1).find(s2) != std::string::npos;
	}
};
#endif // FINDSUBSTRING_METHOD


#endif // __leet_code_audition_01_09__