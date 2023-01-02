/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-02 11:16:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1801.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-01-01 11:35:08
 * @Editor: Bingyang Jin
 * @Description: create MAP_METHOD, TIME 196ms, 74.23%, MEMORY 62.8MB and 20.62%
 */

#ifndef __leet_code_1801__
#define __leet_code_1801__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
	int getNumberOfBacklogOrders(std::vector<std::vector<int>>& orders) {
		std::map<int, long long>sell;
		std::map<int, long long, std::greater<int>> buy;

		std::vector<int> del;
		for (int i = 0; i < orders.size(); i++) {
			del.clear();
			if (orders[i][2] == 0) {
				// 当前为采购订单，搜寻销售订单
				int price = orders[i][0];
				int remain = orders[i][1];
				for (auto iter = sell.begin(); iter != sell.end(); iter++) {
					if ((*iter).first > price) {
						break;
					}

					if (remain <= (*iter).second) {
						(*iter).second -= remain;
						remain = 0;
						break;
					}

					remain -= (*iter).second;
					(*iter).second = 0;
					del.push_back((*iter).first);
				}

				for (int j = 0; j < del.size(); j++) {
					sell.erase(del[j]);
				}
				if (remain != 0) {
					buy[price] += remain;
				}

			}
			else if (orders[i][2] == 1){
				// 当前为销售订单，搜寻采购订单
				int price = orders[i][0];
				int remain = orders[i][1];
				for (auto iter = buy.begin(); iter != buy.end(); iter++) {
					if ((*iter).first < price) {
						break;
					}

					if (remain <= (*iter).second) {
						(*iter).second -= remain;
						remain = 0;
						break;
					}

					remain -= (*iter).second;
					(*iter).second = 0;
					del.push_back((*iter).first);
				}

				for (int j = 0; j < del.size(); j++) {
					buy.erase(del[j]);
				}
				if (remain != 0) {
					sell[price] += remain;
				}
			}
		}

		// 计算积压的订单数
		long long result = 0;
		int MOD = 1e9 + 7;
		for (auto iter = buy.begin(); iter != buy.end(); iter++) {
			result += (*iter).second;
			if (result > MOD) {
				result = result % MOD;
			}
		}
		for (auto iter = sell.begin(); iter != sell.end(); iter++) {
			result += (*iter).second;
			if (result > MOD) {
				result = result % MOD;
			}
		}

		return result;
	}
};

#endif // __leet_code_1801__