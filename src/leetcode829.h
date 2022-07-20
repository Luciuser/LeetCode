#ifndef __leet_code_829__
#define __leet_code_829__

#include<iostream>
#include<math.h>

class Solution {
public:

	// 1 +����+n = (1+n)*n/2 = m ====> 2m = (1+n) * n
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
			// i ��ʾ�� i ������ɵ���������

			if (i % 2 == 1) {
				// �����������������У���Ҫ�ܹ���ɣ��������㣺
				// 1. n �ܹ����� i
				// 2. ��С���� a0 >= 1
				if (n % i == 0) {
					// ����1
					int average = n / i; // ���м����
					if (average - ((i - 1) / 2) >= 1) {
						// ���� 2
						result++;
					}
				}
			}
			else {
				// ż���������������У���Ҫ�ܹ���ɣ��������㣺
				// 1. 2n �ܹ����� i��n �������� i
				// 2. ��С���� a0 >= 1
				if ((2*n) % i == 0 && n % i != 0) {
					// ����1
					int average = (int)(n / i); // ƽ��������һλ
					if (average - (i / 2 - 1) >= 1) {
						// ���� 2
						result++;
					}
				}
			}

		}
		return result;
	}
};

#endif // __leet_code_829__