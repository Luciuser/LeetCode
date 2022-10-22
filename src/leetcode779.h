/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-20 10:47:45
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode779.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-20 10:58:02
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 5.02%
 */

#ifndef __leet_code_779__
#define __leet_code_779__

#include<iostream>
#include<stack>

class Solution {
public:
	int kthGrammar(int n, int k) {

		std::stack<int> tree; // 0 表示向左，1表示向右
		int temp = k - 1;
		for (int i = 1; i < n; i++) {
			tree.push(temp % 2);
			temp /= 2;
		}

		int result = 0;
		while (tree.size() > 0) {
			temp = tree.top();
			tree.pop();
			result = result ^ temp;
		}

		return result;
	}
};

#endif // __leet_code_779__