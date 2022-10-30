/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-30 11:04:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode946.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-30 11:16:36
 * @Editor: Bingyang Jin
 * @Description: create DOUBLE_POINTER_METHOD, TIME 12ms, 27.25%, MEMORY 15MB and 15.67%
 */

#ifndef __leet_code_946__
#define __leet_code_946__

#include<iostream>
#include<vector>
#include<stack>

class Solution {
public:
	bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
		std::stack<int> save;
		int i = 0, j = 0;
		while (true) {
			if (save.size() == 0) {
				if (i < pushed.size()) {
					save.emplace(pushed[i]);
					i++;
				}
				else {
					return true;
				}
			}
			else {
				int temp = save.top();
				if (temp == popped[j]) {
					save.pop();
					j++;
				}
				else if(i<pushed.size()){
					save.emplace(pushed[i]);
					i++;
				}
				else {
					return false;
				}
			}
		}

		return true;
	}
};

#endif // __leet_code_946__