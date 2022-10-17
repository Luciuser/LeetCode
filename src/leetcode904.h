/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-17 12:14:54
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode904.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-17 12:48:19
 * @Editor: Bingyang Jin
 * @Description: create TYPE_METHOD, TIME 152ms, 28.52%, MEMORY 71.4MB and 12.30%
 */

 /*
 * @EditTime: 2022-10-17 13:43:22
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW, TIME 168ms, 12.69%, MEMORY 69.4MB and 42.28%
 */


#ifndef __leet_code_904__
#define __leet_code_904__

#include<iostream>
#include<vector>
#include<unordered_map>

//#define TYPE_METHOD // 同时只能出现两个type，TIME 152ms, 28.52%, MEMORY 71.4MB and 12.30%
#define SLIDE_WINDOW // 滑动窗口，TIME 168ms, 12.69%, MEMORY 69.4MB and 42.28%

#ifdef TYPE_METHOD
class Solution {
public:
	int totalFruit(std::vector<int>& fruits) {

		std::unordered_map<int, int> typeCount;

		int max = 1;
		int type1, type2;
		type1 = fruits[0];
		type2 = -1;
		typeCount[type1] = 1;
		typeCount[type2] = 0;

		int remain = 0;
		for (int i = 1; i < fruits.size(); i++) {
			if (fruits[i] == type1) {
				typeCount[type1]++;

				if (type2 != -1) {
					int temp = type1;
					type1 = type2;
					type2 = temp;

					remain = 1;
				}
			}
			else if (fruits[i] == type2) {
				typeCount[type2]++;
				remain++;
			}
			else if (type2 == -1) {
				type2 = fruits[i];
				typeCount[type2] = 1;
				remain = 1;
			}
			else {
				typeCount[type1] = 0;
				typeCount[type2] = remain;
				remain = 1;
				type1 = type2;
				type2 = fruits[i];
				typeCount[type2] = 1;
			}

			max = max > (typeCount[type1] + typeCount[type2]) ? max : (typeCount[type1] + typeCount[type2]);
		}

		return max;
	}
};
#endif // TYPE_METHOD

#ifdef SLIDE_WINDOW
class Solution {
public:
	int totalFruit(std::vector<int>& fruits) {
		
		std::unordered_map<int, int> typeCount;

		int left = 0;
		int max = 0;
		for (int right = 0; right < fruits.size(); right++) {
			typeCount[fruits[right]]++;
			while (typeCount.size() > 2) {
				typeCount[fruits[left]]--;
				if (typeCount[fruits[left]] == 0) {
					typeCount.erase(fruits[left]);
				}
				left++;
				continue;
			}
			if (right - left + 1 > max) {
				max = right - left + 1;
			}
		}

		return max;
	}
};
#endif // SLIDE_WINDOW

#endif // __leet_code_904__