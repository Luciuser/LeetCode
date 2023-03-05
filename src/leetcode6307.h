/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode6307.h
 * @Description: create the file
 */

 /*
 * @Editor: Bingyang Jin
 * @Description: Leetcode week competition 335
 */

#ifndef __leet_code_6307_h__
#define __leet_code_6307_h__

#include<iostream>

class Solution {
public:
	int passThePillow(int n, int time) {
		int x = time / (n - 1);
		int mod = time % (n - 1);

		if (x % 2 == 0) {
			return mod + 1;
		}
		else {
			return n - mod;
		}
	}
};

#endif // __leet_code_6307_h__