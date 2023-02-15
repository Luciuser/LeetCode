/*
 * @Author: Bingyang Jin
 * @Date: 2023-02-15 10:29:05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1250.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-14 16:13:31
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD, TIME 48ms, 26.87%, MEMORY 28.4MB and 79.10%
 */

#ifndef __leet_code_1250_h__
#define __leet_code_1250_h__

#include<iostream>
#include<vector>

class Solution {
public:
	bool isGoodArray(std::vector<int>& nums) {
		// 设取出的数为 a1, a2, a3, …… , an，对应相乘的整数为 k1, k2, k3, …… , kn
		// 按题意，若为好数组，则满足：k1*a1 + k2*a2 + k3*a3 + …… + kn*an = 1，其中 ki 为整数
		// 设 a1, a2, a3, …… , an 的最大公因数为 a0，则有：a0*x1 = a1；a0*x2 = a2；……，其中 xi 为整数
		// 因此上式可写为：k1*x1*a0 + k2*x2*a0 + k3*x3*a0 + …… + kn*xn*a0 = 1
		// 推到为：k1*x1 + k2*x2 + k3*x3 + …… + kn*xn = 1 / a0
		// 因为等式左侧均为整数乘积和，故为整数，则 a0 = 1 恒成立
		// 综上，当 nums 全组数的最大公约数为 1 时，nums 为好数组，否则不为好数组

		int a = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int b = nums[i];
			if (a < b) {
				int temp = a;
				a = b;
				b = temp;
			}
			a = gcd(a, b);
			if (a == 1) {
				return true;
			}
		}
		if (a == 1) {
			return true;
		}
		return false;
	}

private:
	int gcd(int a, int b) {
		if (a%b == 0) {
			return b;
		}
		return gcd(b, a%b);
	}
};

#endif // __leet_code_1250_h__