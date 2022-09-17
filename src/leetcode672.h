/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-15 15:52:26
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode672.h
 * @Description: create the file and ITERATROR_METHOD and SLIDE_WINDOW_METHOD
 */

 /*
 * @EditTime: 2022-09-15 15:20:50
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 680ms, 9.02%, MEMORY 420.9MB and 5.16%
 */

#ifndef __leet_code_672__
#define __leet_code_672__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
	int flipLights(int n, int presses) {
		// ���ڵ� 1 2 3 4 5 6 7 8 9 10 ���� ���ԣ�����7�ŵƸ���1�ŵƣ�6�š�8�ŵƸ���2�ŵƣ�5�ŵơ�9�ŵƸ���3�ŵƣ�10�ŵƸ���4�ŵơ�
		// ��˵� n>4 ʱ��ֻ���ж�ǰ4���Ƽ���

		// �� int ����ʾǰ 4 �ŵƵ��������СֵΪ0�����ֵΪ15
		std::unordered_set<int> result;	// ���ճ��ֵĽ��
		std::vector<int>lightIndex(16, -1);
		std::vector<int>lightIndexNext(16, -1);

		int open[4] = { 15, 5, 10, 9 };
		int time = presses;
		// ��һ�β���
		for (int j = 0; j < 4; j++) {
			int light = 15 ^ open[j]; // ����������ȡ��
			if (time % 2 == 0) {
				result.emplace(light);
			}
			lightIndex[light] = time - 1;
		}
		time--;
		if (time == -1) {
			return 1;
		}
		else if (time == 0) {
			return result.size();
		}

		// ����Ķ��ѭ��
		while (true) {
			for (int i = 0; i < 16; i++) {
				if (lightIndex[i] == -1) {
					continue;
				}  
				for (int j = 0; j < 4; j++) {
					int light = i ^ open[j]; // ����������ȡ��
					if (time % 2 == 0) {
						
					}
				}
			}

		}

		return result.size();
	}
};

#endif // __leet_code_672__