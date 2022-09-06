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
 * @Description: create DYNAMIC_PROGRAMMING_DOUBLE��TIME OUT
 */

 /*
 * @EditTime: 2022-09-06 12:53:02
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_SINGLE��TIME 72ms, 18.16%, MEMORY 15.7MB and 47.97%
 */

#ifndef __leet_code_828__
#define __leet_code_828__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

//#define DYNAMIC_PROGRAMMING_DOUBLE // ��ά��̬�滮��TIME OUT
#define DYNAMIC_PROGRAMMING_SINGLE // һά��̬�滮��TIME 72ms, 18.16%, MEMORY 15.7MB and 47.97%

#ifdef DYNAMIC_PROGRAMMING_DOUBLE
class Solution {
public:
	int uniqueLetterString(std::string s) {

		std::vector<int> sameCharacterIndex(s.size(), -1); // �����ͬ�ַ���ţ��� i ����ĸ��ǰ׷�ݣ������������ͬ��ĸ�����硰AADBACCDS���洢�Ľ��Ϊ{-1, 0, -1, -1, 1, -1, 5, 2, -1}

		// ���� sameCharacterIndex��O(n)
		std::unordered_map<char, int> characterMap;	// ĳ����ĸ���ַ������������
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

		// ��̬�滮
		// ���� str[i][j] ��ʾ�� i �� j �����ַ�����p[i][j] ��ʾ str[i][j] ��Ψһ���ַ��ĸ�����c[i] ��ʾ�� i ����ĸ����
		// ��� c[j] �� s[i][j-1] ��ĳһ�ַ���ͬ����������ͬ�ַ�Ϊ c[x]���� i <= x <= j-1����һ���ж�
		//			�� c[x] == c[y] && i <= y <= j-1 && x != y���� p[i][j] = p[i][j-1];
		//			�������� c[x] == c[y] && i <= y <= j-1 && x != y���� p[i][j] = p[i][j-1] - 1;
		// ��� c[j] �� s[i][j-1] ���ַ�������ͬ���� p[i][j] = p[i][j-1] + 1;
		// �������������ͬ�ַ���ţ����ж������ɼ�Ϊ��
		// ��� i <= sameCharacterIndex[j]��˵�������ַ� c[x] == c[j]������ x = sameCharacterIndex[j] �� i <= x <= j-1����һ���ж�
		//			�� i <= sameCharacterIndex[sameCharacterIndex[j]]��˵�������ַ�  c[x] == c[y] && i <= y < x <= j-1
		//         �� i > sameCharacterIndex[sameCharacterIndex[j]]��˵�������ڴ����ַ�  c[x] == c[y] && i <= y < x <= j-1
		// ��� i > sameCharacterIndex[j]���򲻴�����ͬ�ַ�

		// ������ʼ�����O(n)
		int sum = 0;
		std::vector<std::vector<int>> p(s.size(), std::vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++) {
			p[i][i] = 1;
		}
		sum += s.size();
		// ���ж�̬�滮��O(n^2)
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

		std::vector<int> sameCharacterIndex(s.size(), -1); // �����ͬ�ַ���ţ��� i ����ĸ��ǰ׷�ݣ������������ͬ��ĸ�����硰AADBACCDS���洢�Ľ��Ϊ{-1, 0, -1, -1, 1, -1, 5, 2, -1}

		// ���� sameCharacterIndex��O(n)
		std::unordered_map<char, int> characterMap;	// ĳ����ĸ���ַ������������
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

		// ��̬�滮
		// ���� str[i][j] ��ʾ�� i �� j �����ַ�����p[i][j] ��ʾ str[i][j] ��Ψһ���ַ��ĸ�����p[j] ��ʾ str[0][j] �� str[j][j] ���� j ���ַ�����Ψһ���ַ��ĸ��������� p[j] = p[0][j] + p[1][j] + ���� + p[j][j]��c[i] ��ʾ�� i ����ĸ����
		// ��� sameCharacterIndex[j] == x �� 0 <= x < j ��˵�������ַ� c[x] == c[j]������ str[i][j] ���ԣ�
		//        �� i <= x ʱ���ҵ� y = sameCharacterIndex[sameCharacterIndex[x]]
		//                �� y == -1������� str[i][j-1] ���ԣ�str[i][j] ��ֻ���� 1 �� c[j]�������� c[j] �󣬵��� p[i][j] = p[i][j-1] - 1������ temp -= x
		//                �� y != -1��
		//                        ����� y < i <= x ���ԣ�str[i][j] ��ֻ���� 1 �� c[j]�������� c[j] �󣬵��� p[i][j] = p[i][j-1] - 1������ temp -= (x - y)
		//                        ����� 0 <= i <= y ���ԣ�str[i][j] ������ 2 ������ c[j]�������� c[j] ��p[i][j] = p[i][j-1]���� temp ����
		//        �� x < i ʱ������� str[i][j-1] ���ԣ�str[i][j] �������ַ� c[j]���� p[i][j] = p[i][j-1] + 1; ����� temp += j - x
		// ��� sameCharacterIndex[j] == -1���򲻴�����ͬ�ַ���p[0][j] = p[0][j-1] + 1; p[1][j] = p[1][j-1] + 1; ���� ������ p[j] = p[j-1] + j
		// �����������У�
		//         --------------- C ------------- C -------------- C
		//        0-------------- y -------------  x -------------- j
		//        �� [0, y] �����ڣ�temp ��������
		//        �� [y+1, x] �����ڣ�temp ÿ�μ�1
		//        �� [x+1, j] �����ڣ�temp ÿ�μ�1

		// ������ʼ�����O(1)
		int sum = 0;
		int p = 1;	// ���� p[j] ���ԣ���ʾ p[j-1]����ʼʱΪ p[0]

		sum += p;
		// ���ж�̬�滮��O(n^2)
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