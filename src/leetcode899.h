/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-03 13:37:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode622.h
 * @Description: create the file and direct method, TIME 4 ms, MEMORY 6.2 MB
 */

 /*
 * @EditTime: 2022-08-03 14:00:52
 * @Editor: Bingyang Jin
 * @Description: create MINIMUM_REPRESENTATION_METHOD, TIME 0 ms, MEMORY 6.2 MB
 */

#ifndef __leet_code_899__
#define __leet_code_899__

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

//#define DIRECTION_METHOD // ��k=1ʱ��ֱ�ӱ����жϣ�O(n^2)ʱ�临�Ӷ�
#define MINIMUM_REPRESENTATION_METHOD // ��k=1ʱ������С��ʾ����O(nlogn)ʱ�临�Ӷ�


class Solution {
public:
	std::string orderlyQueue(std::string s, int k) {
		
		// ���ݸ��Ӽ���֤������ k==1 ʱ���п����޷��õ�s��������������ֵ���С���ַ���
		// ���� k>= 2 ʱ��ÿ���� s.length() ���ƶ������Խ� [1, k-1] ���ַ����õ����е��κ�λ�ã����һ�����Եõ� s ����������ֵ���С���ַ���
		std::string result = s;
		if (k == 1) {
#ifdef DIRECTION_METHOD
			std::string temp = s;
			for (int i = 1; i < s.size(); i++) {
				char c = temp[0];
				temp.erase(temp.begin());
				temp += c;
				if (result > temp) {
					result = temp;
				}
			}
#endif // DIRECTION_METHOD

#ifdef MINIMUM_REPRESENTATION_METHOD
			int min = 0;
			for (int i = 1; i < s.size(); i++) {
				int index = i;
				for (int j = 0; j < s.size(); j++) {
					int minIndex = (min + j) % s.size();
					int tempIndex = (i + j) % s.size();
					if (s[minIndex] < s[tempIndex]) {
						i += j;
						break;
					}
					if (s[minIndex] > s[tempIndex]) {
						min = index;
						break;
					}
				}
			}
			result = s.substr(min, s.size() - min);
			result += s.substr(0, min);
#endif // MINIMUM_REPRESENTATION_METHOD
		}
		else {
			std::sort(result.begin(), result.end());
		}
		return result;
	}
};

#endif // __leet_code_899__