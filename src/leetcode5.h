/*
 * @Author: Bingyang Jin
 * @Date: 2022-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode5.h
 * @Description: create the file and ITERATROR_METHOD and SLIDE_WINDOW_METHOD
 */

 /*
 * @EditTime: 2022-08-09 15:20:50
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 680ms, 9.02%, MEMORY 420.9MB and 5.16%
 */

 /*
 * @EditTime: 2022-08-09 15:49:57
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 500ms, 25.49%, MEMORY 276.4MB and 24.24%
 */

 /*
 * @EditTime: 2022-08-09 16:14:12
 * @Editor: Bingyang Jin
 * @Description: create CENTER_EXPENSION_METHOD, TIME 48ms, 64.81%, MEMORY 93.4MB and 36.76%
 */

#ifndef __leet_code_5__
#define __leet_code_5__

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

//#define ITERATROR_METHOD // �ö��д洢��ǰ��Ҫ�����Ӵ����������£�O(n^3)����ʱ
//#define SLIDE_WINDOW_METHOD // �������ڣ��뱩��������iΪ���ģ��жϸû��������Ƿ��㹻����TIME 680ms, 9.02%, MEMORY 420.9MB and 5.16%
//#define DYNAMIC_PROGRAMMING_METHOD // ��̬�滮��O(n^2)��TIME 500ms, 25.49%, MEMORY 276.4MB and 24.24%
#define CENTER_EXPENSION_METHOD	// ������չ������ʵ��������Ļ������ڷ����

#ifdef ITERATROR_METHOD
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		int n = s.size();
		std::queue<std::string> temp;
		std::unordered_map<std::string, int> string2num;
		temp.push(s);

		while (true) {
			std::string crtString = temp.front();
			temp.pop();

			bool isRight = true;
			for (int i = 0; i < crtString.size() / 2; i++) {
				int begin = i;
				int end = crtString.size() - 1 - i;
				if (crtString[begin] != crtString[end]) {
					isRight = false;
					break;
				}
			}

			if (isRight) {
				return crtString;
			}
			else {
				std::string left = crtString.substr(0, crtString.size() - 1);
				std::string right = crtString.substr(1, crtString.size() - 1);
				if (string2num.count(left) == 0) {
					temp.push(left);
					string2num[left] = 1;
				}
				if (string2num.count(right) == 0) {
					temp.push(right);
					string2num[right] = 1;
				}
			}
		}
	}
};
#endif // ITERATROR_METHOD

#ifdef SLIDE_WINDOW_METHOD
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		std::string result = "";
		std::string temp = "";
		// ������������
		for (int i = 0; i < s.size(); i++) {
			if ((s.size() - i) * 2 - 1 < result.size()) {
				// ��iΪ���в����ܱ� result ����
				break;
			}

			temp = s[i];
			for (int j = 0; j < s.size(); j++) {
				if (i - j - 1 < 0 || i + j + 1 >= s.size()) {
					break;
				}
				if (s[i - j - 1] != s[i + j + 1]) {
					break;
				}
				temp = s[i - j - 1] + temp + s[i + j + 1];
			}

			if (temp.size() > result.size()) {
				result = temp;
			}
		}
		// ����ż������
		for (int i = 1; i < s.size(); i++) {
			// i ��ʾ����м�����
			if (i * 2 < result.size()) {
				continue;
			}
			if ((s.size() - i) * 2 < result.size()) {
				break;
			}

			temp = "";
			for (int j = 0; j < s.size(); j++) {
				if (i - j - 1 < 0 || i + j >= s.size()) {
					break;
				}
				if (s[i - j - 1] != s[i + j]) {
					break;
				}
				temp = s[i - j - 1] + temp + s[i + j];
			}
			if (temp.size() > result.size()) {
				result = temp;
			}
		}
		
		return result;
	}
};
#endif // SLIDE_WINDOW_METHOD

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {
public:
	std::string longestPalindrome(std::string s) {
		// �� P[i, j] Ϊ i �� j �����ַ�������̬�滮��ʽΪ��
		// P[i, j] = P[i+1, j-1] && s[i] == s[j]
		// ��̬�滮�ı߽�����Ϊ��
		// P[i, i] = true
		// p[i, j] = false, if j<i;
		// P[i, i+1] = (s[i] == s[i+1])

		int n = s.size();
		std::vector<std::vector<int>> P(n, std::vector<int>(n, 0));
		P[0][0] = 1;
		int min = 0;
		int max = 0;
		for (int i = 1; i < s.size(); i++) {
			P[i][i] = 1;
			P[i - 1][i] = s[i - 1] == s[i] ? 1 : 0;
			if (P[i - 1][i] == 1 && max - min == 0) {
				min = i - 1;
				max = i;
			}
		}


		for (int length = 2; length < s.size(); length++) {
			for (int i = 0; i + length < s.size(); i++) {
				P[i][i + length] = (P[i + 1][i + length - 1] == 1 && s[i] == s[i + length]) ? 1 : 0;
				if (P[i][i + length] == 1 && length > max - min) {
					min = i;
					max = i + length;
				}
			}
		}

		return s.substr(min, max - min + 1);

	}
};
#endif // DYNAMIC_PROGRAMMING_METHOD

#ifdef CENTER_EXPENSION_METHOD
class Solution {
public:

	std::pair<int, int> centerExpension(std::string s, const int begin, int end) {
		int i = begin;
		int j = end;
		while (true) {
			if (i - 1 < 0 || j + 1 >= s.size()) {
				break;
			}
			if (s[i - 1] == s[j + 1]) {
				i--;
				j++;
			}
			else {
				break;
			}
		}

		return std::pair<int, int>(i, j);
	}

	std::string longestPalindrome(std::string s) {
		// �� P[i, j] Ϊ i �� j �����ַ�������̬�滮��ʽΪ��
		// P[i, j] = P[i+1, j-1] && s[i] == s[j]
		// ��̬�滮�ı߽�����Ϊ��
		// P[i, i] = true
		// p[i, j] = false, if j<i;
		// ���������ֱ߽�����ֱ��������չ������չֹͣʱ����������

		int n = s.size();

		int min = 0;
		int max = 0;
		// P[0][0] ����չ�� min = max = 0
		for (int i = 1; i < n; i++) {
			auto str1 = centerExpension(s, i, i);
			if (str1.second - str1.first > max - min) {
				min = str1.first;
				max = str1.second;
			}
			if (s[i - 1] == s[i]) {
				auto str2 = centerExpension(s, i - 1, i);
				if (str2.second - str2.first > max - min) {
					min = str2.first;
					max = str2.second;
				}
			}
		}
		 
		return s.substr(min, max - min + 1);

	}
};
#endif // CENTER_EXPENSION_METHOD

#endif // __leet_code_5__