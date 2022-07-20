#ifndef __leet_code_875__
#define __leet_code_875__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:

	bool canEat(std::vector<int>&piles, int h, int speed) {
		int sum = 0;
		for (int i = 0; i < piles.size(); i++) {
			if (piles[i] < speed) {
				sum = sum + piles.size() - i;
				break;
			}
			if (piles[i] % speed == 0)	{
				sum = sum + piles[i] / speed;
			}
			else {
				sum = sum + piles[i] / speed + 1;
			}
		}
		//sum = sum + piles.size();
		return sum <= h;
	}

	int minEatingSpeed(std::vector<int>& piles, int h) {
		std::vector<int> temp = piles;
		
		std::sort(temp.begin(), temp.end(), [=](int a, int b) {return a > b; }); // ≈≈–Ú

		int left = 1;
		int right = temp[0];
		int mid = (left + right) / 2;

		while (true) {
			if (right - 1 == left) {
				if (canEat(temp, h, left)) {
					return left;
				}
				else {
					return right;
				}
			}
			if (canEat(temp, h, mid) == true) {
				right = mid;
				mid = (left + right) / 2;
			}
			else {
				left = mid;
				mid = (left + right) / 2;
			}
		}

		return temp[0];
	}
};

#endif // __leet_code_875__