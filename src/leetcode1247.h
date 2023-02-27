/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-25 09:59:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2357.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-24 15:46:52
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6.2MB and 5.70%
 */

#ifndef __leet_code_1247_h__ 
#define __leet_code_1247_h__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumSwap(std::string s1, std::string s2) {
		// 由题意，注意到：
		// 会有两种情况不同：
		// (1) XX    (2) XY 
		//      YY     (3) YX
		// 对于1情况，只需一步即可将交换两组不相同的结果；对于2情况，需要两步来交换两组不同的结果
		// 因此对于上述两种情况，先内部自己交换，最后再一起交换

		int num_1 = 0;
		int num_2 = 0;

		int n = s1.size();
		for (int i = 0; i < n; i++) {
			if (s1[i] == 'x' && s2[i] == 'y') {
				num_1++;
			}
			else if(s1[i] == 'y' && s2[i] == 'x'){
				num_2++;
			}
		}

		int sum = 0;
		sum += num_1 / 2;
		sum += num_2 / 2;
		if (num_1 % 2 == 0 && num_2 % 2 == 0) {
			return sum;
		}
		else if (num_1 % 2 == 1 && num_2 % 2 == 1) {
			return sum + 2;
		}

		return -1;
	}
};

#endif // __leet_code_1247_h__