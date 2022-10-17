/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-17 13:52:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode940.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-17 15:11:07
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 8ms, 56.09%, MEMORY 6.8MB and 15.00%
 */

#ifndef __leet_code_940__
#define __leet_code_940__

#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>

class Solution {
public:
	int distinctSubseqII(std::string s) {

		// 令 str[i] 表示从 0-i 的子序列集合，str[i][j] 表示 0-i 的子序列集合中子序列的索引
		// 定义“str[i][j]针对字符 c 可以拷贝增加”为：构造字符串 str_temp = str[i][j] + c，且 str_temp 不存在于 str[i] 中。
		// 令 dp[i] 表示从 0-i 的子序列数目，令 del[i][c] 表示第 i 的子序列集合 str[i] 中，针对字符 c ，不可以拷贝增加的子字符串。
		// 令 add_c[i][c] 表示在 0-i-1 中，字符 c 是否出现过，出现过 add_c[i][c] = 0，否则为 1.
		// 基于上述定义，dp[i+1] = dp[i] * 2 - del[i][c] + add_c[i][c];
		//						    del[i+1][c] = dp[i];

		std::unordered_set<char> character;
		character.emplace(s[0]);
		long dp = 1;
		std::unordered_map<char, long>del;
		// 初始化
		for (int i = 0; i < 26; i++) {
			del['a' + i] = 0;
		}

		for (int i = 1; i < s.size(); i++) {
			char c = s[i];
			long dp_next = dp * 2 - del[c];
			if (character.count(c) == 0) {
				dp_next++;
				character.emplace(c);
			}
			while (dp_next < 0) {
				dp_next += pow(10, 9) + 7;
			}
			while (dp_next > pow(10, 9) + 7) {
				dp_next -= pow(10, 9) + 7;
			}

			del[c] = dp;
			dp = dp_next;
		}

		return dp;
	}
};

#endif // __leet_code_940__