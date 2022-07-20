#ifndef __leet_code_829__
#define __leet_code_829__

#include<iostream>
#include<math.h>

class Solution {
public:

	// 1 +……+n = (1+n)*n/2 = m ====> 2m = (1+n) * n
	// k = 1 ~ sqrt(2 * m) + 1
	// 

	//int accumulateFromA0(int a0, int n) {
	//	return (a0 + a0 + n - 1) * n / 2;
	//}

	//int accumulateFromA1(int a1, int n) {
	//	return (a1 + a1 - n + 1) * n / 2;
	//}

	//int accumulateFromAverage(double average, int n) {
	//	int temp =(int) (average + 0.5);
	//}

	int consecutiveNumbersSum(int n) {
		int result = 0;
		int temp = sqrt(2) * sqrt(n) + 1;
		for (int i = 1; i <= sqrt(2) * sqrt(n) + 1; i++) {
			// i 表示由 i 个数组成的连续数列

			if (i % 2 == 1) {
				// 奇数个数的连续数列，想要能够组成，则需满足：
				// 1. n 能够整除 i
				// 2. 最小的数 a0 >= 1
				if (n % i == 0) {
					// 满足1
					int average = n / i; // 最中间的数
					if (average - ((i - 1) / 2) >= 1) {
						// 满足 2
						result++;
					}
				}
			}
			else {
				// 偶数个数的连续数列，想要能够组成，则需满足：
				// 1. 2n 能够整除 i，n 不能整除 i
				// 2. 最小的数 a0 >= 1
				if ((2*n) % i == 0 && n % i != 0) {
					// 满足1
					int average = (int)(n / i); // 平均数靠左一位
					if (average - (i / 2 - 1) >= 1) {
						// 满足 2
						result++;
					}
				}
			}

		}
		return result;
	}
};

#endif // __leet_code_829__