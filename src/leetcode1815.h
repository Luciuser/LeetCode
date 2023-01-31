/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-21 10:26:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1815.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-21 11:50:07
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 748ms, 11.52%, MEMORY 313.1MB and 10.99%
 */

#ifndef __leet_code_1815_h__
#define __leet_code_1815_h__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxHappyGroups(int batchSize, std::vector<int>& groups) {
		// 进行化简
		std::vector<int> frequence(batchSize, 0); // 余数为 index 的组数
		for (int i = 0; i < groups.size(); i++) {
			groups[i] = groups[i] % batchSize;
			frequence[groups[i]]++;
		}

		int unhappy = 0;
		frequence[0] = 0;

		for (int index = 2; index <= batchSize; index++) {
			// 所有组都用完后，直接跳出
			bool is_frequence_empty = true;
			for (int i = 1; i < frequence.size(); i++) {
				if (frequence[i] != 0) {
					is_frequence_empty = false;
					break;
				}
			}
			if (is_frequence_empty == true) {
				break;
			}

			// index 个组合并，判断能否开心一组
			std::vector<int> current(index - 1); // 当前选择的组情况
			int current_sum = 0;
			int frequence_index = 0;
			int frequence_use = 0;
			for (int i = 0; i < current.size(); i++) {
				while(frequence[frequence_index]==frequence_use)
			}

			while (true) {
				if ( target < 0 ) {
					break;
				}


			}

		}

		return groups.size() - unhappy;
	}
};

#endif // __leet_code_1815_h__