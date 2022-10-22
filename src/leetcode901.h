/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-21 09:50:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode901.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-21 10:02:23
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 204ms, 42.50%, MEMORY 83MB and 34.08%
 */

#ifndef __leet_code_901__
#define __leet_code_901__

#include<iostream>
#include<vector>
#include<unordered_map>

class StockSpanner {
public:
	StockSpanner() {

	}

	int next(int price) {
		if (value.size() == 0) {
			value.push_back(price);
			days[value.size() - 1] = 1;
			return 1;
		}

		int sum = 1;
		for (int i = value.size() - 1; i >= 0; i--) {
			if (price >= value[i]) {
				sum += days[i];
			}
			else {
				break;
			}
		}

		if (sum > 1) {
			value[value.size() - 1] = price;
			days[value.size() - 1]++;
		}
		else {
			value.push_back(price);
			days[value.size() - 1] = 1;
		}

		return sum;
	}

private:
	std::vector<int> value;
	std::unordered_map<int, int> days;
};


#endif // __leet_code_901__