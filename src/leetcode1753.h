/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-21 00:21:36
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1753.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-21 00:36:46
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 16ms, 30.39%, MEMORY 5.7MB and 99.02%
 */

#ifndef __leet_code_1753__
#define __leet_code_1753__

class Solution {
public:
	int maximumScore(int a, int b, int c) {

		int result = 0;
		while (true) {
			sortABC(&a, &b, &c);
			if (b == 0 && c == 0) {
				break;
			}
			result++;
			a--;
			b--;
		}

		return result;
	}

private:
	void sortABC(int*a, int *b, int *c) {
		if ((*a) < (*b)) {
			int temp = (*a);
			(*a) = (*b);
			(*b) = temp;
		}
		if ((*a) < (*c)) {
			int temp = (*a);
			(*a) = (*c);
			(*c) = temp;
		}
		if ((*b) < (*c)) {
			int temp = (*b);
			(*b) = (*c);
			(*c) = temp;
		}
		return;
	}
};

#endif // __leet_code_1753__