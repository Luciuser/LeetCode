/*
 * @Author: Bingyang Jin
 * @Date: 2024-01-16 13:41:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2719.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-01-14 14:40:11
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, out of TIME
 */

 /*
 * @EditTime: 2024-01-14 10:49:31
 * @Editor: Bingyang Jin
 * @Description: create DFS_METHOD, TIME 12ms, 30.08%, MEMORY 11.6MB and 82.9%
 */

#ifndef __leet_code_2719__
#define __leet_code_2719__

#include<iostream>
#include<string>
#include<vector>

//#define DFS_METHOD

#ifdef DFS_METHOD
class Solution {
public:
	int count(std::string num1, std::string num2, int min_sum, int max_sum) {
		// �ݹ���ã����Կ��᲻�ᳬʱ��������Ӧ�ò���

		int m = num1.size();
		int n = num2.size();
		int temp = n - m;
		std::string zeros(temp, '0');
		num1 += zeros;

		return dfs(num1, num2, min_sum, max_sum);
	}

private:
	long long dfs(std::string num1, std::string num2, int min_sum, int max_sum) {
		// �ݹ���ã����Կ��᲻�ᳬʱ��������Ӧ�ò���

		int n = num1.size();

		// ��֦�жϣ�
		if (max_sum <= 0) {
			return 0;
		}
		if (1 < n && n <= 10) {
			int first_number = num2[0] - '0';
			int sum_max_temp = first_number + 9 * (n - 1);
			if (sum_max_temp <= min_sum) {
				return sum_max_temp == min_sum ? 1 : 0;
			}
		}

		// �ݹ������ж�
		if (n == 1) {
			int num1_int = std::stoi(num1);
			int num2_int = std::stoi(num2);

			int begin = num1_int > min_sum ? num1_int : min_sum;
			int end = num2_int < max_sum ? num2_int : max_sum;
			if (end < begin) {
				return 0;
			}
			return end - begin + 1;
		}

		// ���еݹ�
		int begin = num1[0] - '0';
		int end = num2[0] - '0';
		long long sum = 0;

		std::string str_begin_num1 = num1.substr(1, n - 1);
		std::string str_begin_num2(n - 1, '9');
		std::string str_end_num1(n - 1, '0');
		std::string str_end_num2 = num2.substr(1, n - 1);
		// ����λȡbeginʱ
		sum += dfs(str_begin_num1, str_begin_num2, min_sum - begin, max_sum - begin);
		if (sum > MOD) {
			sum = sum % MOD;
		}
		// ����λȡ�м�ʱ
		for (int i = begin + 1; i <= end - 1; i++) {
			sum += dfs(str_end_num1, str_begin_num2, min_sum - i, max_sum - i);
			if (sum > MOD) {
				sum = sum % MOD;
			}
		}
		// ����λȡendʱ
		sum += dfs(str_end_num1, str_end_num2, min_sum - end, max_sum - end);
		if (sum > MOD) {
			sum = sum % MOD;
		}

		return sum;
	}

	long long MOD = 1e9 + 7;
};
#endif // DFS_METHOD

class Solution {
public:
	int count(std::string num1, std::string num2, int min_sum, int max_sum) {
		// �ݹ���ã����Կ��᲻�ᳬʱ��������Ӧ�ò���

		int m = num1.size();
		int n = num2.size();
		int temp = n - m;
		std::string zeros(temp, '0');
		num1 = zeros+num1;

		record = std::vector<std::vector<std::vector<long long>>>(24, std::vector<std::vector<long long>>(24 * 9, std::vector<long long>(24 * 9, -1)));

		return dfs(num1, num2, min_sum, max_sum);
	}

private:
	long long dfs(std::string num1, std::string num2, int min_sum, int max_sum) {
		// �ݹ���ã����Կ��᲻�ᳬʱ��������Ӧ�ò���

		int n = num1.size();

		// ��֦�жϣ�
		if (max_sum < 0) {
			return 0;
		}
		//if (1 < n && n <= 10) {
		//	int first_number = num2[0] - '0';
		//	int sum_max_temp = first_number + 9 * (n - 1);
		//	if (sum_max_temp < min_sum) {
		//		return 0;
		//	}
		//}

		// �ݹ������ж�
		if (n == 1) {
			int num1_int = std::stoi(num1);
			int num2_int = std::stoi(num2);

			int begin = num1_int > min_sum ? num1_int : min_sum;
			int end = num2_int < max_sum ? num2_int : max_sum;
			if (end < begin) {
				return 0;
			}
			return end - begin + 1;
		}

		// ���еݹ�
		int begin = num1[0] - '0';
		int end = num2[0] - '0';
		long long sum = 0;

		std::string str_begin_num1 = num1.substr(1, n - 1);
		std::string str_begin_num2(n - 1, '9');
		std::string str_end_num1(n - 1, '0');
		std::string str_end_num2 = num2.substr(1, n - 1);
		// ����λȡbeginʱ
		sum += dfs(str_begin_num1, str_begin_num2, min_sum - begin, max_sum - begin);
		if (sum > MOD) {
			sum = sum % MOD;
		}
		// ����λȡ�м�ʱ
		for (int i = begin + 1; i < end; i++) {
			sum += calculate_standard(n - 1, min_sum - i, max_sum - i);
			if (sum > MOD) {
				sum = sum % MOD;
			}
		}
		// ����λȡendʱ
		if (begin != end) {
			sum += dfs(str_end_num1, str_end_num2, min_sum - end, max_sum - end);
		}
		if (sum > MOD) {
			sum = sum % MOD;
		}

		return sum;
	}

	// ����nλ���֣���0����0������9����9�����У�����λ����[min, max]֮���ܹ����ٸ���
	long long calculate_standard(int n, int min, int max) {
		int a = min;
		int b = max;
		// ��һ��
		if (a < 0) {
			a = 0;
		}
		if (b > n * 9) {
			b = n * 9;
		}

		// ��һ��������������� 0
		if (n * 9 < a || b < 0) {
			return 0;
		}

		if (a > b) {
			std::cout << "Error!" << std::endl;
			return 0;
		}

		// �����ʱ��֤ 0<=a<=b<=n*9
		if (record[n][a][b] != -1) {
			return record[n][a][b];
		}

		// �ݹ������ж�
		if (n == 1) {
			long long sum = b - a + 1;
			record[n][a][b] = sum;
			return sum;
		}

		// �������������ֱ�Ӽ���
		if (a <= 1 && n * 9 - 1 <= b) {
			long long sum = 1;
			for (int i = 0; i < n; i++) {
				sum *= 10;
				if (sum > MOD) {
					sum = sum % MOD;
				}
			}
			if (a == 1) {
				sum--;
			}
			if (n * 9 - 1 == b) {
				sum--;
			}
			if (sum < 0) {
				sum += MOD;
			}

			record[n][a][b] = sum;
			return sum;
		}

		// �������������������
		long long sum = 0;
		for (int i = 0; i <= 9; i++) {
			sum += calculate_standard(n - 1, a - i, b - i);
			if (sum > MOD) {
				sum = sum % MOD;
			}
		}
		record[n][a][b] = sum;
		return sum;
	}

	long long MOD = 1e9 + 7;
	std::vector<std::vector<std::vector<long long>>> record;
};

#endif // __leet_code_2719__