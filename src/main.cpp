#include "leetcodetest.h"
#include "acmtest.h"

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
//typedef long long ll;
int main() {

	//int n = 10;
	//int MOD = 1e9 + 7;

	//ll zero = 25;
	//ll e_last = 1;
	//ll e_last_num = 1;
	//ll e_not_last = 0;
	//ll e_not_last_num = 0;

	//for (int i = 2; i <= 10; i++) {
	//	ll next_zero = zero * 24 % MOD;
	//	ll next_e_last = (zero + e_not_last) % MOD;
	//	ll next_e_last_num = (zero + e_not_last+ e_not_last_num) % MOD;
	//	ll next_e_not_last = (e_not_last * 24 % MOD + e_last * 25 % MOD)% MOD;
	//	ll next_e_not_lsat_num = (e_not_last_num * 24 % MOD + e_last_num * 25 % MOD) % MOD;

	//	zero = next_zero;
	//	e_last = next_e_last;
	//	e_last_num = next_e_last_num;
	//	e_not_last = next_e_not_last;
	//	e_not_last_num = next_e_not_lsat_num;

	//	std::cout << i << " " << e_last_num + e_not_last_num << std::endl;
	//}



	//std::cout << std::numeric_limits<int>::max() << std::endl;

	//std::string s2 = "abcda";
	//std::string s1 = "dbcdd";
	//int n = 5;

	//std::unordered_map<int, std::unordered_map<int, std::pair<int, std::vector<std::queue<int>>>>> characterMap; // a-f 对 a-f 的映射次数，每个都需要处理

	//for (int i = 0; i < n; i++) {
	//	if (s1[i] != s2[i]) {
	//		//characterArray[s1[i] - 'a'][s2[i] - 'a']++;
	//		characterMap[s1[i] - 'a'][s2[i] - 'a'].first++;
	//	}
	//}

	//srand((unsigned)time(NULL));

	//int iter_num = 100000;

	//double sum = 0;
	//for (int i = 0; i < iter_num; i++) {
	//	double x = rand() / double(RAND_MAX);
	//	std::cout << "x = " << x << " ; ";
	//	double temp = 1.0 / (exp(x) + x);
	//	sum += temp;
	//	std::cout << " result = " << temp << std::endl;
	//}
	//sum /= iter_num;
	//std::cout << "The average answer is " << sum << std::endl;

	ACMTest acmTest;
	acmTest.cin_cout_test();

	leetcodeTest();


	return 0;
}