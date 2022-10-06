/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-06 10:14:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode927.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-06 11:26:13
 * @Editor: Bingyang Jin
 * @Description: create VALID_END_METHOD, TIME 40ms, 40.97%, MEMORY 37.9MB and 75.35%
 */

#ifndef __leet_code_927__
#define __leet_code_927__

#include<iostream>
#include<vector>

class Solution {
public:

	bool sameString(const std::vector<int>&arr, const int end_a, const int end_b, const int end_c) {
		int index = 0;
		int a_length = end_a + 1;
		int b_length = end_b - end_a;
		int c_length = end_c - end_b;

		int a = 0, b = 0, c = 0;

		while (true) {
			if (index + 1 > a_length && index + 1 > b_length && index + 1 > c_length) {
				break;
			}

			if (index + 1 > a_length) {
				a = 0;
			}
			else {
				a = arr[end_a - index];
			}

			if (index + 1 > b_length) {
				b = 0;
			}
			else {
				b = arr[end_b - index];
			}

			if (index + 1 > c_length) {
				c = 0;
			}
			else {
				c = arr[end_c - index];
			}

			index++;

			if (a == b && b == c) {
				continue;
			}
			else {
				return false;
			}
		}

		return true;
	}

	void turnRight(const std::vector<int>& arr, int &valid_b, int &valid_c, int & end_b, int &end_c) {
		// 重新计算 valid_b
		if (valid_b == 1 && arr[end_b] == 0) {
			// 特殊情况，第二段均为0，此时右移 end_b 不改变 valid_b
		}
		else {
			valid_b++;
		}

		// 重新计算 valid_c
		end_b++;
		if (arr[end_b] == 0) {
			// 特殊情况，当 end_b 后一位为 0 时，valid_c 不变
		}
		else {
			// 当 end_b 后一位为 1 时，遍历重新计算 valid_c
			valid_c--;
			int tempZero = end_b + 1;
			while (true) {
				if (tempZero > end_c) {
					// 遍历到最后依然没有出现新的 1
					valid_c = 1;
					break;
				}
				if (arr[tempZero] == 1) {
					// 出现了新的1
					break;
				}
				else {
					valid_c--;
				}
				tempZero++;
			}
		}
	}

	std::vector<int> threeEqualParts(std::vector<int>& arr) {

		// 若要三段相同，则三段的有效数字一定要相同
		// 当 end_a 右移一位时，valid_a 不变或者增加一位，valid_b 不变或者减少一位。
		//			此时需要尝试右移 end_b 来使得 valid_a 和 valid_b 保持不变
		//					当 valid_a == valid_b 时，去判断 valid_c 的情况，进而决定是否进行字符串相等的判断
		//					当 valid_a > valid_b 时，右移 end_b，增加 valid_b
		//					当 valid_a < valid_b 时，右移 end_b，valid_b 会越来越大，此时回退，开始尝试右移 end_a
		// 当 valid_a > valid_b && valid_a > valid_c 时，已经无法相同，返回失败结果

		// 三段的有效数字，默认均为1
		int valid_a = 1;
		int valid_b = 1;
		int valid_c = 1;
		// 计算第三段的有效数字
		int temp = -1;
		for (int i = 2; i < arr.size(); i++) {
			if (arr[i] == 1) {
				temp = i;
				break;
			}
		}
		if (temp != -1) {
			valid_c = arr.size() - temp;
		}

		// 三段的结束位置
		int end_a = 0;
		int end_b = 1;
		int end_c = arr.size() - 1;

		while (true) {
			std::cout << end_a << " " << end_b << " " << end_c << std::endl;
			if (valid_a > valid_b && valid_a > valid_c) {
				return std::vector<int>(2, -1);
			}
			if (end_b == arr.size() - 1) {
				return std::vector<int>(2, -1);
			}

			if (valid_a == valid_b) {
				if (valid_b == valid_c) {
					// 进行字符串判断
					if (sameString(arr, end_a, end_b, end_c)) {
						std::vector<int> result = { end_a, end_b + 1 };
						return result;
					}
					else {
						turnRight(arr, valid_a, valid_b, end_a, end_b);
					}
				}
				else if(valid_b < valid_c){
					// 此时第一段和第二段有可能相同，但一定与第三段不相同，则对 end_b 尝试右移
					turnRight(arr, valid_b, valid_c, end_b, end_c);
				}
				else {
					// 此时右移 end_b，valid_c 只会变得更小，无法满足 valid_b == valid_c，因此 end_a 尝试右移
					turnRight(arr, valid_a, valid_b, end_a, end_b);
				}
			}
			else if (valid_a < valid_b) {
				// end_a 尝试右移
				turnRight(arr, valid_a, valid_b, end_a, end_b);
			}
			else {
				// end_b 尝试右移
				turnRight(arr, valid_b, valid_c, end_b, end_c);
			}

		}

		return std::vector<int>(2, -1);
	}
};

#endif // __leet_code_927__