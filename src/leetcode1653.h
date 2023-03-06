/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-06 12:05:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1653.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-05 12:29:20
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGTAMMING_METHOD, TIME 68ms, 80.39%, MEMORY 21.5MB and 81.37%
 */

#ifndef __leet_code_1653_h__ 
#define __leet_code_1653_h__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumDeletions(std::string s) {
		// 动态规划
		// 设 dp_a[i] 表示前 i 个数为平衡，且上一个字符为 a 时最小的删除次数；
		// 设 dp_b[i] 表示前 i 个数为平衡，且上一个字符为 b 时最小的删除次数；
		// 因此对于第 i 个字符而言
		// 考虑 dp_a，由于 dp_a 只能跟在上一个字符为 a 的情况，因此此时有递推公式为：
		//			dp_a[i] = dp_a[i-1],  if s[i] == 'a'
		//			dp_a[i] = dp_a[i-1] + 1,  if s[i] == 'b'	// 删除第 i 个数
		// 考虑 dp_b，dp_b 可以由上述两种情况转移而来，因此此时有地推公式为：
		//			dp_b[i] = min(dp_a[i-1], dp_b[i-1] + 1),  if s[i] == 'a'
		//			dp_b[i] = min(dp_a[i-1], dp_b[i-1]),  if s[i] == 'b'

		int dp_a = 0;
		int dp_b = 0;
		// 初始化
		if (s[0] == 'a') {
			dp_b = 1;
		}
		else if (s[0] == 'b') {
			dp_a = 1;
		}
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == 'a') {
				dp_b = dp_a < dp_b + 1 ? dp_a : dp_b + 1;
			}
			else if (s[i] == 'b') {
				dp_b = dp_a < dp_b ? dp_a : dp_b;
				dp_a++;
			}
		}

		return dp_a < dp_b ? dp_a : dp_b;
	}
};

#endif // __leet_code_1653_h__