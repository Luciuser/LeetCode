/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-28 10:28:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode10.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-28 10:00:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 24ms, 31.21%, MEMORY 12.5MB and 38.30%
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
		char before = p[0];
		while (true) {
			if (i >= s.size() || j >= p.size()) {
				break;
			}

			if (p[j] == '*') {
				if (before == '.') {
					if (j + 1 >= p.size()) {
						return true;
					}
					std::string new_p = p.substr(j + 1, p.size() - j);
					for (int k = i + 1; k < s.size(); k++) {
						std::string new_s = s.substr(k, s.size() - k + 1);
						bool success = isMatchDFS(new_s, new_p);
						if (success) {
							return true;
						}
					}
					return false;
				}
				else {
					std::string new_p = p.substr(j + 1, p.size() - j);
					if (new_p == "") {
						if (i + 1 == s.size() && s[i] == before) {
							return true;
						}
						else {
							return false;
						}
					}
					for (int k = i; k < s.size(); k++) {
						if (s[k] == before) {
							std::string new_s = s.substr(k, s.size() - k + 1);
							bool success = isMatchDFS(new_s, new_p);
							if (success) {
								return true;
							}
						}
						else {
							std::string new_s = s.substr(k, s.size() - k + 1);
							bool success = isMatchDFS(new_s, new_p);
							if (success) {
								return true;
							}
							break;
						}
					}
					return false;
				}
			}
			else {
				if (s[i] == p[j] || p[j] == '.') {
					before = p[j];
					i++;
					j++;
				}
				else {
					j++;
					if (j >= p.size()) {
						return false;
					}
				}
			}
		}

		if (i == s.size() && j == p.size()) {
			return true;
		}
		else {
			return false;
		}

	}

};

#endif // __leet_code_10__