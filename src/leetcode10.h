/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-28 10:28:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode10.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-29 11:04:03
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 196ms, 5.16%, MEMORY 8MB and 14.47%
 */

#ifndef __leet_code_10__
#define __leet_code_10__

#include<iostream>
#include<string>

class Solution {
public:
	bool isMatch(std::string s, std::string p) {
		// 先预处理一下p字符串，将可能出现的多个***合并为一个*
		std::string match = "";
		char before = p[0];
		match += p[0];
		for (int i = 1; i < p.size(); i++) {
			if ( (before == '*' && p[i] == '*') ) {
				continue;
			}
			match += p[i];
			before = p[i];
		}

		return isMatchDFS(s, match);
		
	}

private:
	bool isMatchDFS(std::string s, std::string p) {
		if (s.size() == 0 && p.size() == 0) {
			return true;
		}
		int i = 0, j = 0;
		while (true) {
			if (i >= s.size() || j >= p.size()) {
				break;
			}

			if (j + 1 < p.size()) {
				if (p[j + 1] == '*') {
					if (p[j] == '.') {
						std::string new_p = p.substr(j + 2, p.size() - j - 1);
						for (int k = i; k <= s.size(); k++) {
							std::string new_s = s.substr(k, s.size() - k + 1);
							bool success = isMatchDFS(new_s, new_p);
							if (success) {
								return true;
							}
						}
						return false;
					}
					else {
						std::string new_p = p.substr(j + 2, p.size() - j - 1);
						for (int k = i; k <= s.size(); k++) {
							std::string new_s = s.substr(k, s.size() - k + 1);
							bool success = isMatchDFS(new_s, new_p);
							if (success) {
								return true;
							}
							if (s[k] != p[j]) {
								break;
							}
						}
						return false;
					}
				}
				else {
					if (s[i] == p[j] || p[j] == '.') {
						i++;
						j++;
					}
					else {
						return false;
					}
				}
			}
			else {
				// 当前已经读到p的最后一个字符
				if (s[i] == p[j] || p[j] == '.') {
					i++;
					j++;
				}
				else {
					return false;
				}
			}
		}

		if (i == s.size() && j == p.size()) {
			return true;
		}
		else if (i == s.size() && j < p.size()) {
			while (j<p.size()){
				if (j + 1 < p.size() && p[j+1] == '*') {
					j += 2;
				}
				else {
					return false;
				}
			}
			return true;
		}
		else {
			return false;
		}

	}

};

#endif // __leet_code_10__