/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-17 11:03:03
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode22.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-17 11:13:40
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 4ms, 67.43%, MEMORY 13.4MB and 41.41%
 */

#ifndef __leet_code_22_h__ 
#define __leet_code_22_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> result;
		n_ = n;
		
		dfs(result, "", 0, 0);

		return result;
	}
private:

	void dfs(std::vector<std::string> &result,  std::string current_string, int left, int right) {
		if (left == n_) {
			current_string += std::string(n_ - right, ')');
			result.emplace_back(current_string);
			return;
		}

		dfs(result, current_string + "(", left + 1, right);
		if (left > right) {
			dfs(result, current_string + ")", left, right + 1);
		}

		return;
	}

	int n_;
};

#endif // __leet_code_22_h__