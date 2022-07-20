#ifndef __leet_code_326__
#define __leet_code_326__

#include<iostream>
#include<algorithm>
#include<vector>

//#define LOOP_METHODS
#define LOG_METHODS

#ifdef LOOP_METHODS
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n == 1) {
			return true;
		}
		if (n <= 2) {
			return false;
		}

		while (n >= 3) {
			if (n % 3 != 0) {
				return false;
			}
			n = n / 3;
		}

		if (n == 2) {
			return false;
		}

		return true;
	}
};
#endif // LOOP_METHODS

#ifdef LOG_METHODS
class Solution {
public:

	bool nearlyEqual(double x, int y) {
		if (abs(x - y) < 1e-10) {
			return true;
		}
		
		return false;
	}

	bool isPowerOfThree(int n) {
		if (n == 1) {
			return true;
		}
		if (n <= 2) {
			return false;
		}

		double x = log(n) / log(3);
		int x_int = (int)x;

		// 考虑double的精度误差产生的影响
		int x_int2 = x_int - 1;
		int x_int3 = x_int + 1;

		if (nearlyEqual(x, x_int) ||
			nearlyEqual(x, x_int2) ||
			nearlyEqual(x, x_int3)
			) {
			return true;
		}

		return false;
	}
};
#endif // LOOP_METHODS

#endif // !__leet_code_326__