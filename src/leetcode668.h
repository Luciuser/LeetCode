#ifndef __leet_code_668__
#define __leet_code_668__

#include<iostream>
#include<algorithm>
#include<vector>

//#define VIOLENT_TRAVERSAL_METHODS // �������㷨���ᳬʱ
#define BINARY_SEARCH_METHODS // ���ֲ��ҷ�

#ifdef VIOLENT_TRAVERSAL_METHODS
class Solution {
public:
	int findKthNumber(int m, int n, int k) {

		int result;

		bool isFoward;
		if (k <= m || k <= n) {
			isFoward = true;
		}
		else
		{
			isFoward = false;
		}

		if (isFoward) {
			// �������
			for (int i = 1; i < k + 1; i++) {
				int sum = 0; // ��ʾ�ó˷�����С�ڵ����� i �������м���
				for (int j = 0; j < m; j++) {
					int temp = i / (j + 1);
					if (temp > n) {
						temp = n;
					}
					sum += temp;
				}
				if (sum <= k - 1) {
					continue;
				}
				else {
					result = i;
					break;
				}
			}
		}
		else {
			// �������
			for (int i = 1; i < k + 1; i++) {
				int sum = 0; // ��ʾ�ó˷���������� i �������м���
				for (int j = m; j > 0; j--) {
					int temp = n - i / j;
					if (temp < 0) {
						temp = 0;
					}
					sum += temp;
				}
				if (n * m - sum <= k - 1) {
					continue;
				}
				else {
					result = i;
					break;
				}
			}
		}

		return result;

	}
};
#endif // VIOLENT_TRAVERSAL_METHODS

#ifdef BINARY_SEARCH_METHODS
class Solution {
public:

	int findTheNumberEqualLessThanK(int m, int n, int k) {
		int result = 0;
		for (int i = 1; i <= m; i++) {
			if (i > k) {
				break;
			}
			int temp = k / i;
			if (temp > n) {
				temp = n;
			}
			result += temp;
		}
		return result;
	}

	int findKthNumber(int m, int n, int k) {

		int result;
		int left = 0;
		int right = m * n;
		while (true) {
			if (right - left == 1) {
				result = right;
				break;
			}
			result = (left + right) / 2;
			int resultTemp = result - 1;
			int testResult = findTheNumberEqualLessThanK(m, n, result);
			int testResultTemp = findTheNumberEqualLessThanK(m, n, resultTemp);

			if (testResult < testResultTemp) {
				std::cout << "WRONG" << std::endl;
				return -1;
			}

			if (testResultTemp < k && testResult >= k) {
				break;
			}

			if (testResult < k) {
				left = result;
			}

			if (testResultTemp >= k) {
				right = resultTemp;
			}

		}

		return result;

	}
};
#endif // BINARY_SEARCH_METHODS



#endif // !__leet_code_668__