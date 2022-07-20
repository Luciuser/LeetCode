#ifndef __leet_code_965__
#define __leet_code_965__

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

//#define VIOLENCE_METHODS	// 暴力法遍历
//#define MATH_METHODS		// 截成多段，通过递归计算各段总和
#define DYNAMIC_PROGRAMMING_METHODS	// 动态规划

#ifdef VIOLENCE_METHODS
class Solution {
public:
	int findSubstringInWraproundString(std::string p) {
		std::map<std::string, int> str2count;

		int sum = 0;
		for (int i = 0; i < p.size(); i++) {
			char c = p[i];
			std::string str = "" + c;
			if (str2count.count(str) == 0) {
				sum++;
				str2count[str] = 1;
			}
			for (int j = i + 1; j < p.size(); j++) {
				if (p[j] - c == 1 || (c == 'z' && p[j] == 'a')) {
					str += c;
					c = p[j];
					if (str2count.count(str) == 0) {
						sum++;
						str2count[str] = 1;
					}
					continue;
				}
				else {
					break;
				}
			}
		}

		return sum;
	}
};
#endif // VIOLENCE_METHODS

#ifdef MATH_METHODS
class Solution {
public:

	std::map<std::string, int> str2count;

	// 对于有序的字符串，通过递归求其子串数
	int getSubstringNumFromStr(std::string p) {
		int sum = 0;
		if (str2count.count(p) == 0) {
			sum++;
			str2count[p] = 1;
			for (int i = 1; i < p.size(); i++) {
				sum += getSubstringNumFromStr(p.substr(0, i));
				sum += getSubstringNumFromStr(p.substr(i, p.size() - i));
			}
		}
		return sum;
	}

	int findSubstringInWraproundString(std::string p) {

		std::vector<int> segments;
		segments.push_back(0);
		for (int i = 1; i < p.size(); i++) {
			if(p[i]-p[i-1]==1 || (p[i]=='a' && p[i-1]=='z')){}
			else {
				segments.push_back(i);
			}
		}
		segments.push_back(p.size());

		int sum = 0;
		for (int i = 1; i < segments.size(); i++) {
			std::string str = p.substr(segments[i - 1], segments[i] - segments[i - 1]);
			sum += getSubstringNumFromStr(str);
		}

		return sum;
	}
};
#endif // MATH_METHODS

#ifdef DYNAMIC_PROGRAMMING_METHODS
class Solution {
public:
	int findSubstringInWraproundString(std::string p) {

		std::vector<int> char2count(26, 0);

		int k = 1;
		char2count[p[0] - 'a'] = 1;
		for (int i = 1; i < p.size(); i++) {
			if (p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z')) {
				k++;
			}
			else {
				k = 1;
			}
			char2count[p[i] - 'a'] = char2count[p[i] - 'a'] > k ? char2count[p[i] - 'a'] : k;
		}

		int sum = 0;
		for (int i = 0; i < char2count.size(); i++) {
			sum += char2count[i];
		}
		
		return sum;
	}
};
#endif // DYNAMIC_PROGRAMMING_METHODS


#endif