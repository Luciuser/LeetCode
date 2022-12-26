/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-25 09:49:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1739.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-25 10:17:24
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD��TIME 40ms, 8.08%, MEMORY 6.4MB and 11.11%
 */

 /*
 * @EditTime: 2022-12-25 10:52:21
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD��TIME 0ms, 100.00%, MEMORY 6.1MB and 13.13%
 */

#ifndef __leet_code_1739__
#define __leet_code_1739__

#include<iostream>
#include<vector>

//#define GREEDY_METHOD // ̰�ķ���TIME 40ms, 8.08%, MEMORY 6.4MB and 11.11%
#define MATH_METHOD // ��ѧ����O(1)��TIME 0ms, 100.00%, MEMORY 6.1MB and 13.13%

#ifdef GREEDY_METHOD
class Solution {
public:
	int minimumBoxes(int n) {
		// ���ȼ����һ���ѵ�����������������ϵ��£���1��1������2��3������i��(i+2)*i/2����
		int i = 1; // ��ǰ�ܲ���
		int temp = 1; // ���²�ķ�����
		long long sum = 1; // �ܷ�����
		while (sum < n) {
			i++;
			temp += i;
			sum += temp;
		}
		if (sum == n) {
			return temp;
		}

		sum -= temp;
		temp -= i;
		i--;
		// �ӵ� i �㿪ʼ����ʣ�µķ������ȥ�����������²��ж��ٸ�
		std::vector<int>isFirst(i + 1, 0); // ÿһ���Ƿ��Ѿ�������һ��
		while (sum < n) {
			temp++;
			sum = addOneBlock(isFirst, 0, sum);
		}

		return temp;
	}
private:
	int addOneBlock(std::vector<int> &isFirst, int i, int sum) {
		int result = sum + 1;
		if (isFirst[i] == 0) {
			isFirst[i] = 1;
		}
		else {
			result = addOneBlock(isFirst, i + 1, result);
		}
		return result;
	}
};
#endif // GREEDY_METHOD

#ifdef MATH_METHOD
class Solution {
public:
	int g(int x) {
		return (long long)x * (x + 1) * (x + 2) / 6;
	}

	int minimumBoxes(int n) {
		int i = pow(6.0 * n, 1.0 / 3);
		if (g(i) < n) {
			i++;
		}
		n -= g(i - 1);
		int j = ceil(1.0 * (sqrt((long long)8 * n + 1) - 1) / 2);
		return (i - 1) * i / 2 + j;
	}
};
#endif // MATH_METHOD


#endif // __leet_code_1739__