/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-06 10:44:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode828.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-06 11:30:39
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_DOUBLE，TIME OUT
 */

 /*
 * @EditTime: 2022-09-06 12:53:02
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_SINGLE，TIME 72ms, 18.16%, MEMORY 15.7MB and 47.97%
 */

#ifndef __leet_code_828__
#define __leet_code_828__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

//#define DYNAMIC_PROGRAMMING_DOUBLE // 二维动态规划，TIME OUT
#define DYNAMIC_PROGRAMMING_SINGLE // 一维动态规划，TIME 72ms, 18.16%, MEMORY 15.7MB and 47.97%

#ifdef DYNAMIC_PROGRAMMING_DOUBLE
class Solution {
public:
	int uniqueLetterString(std::string s) {

		std::vector<int> sameCharacterIndex(s.size(), -1); // 最大相同字符序号：第 i 个字母向前追溯，离它最近的相同字母。例如“AADBACCDS”存储的结果为{-1, 0, -1, -1, 1, -1, 5, 2, -1}

		// 建立 sameCharacterIndex，O(n)
		std::unordered_map<char, int> characterMap;	// 某个字母在字符串中最大的序号
		for (int i = 0; i < s.size(); i++) {
			if (characterMap.count(s[i]) == 0) {
				sameCharacterIndex[i] = -1;
				characterMap[s[i]] = i;
			}
			else {
				sameCharacterIndex[i] = characterMap[s[i]];
				characterMap[s[i]] = i;
			}
		}

		// 动态规划
		// 假设 str[i][j] 表示从 i 到 j 的子字符串，p[i][j] 表示 str[i][j] 中唯一的字符的个数，c[i] 表示第 i 个字母，则
		// 如果 c[j] 与 s[i][j-1] 中某一字符相同，并假设相同字符为 c[x]，且 i <= x <= j-1，进一步判断
		//			若 c[x] == c[y] && i <= y <= j-1 && x != y，则 p[i][j] = p[i][j-1];
		//			若不存在 c[x] == c[y] && i <= y <= j-1 && x != y，则 p[i][j] = p[i][j-1] - 1;
		// 如果 c[j] 与 s[i][j-1] 中字符均不相同，则 p[i][j] = p[i][j-1] + 1;
		// 基于上述最大相同字符序号，此判断条件可简化为：
		// 如果 i <= sameCharacterIndex[j]，说明存在字符 c[x] == c[j]，其中 x = sameCharacterIndex[j] 且 i <= x <= j-1，进一步判断
		//			若 i <= sameCharacterIndex[sameCharacterIndex[j]]，说明存在字符  c[x] == c[y] && i <= y < x <= j-1
		//         若 i > sameCharacterIndex[sameCharacterIndex[j]]，说明不存在存在字符  c[x] == c[y] && i <= y < x <= j-1
		// 如果 i > sameCharacterIndex[j]，则不存在相同字符

		// 建立初始情况，O(n)
		int sum = 0;
		std::vector<std::vector<int>> p(s.size(), std::vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++) {
			p[i][i] = 1;
		}
		sum += s.size();
		// 进行动态规划，O(n^2)
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j < s.size(); j++) {
				if (i <= sameCharacterIndex[j]) {
					if (i <= sameCharacterIndex[sameCharacterIndex[j]]) {
						p[i][j] = p[i][j - 1];
					}
					else {
						p[i][j] = p[i][j - 1] - 1;
					}
				}
				else {
					p[i][j] = p[i][j - 1] + 1;
				}
				sum += p[i][j];
			}
		}

		return sum;
	}
};
#endif // DYNAMIC_PROGRAMMING_DOUBLE

#ifdef DYNAMIC_PROGRAMMING_SINGLE
class Solution {
public:
	int uniqueLetterString(std::string s) {

		std::vector<int> sameCharacterIndex(s.size(), -1); // 最大相同字符序号：第 i 个字母向前追溯，离它最近的相同字母。例如“AADBACCDS”存储的结果为{-1, 0, -1, -1, 1, -1, 5, 2, -1}

		// 建立 sameCharacterIndex，O(n)
		std::unordered_map<char, int> characterMap;	// 某个字母在字符串中最大的序号
		for (int i = 0; i < s.size(); i++) {
			if (characterMap.count(s[i]) == 0) {
				sameCharacterIndex[i] = -1;
				characterMap[s[i]] = i;
			}
			else {
				sameCharacterIndex[i] = characterMap[s[i]];
				characterMap[s[i]] = i;
			}
		}

		// 动态规划
		// 假设 str[i][j] 表示从 i 到 j 的子字符串，p[i][j] 表示 str[i][j] 中唯一的字符的个数，p[j] 表示 str[0][j] 到 str[j][j] 共计 j 个字符串中唯一的字符的个数，既有 p[j] = p[0][j] + p[1][j] + …… + p[j][j]，c[i] 表示第 i 个字母，则
		// 如果 sameCharacterIndex[j] == x 且 0 <= x < j ，说明存在字符 c[x] == c[j]，对于 str[i][j] 而言：
		//        当 i <= x 时，找到 y = sameCharacterIndex[sameCharacterIndex[x]]
		//                若 y == -1，则对于 str[i][j-1] 而言，str[i][j] 均只包含 1 个 c[j]，在增加 c[j] 后，导致 p[i][j] = p[i][j-1] - 1；则有 temp -= x
		//                若 y != -1，
		//                        则对于 y < i <= x 而言，str[i][j] 均只包含 1 个 c[j]，在增加 c[j] 后，导致 p[i][j] = p[i][j-1] - 1；则有 temp -= (x - y)
		//                        则对于 0 <= i <= y 而言，str[i][j] 均包含 2 个以上 c[j]，在增加 c[j] 后，p[i][j] = p[i][j-1]，则 temp 不变
		//        当 x < i 时，则对于 str[i][j-1] 而言，str[i][j] 不包含字符 c[j]，有 p[i][j] = p[i][j-1] + 1; 因此有 temp += j - x
		// 如果 sameCharacterIndex[j] == -1，则不存在相同字符，p[0][j] = p[0][j-1] + 1; p[1][j] = p[1][j-1] + 1; …… ；则有 p[j] = p[j-1] + j
		// 综上所述，有：
		//         --------------- C ------------- C -------------- C
		//        0-------------- y -------------  x -------------- j
		//        在 [0, y] 区间内，temp 不增不减
		//        在 [y+1, x] 区间内，temp 每次减1
		//        在 [x+1, j] 区间内，temp 每次加1

		// 建立初始情况，O(1)
		int sum = 0;
		int p = 1;	// 对于 p[j] 而言，表示 p[j-1]，初始时为 p[0]

		sum += p;
		// 进行动态规划，O(n^2)
		for (int i = 1; i < s.size(); i++) {
			int temp = 0;
			int x = sameCharacterIndex[i];
			int y = -1;
			if (x != -1) {
				y = sameCharacterIndex[x];
			}
			
			temp -= (x - y);
			temp += (i - x);
			p += temp;
			sum += p;
		}

		return sum;
	}
};
#endif // DYNAMIC_PROGRAMMING_SINGLE



#endif // __leet_code_828__