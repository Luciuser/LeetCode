/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-10 09:16:01
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode753.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-10 11:54:35
 * @Editor: Bingyang Jin
 * @Description: create ANSWER_DFS_METHOD, TIME 4ms, 86.44%, MEMORY 8.8MB and 67.80%
 */

#ifndef __leet_code_753__
#define __leet_code_753__

#include<iostream>
#include<string>
#include<unordered_set>

class Solution {
private:
	std::unordered_set<int> seen;
	std::string ans;
	int highest;
	int k;

public:
	void dfs(int node) {
		for (int x = 0; x < k; ++x) {
			int nei = node * 10 + x;
			if (!seen.count(nei)) {
				seen.insert(nei);
				dfs(nei % highest);
				ans += (x + '0');
			}
		}
	}

	std::string crackSafe(int n, int k) {
		highest = pow(10, n - 1);
		this->k = k;
		dfs(0);
		ans += std::string(n - 1, '0');
		return ans;
	}
};

#endif // __leet_code_753__