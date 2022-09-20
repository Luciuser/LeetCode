/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-12 16:47:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode3.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-12 17:11:17
 * @Editor: Bingyang Jin
 * @Description: create PRE_SLIDE_WINDOW��TIME 16ms, 70.04%, MEMORY 9.4MB and 49.45%
 */

#ifndef __leet_code_3__
#define __leet_code_3__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s) {
		// Ԥ����ȷ���� i ���ַ�����ߣ��������������ͬ�ַ�������
		std::vector<int> same; // �� i ���ַ���߾������������ͬ�ַ���������������Ϊ -1
		std::unordered_map<char, int> character; // �� i ���ַ���ǰ��������λ��
		for (int i = 0; i < s.size(); i++) {
			if (character.count(s[i]) == 0) {
				same.push_back(-1);
				character[s[i]] = i;
			}
			else {
				same.push_back(character[s[i]]);
				character[s[i]] = i;
			}
		}

		int begin = 0; // ��ǰ�ַ�������ʼ����λ��
		int length = 0;	// ��ǰ�ַ����ĳ���
		int max = 0; // ��ǰ�����ַ�������
		for (int i = 0; i < s.size(); i++) {
			if (begin <= same[i]) {
				// �ڵ�ǰ�ַ����ڳ����ظ�
				length -= (same[i] + 1 - begin);
				begin = same[i] + 1;
			}
			length++;
			max = length > max ? length : max;
		}
		
		return max;
	}
};

#endif // __leet_code_3__