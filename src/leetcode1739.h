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
 * @Description: create GREEDY_METHOD，TIME 40ms, 8.08%, MEMORY 6.4MB and 11.11%
 */

 /*
 * @EditTime: 2022-12-25 10:52:21
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD，TIME 0ms, 100.00%, MEMORY 6.1MB and 13.13%
 */

#ifndef __leet_code_1739__
#define __leet_code_1739__

#include<iostream>
#include<vector>

//#define GREEDY_METHOD // 贪心法，TIME 40ms, 8.08%, MEMORY 6.4MB and 11.11%
#define MATH_METHOD // 数学法，O(1)，TIME 0ms, 100.00%, MEMORY 6.1MB and 13.13%

#ifdef GREEDY_METHOD
class Solution {
public:
	int minimumBoxes(int n) {
		// 首先计算出一个堆叠的最优情况，即从上到下，第1层1个，第2层3个，第i层(i+2)*i/2个，
		int i = 1; // 当前总层数
		int temp = 1; // 最下层的方块数
		long long sum = 1; // 总方块数
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
		// 从第 i 层开始，将剩下的方块放上去，并计算最下层有多少个
		std::vector<int>isFirst(i + 1, 0); // 每一层是否已经增加了一个
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