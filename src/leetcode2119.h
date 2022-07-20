#ifndef __leet_code_2119__
#define __leet_code_2119__

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

//#define NORMAL_METHOD // ������ĿҪ�������������д��һ��int�ĵ��ú���
#define QUACKLY_METHOD // ���ٽ��˼·����0�⣬���һ�����ĸ�λ��Ϊ0�����䵹�����κ����

#ifdef  NORMAL_METHOD
class Solution {
public:

	// ����һ����num�������������ֵ��ú����
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