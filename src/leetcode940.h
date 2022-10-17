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

		// �� str[i] ��ʾ�� 0-i �������м��ϣ�str[i][j] ��ʾ 0-i �������м����������е�����
		// ���塰str[i][j]����ַ� c ���Կ������ӡ�Ϊ�������ַ��� str_temp = str[i][j] + c���� str_temp �������� str[i] �С�
		// �� dp[i] ��ʾ�� 0-i ����������Ŀ���� del[i][c] ��ʾ�� i �������м��� str[i] �У�����ַ� c �������Կ������ӵ����ַ�����
		// �� add_c[i][c] ��ʾ�� 0-i-1 �У��ַ� c �Ƿ���ֹ������ֹ� add_c[i][c] = 0������Ϊ 1.
		// �����������壬dp[i+1] = dp[i] * 2 - del[i][c] + add_c[i][c];
		//						    del[i+1][c] = dp[i];

		std::unordered_set<char> character;
		character.emplace(s[0]);
		long dp = 1;
		std::unordered_map<char, long>del;
		// ��ʼ��
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