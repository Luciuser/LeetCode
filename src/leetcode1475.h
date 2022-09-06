/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-06 13:08:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1475.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-06 13:18:04
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD£¬TIME 0ms, 100.00%, MEMORY 9.6MB and 52.89%
 */


#ifndef __leet_code_1475__
#define __leet_code_1475__

#include<iostream>
#include<vector>

class Solution {
public:
	std::vector<int> finalPrices(std::vector<int>& prices) {
		for (int i = 0; i < prices.size(); i++) {
			for (int j = i + 1; j < prices.size(); j++) {
				if (prices[i] >= prices[j]) {
					prices[i] -= prices[j];
					break;
				}
			}
		}
		return prices;
	}
};

#endif // __leet_code_1475__