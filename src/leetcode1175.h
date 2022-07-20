#ifndef __leet_code_1175__
#define __leet_code_1175__

#include<iostream>

class Solution {
public:

	bool isPrime(int n) {
		if (n == 1) {
			return false;
		}
		if (n == 2) {
			return true;
		}
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return false;
			}
		}
		return true;
	}

	int numPrimeArrangements(int n) {
		int a = n;
		int b = 0;
		for (int i = 1; i <= n; i++) {
			if (isPrime(i)) {
				a--;
				b++;
			}
		}

		long long temp = 1;
		int reulst = 0;
		for (int i = 1; i <= a; i++) {
			temp *= i;
			if (temp > 10000000007) {
				temp = temp % 10000000007;
			}
		}
		for (int i = 1; i <= b; i++) {
			temp *= i;
			if (temp > 10000000007) {
				temp = temp % 10000000007;
			}
		}
		return temp;
	}
};

#endif // __leet_code_1175__