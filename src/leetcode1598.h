/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-09 09:56:09
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1598.h
 * @Description: create the file
 */

#ifndef __leet_code_1598__
#define __leet_code_1598__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
	int minOperations(std::vector<std::string>& logs) {
		int depth = 0;
		for (int i = 0; i < logs.size(); i++) {
			if (logs[i] == "../") {
				if (depth > 0) {
					depth--;
				}
			}
			else if (logs[i] == "./") {
			}
			else {
				depth++;
			}
		}
		return depth;
	}
};

#endif // __leet_code_1598__