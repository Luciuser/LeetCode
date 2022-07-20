#ifndef __leet_code_2119__
#define __leet_code_2119__

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

//#define NORMAL_METHOD // 按照题目要求的正常做法，写出一个int的倒置函数
#define QUACKLY_METHOD // 快速解决思路：除0外，如果一个数的个位数为0，则其倒置两次后不相等

#ifdef  NORMAL_METHOD
class Solution {
public:

	// 给定一个数num，将其所有数字倒置后输出
	int reversal(int num) {
		int sum = 0;

		while (num >= 10) {
			int temp = num % 10;
			sum = sum * 10 + temp;
			num = num / 10;
		}
		sum = sum * 10 + num;

		return sum;
	}

	bool isSameAfterReversals(int num) {
		if (reversal(reversal(num)) == num) {
			return true;
		}
		else {
			return false;
		}
	}
};
#endif // NORMAL_METHOD

#ifdef QUACKLY_METHOD
class Solution {
public:

	bool isSameAfterReversals(int num) {
		if (num == 0) {
			return true;
		}

		if (num % 10 == 0) {
			return false;
		}
		else {
			return true;
		}
	}
};
#endif // QUACKLY_METHOD

#endif // !__leet_code_2119__