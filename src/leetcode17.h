/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-16 18:21:18
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode17.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 15:35:11
 * @Editor: Bingyang Jin
 * @Description: create TABLE_METHOD, TIME 0ms, 100.00%, MEMORY 6.4MB and 51.30%
 */

#ifndef __leet_code_17_h__ 
#define __leet_code_17_h__

#include<iostream>
#include<queue>
#include<string>
#include<vector>

class Solution {
public:
	std::vector<std::string> letterCombinations(std::string digits) {
		std::vector<std::string> result;
		if (digits.size() == 0) {
			return result;
		}

		std::queue<std::string> q;
		q.emplace("");
		for (int i = 0; i < digits.size(); i++) {
			int number = digits[i] - '0';
			while (q.size() > 0) {
				std::string top = q.front();
				if (top.size() > i) {
					break;
				}
				q.pop();

				switch (number){
				case 2: {
					q.emplace(top + "a");
					q.emplace(top + "b");
					q.emplace(top + "c");
					break;
				}
				case 3: {
					q.emplace(top + "d");
					q.emplace(top + "e");
					q.emplace(top + "f");
					break;
				}
				case 4: {
					q.emplace(top + "g");
					q.emplace(top + "h");
					q.emplace(top + "i");
					break;
				}
				case 5: {
					q.emplace(top + "j");
					q.emplace(top + "k");
					q.emplace(top + "l");
					break;
				}
				case 6: {
					q.emplace(top + "m");
					q.emplace(top + "n");
					q.emplace(top + "o");
					break;
				}
				case 7: {
					q.emplace(top + "p");
					q.emplace(top + "q");
					q.emplace(top + "r");
					q.emplace(top + "s");
					break;
				}
				case 8: {
					q.emplace(top + "t");
					q.emplace(top + "u");
					q.emplace(top + "v");
					break;
				}
				case 9: {
					q.emplace(top + "w");
					q.emplace(top + "x");
					q.emplace(top + "y");
					q.emplace(top + "z");
					break;
				}
				default:
					break;
				}


			}
		}

		int n = q.size();
		for (int i = 0; i < n; i++) {
			result.emplace_back(q.front());
			q.pop();
		}

		return result;
	}
};

#endif // __leet_code_17_h__