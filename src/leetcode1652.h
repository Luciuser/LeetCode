/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-24 10:02:17
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1652.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-24 10:34:06
 * @Editor: Bingyang Jin
 * @Description: create SLIDE_WINDOW_METHOD, TIME 4ms, 54.64%, MEMORY 8.2MB and 18.87%
 */

#ifndef __leet_code_1652__
#define __leet_code_1652__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
	std::vector<int> decrypt(std::vector<int>& code, int k) {
		if (k == 0) {
			return std::vector<int>(code.size(), 0);
		}

		int n = code.size();
		std::queue<int> window;
		std::vector<int> result;
		//int direction = 1;
		//if (k < 0) {
		//	direction = -1;
		//}
		// ³õÊ¼»¯window
		int index = k > 0 ? 1 : k;
		int destination = k > 0 ? k + 1 : 0;
		int sum = 0;
		while (index != destination) {
			int temp = index;
			if (index < 0) {
				temp += n;
			}
			if (index >= n) {
				temp -= n;
			}
			window.emplace(code[temp]);
			sum += code[temp];
			index++;
		}
		result.push_back(sum);
		
		index = k > 0 ? k + 1 : 0;
		for (int i = 1; i < code.size(); i++) {
			if (index < 0) {
				index += n;
			}
			if (index >= n) {
				index -= n;
			}
			int top = window.front();
			window.pop();
			window.emplace(code[index]);
			sum -= top;
			sum += code[index];
			result.push_back(sum);
			index++;
		}

		return result;
	}
};

#endif // __leet_code_1652__