/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-14 00:54:23
 * @FilePath: /EMeshGen/src/eTetrahedralize.h
 */
 /*
 * @EditTime: 2022-07-14 00:56:44
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD
 */

#ifndef  __sword_offer_II_041__
#define  __sword_offer_II_041__

#include<iostream>
#include<queue>

class MovingAverage {
public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		windowSize = size;
		sum = 0;
		while (nums.empty() == false) {
			nums.pop();
		}
	}

	double next(int val) {
		if (nums.size() < windowSize) {
			sum += val;
			nums.push(val);
		}
		else {
			sum -= nums.front();
			sum += val;
			nums.pop();
			nums.push(val);
		}
		return sum * 1.0 / nums.size();
	}

private:
	int windowSize;
	int sum;
	std::queue<int> nums;
};


#endif //  __sword_offer_II_041__