#ifndef __leet_code_1399__
#define __leet_code_1399__

#include<iostream>

class Solution {
public:

	int getSumOfNumber(int n) {
		int t = n;
		int sum = 0;
		while (t >= 10) {
			sum += t % 10;
			t = t / 10;
		}
		sum += t;
		return sum;
	}

	int countLargestGroup(int n) {

		int map[40];
		for (int i = 0; i < 40; i++) {
			map[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			map[getSumOfNumber(i)]++;
		}

		int sum = 0;
		int max = 0;
		for (int i = 0; i < 40; i++) {
			if (map[i] > max) {
				max = map[i];
				sum = 0;
			}
			if (map[i] == max) {
				sum++;
			}
		}

		return sum;
	}
};

#endif // __leet_code_1399__