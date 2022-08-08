/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-08 13:35:42
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode761.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-08 15:03:03
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME WRONG(0ms, 100.00%), MEMORY 6.2 MB and 53.03%
 */

 /*
 * @EditTime: 2022-08-08 15:58:45
 * @Editor: Bingyang Jin
 * @Description: create DIVIDE_METHOD, TIME WRONG(0ms, 100.00%), MEMORY 6.4 MB and 10.60%
 */

#ifndef __leet_code_761__
#define __leet_code_761__

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

//#define VIOLENCE_METHOD	// 暴力解法，直接暴力比较，并循环进行
#define DIVIDE_METHOD		// 分治法

#ifdef VIOLENCE_METHOD
class Solution {
public:
	std::string makeLargestSpecial(std::string s) {

		bool isChange = true;
		std::string result = s;
		while (isChange) {
			isChange = false;
			for (int i = 0; i < result.size(); i++) {
				if (result[i] == '0') {
					continue;
				}
				int num1 = 1;	// 1 的数量
				int num0 = 0;	// 0 的数量
				int end = -1;
				for (int j = i + 1; j < result.size(); j++) {
					result[j] == '1' ? num1++ : num0++;
					if (num1 == num0) {
						end = j;
						break;
					}
				}
				if (end == -1 || end >= result.size() - 1) {
					// 没找到自i开始的特殊子串，或者该特殊子串达到字符串末尾
					continue;
				}

				if (result[end + 1] == '0') {
					// 没有相邻的子串
					continue;
				}
				num1 = 1;
				num0 = 0;
				int end2 = -1;
				for (int j = end + 2; j < result.size(); j++) {
					result[j] == '1' ? num1++ : num0++;
					if (num1 == num0) {
						end2 = j;
						break;
					}
				}
				if (end2 == -1) {
					// 没找到自 end+1 开始的特殊子串
					continue;
				}


				bool change = false;
				for (int j = 0; j < end2 - end; j++) {
					if (result[i + j] == '1' && result[end + 1 + j] == '0') {
						break;
					}
					if (result[i + j] == '0' && result[end + 1 + j] == '1') {
						change = true;
						break;
					}
				}
				if (change == false) {
					continue;
				}

				// 进行替换
				std::string str1 = result.substr(0, i);
				std::string str2 = result.substr(i, end - i + 1);
				std::string str3 = result.substr(end + 1, end2 - end);
				std::string str4 = result.substr(end2 + 1, result.size() - end2 - 1);

				result = str1 + str3 + str2 + str4;
				isChange = true;
			}
		}

		return result;
	}
};
#endif // VIOLENCE_METHOD

#ifdef DIVIDE_METHOD
class Solution {
public:
	// 保证输入的 s 一定是一个特殊序列
	std::string makeLargestSpecial(std::string s) {

		// 当 s=="" 或 s=="10"
		if (s.size() <= 2) {
			return s;
		}

		std::string result = "";

		// 分：将s切分为多个子串，每个子串删除第一个字符1和最后一个字符0
		std::vector<std::string> subStrings;
		int temp = 0;
		int begin = 0;
		for (int i = 0; i < s.size(); i++) {
			s[i] == '1' ? temp++ : temp--;
			if (temp == 0) {
				std::string str = s.substr(begin + 1, i - begin - 1);
				begin = i + 1;
				// 递归处理每一个子串
				str = makeLargestSpecial(str);
				subStrings.push_back("1" + str + "0");
			}
		}

		// 合：对多个子串进行排序，同时给每个子串前增加1，子串后增加0
		std::sort(subStrings.begin(), subStrings.end(), [=](std::string a, std::string b) {
			std::string ab = a + b;
			std::string ba = b + a;
			return ab > ba;
		});
		for (int i = 0; i < subStrings.size(); i++) {
			result += subStrings[i];
		}

		return result;
	}
};
#endif // DIVIDE_METHOD




#endif // __leet_code_761__