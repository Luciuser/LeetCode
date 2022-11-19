/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-18 08:54:12
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode831.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-18 10:23:30
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 120ms, 42.62%, MEMORY 52.6MB and 78.69%
 */

#ifndef __leet_code_891__
#define __leet_code_891__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
	int sumSubseqWidths(std::vector<int>& nums) {
		// ������ע��һ�㣬�ı� nums ������Ԫ�ص�˳����Ȼ��ı������г��ֵ�˳�򼰲����������ڲ���˳�򣬵������е��������䣬��ÿ�������еĿ�Ȳ���
		// ��˿����ȶ� nums �������������ж�̬�滮
		// ��̬�滮
		// �� dp[i] ��ʾ������ i ��ǰ i+1 ���������γɵ������е������������ظ�������У�
		//							dp[0] = 1
		//							dp[i+1] = 2 * dp[i] + 1	
		// �� max[i] �� min[i] �ֱ��ʾ�� i ���������е����ֵ����Сֵ
		// �� Max[i] �� Min[i] �ֱ��ʾ������ i ��ǰ i+1 ���������γɵ� dp[i] ���������е����ֵ����Сֵ�ͣ������ظ�������У�
		//							Max[i] = max[0] + max[1] + ���� + max[dp[i] - 1]
		//							Min[i] = min[0] + min[1] + ���� + min[dp[i] - 1]
		// �� s[i] ��ʾ������ i ��ǰ i+1 ���������γɵ� dp[i] �������еĿ�Ⱥͣ������ظ�������У�
		//							s[i] = (max[0] - min[0]) + (max[1] - min[1]) + ���� + (max[dp[i] - 1] - min[dp[i] - 1])		==>
		//							s[i] = Max[i] - Min[i]
		// �� nums ��������󣬱�֤ nums[i] <= nums[i+1]
		// ����п��� Max[i] �� Min[i] �Ķ�̬�滮���У�
		//							Min[i+1] = 2 * Min[i] + nums[i+1]
		//							Max[i+1] = Max[i] + dp[i] * nums[i+1] + nums[i+1]
		// �� s[i] ���е�����s[n] ��Ϊ�����

		// ����O(nlogn)
		std::sort(nums.begin(), nums.end());
		
		// ��̬�滮������ dp��Min��Max��s ����һ��������ʾ����
		long long dp = 1;
		long long Min = nums[0];
		long long Max = nums[0];
		long long s = Max - Min;
		long long MOD = 1e9 + 7;
		for (int i = 1; i < nums.size(); i++) {
			//std::cout << "dp: " << dp << std::endl;
			//std::cout << "Min: " << Min << std::endl;
			//std::cout << "Max : " << Max << std::endl;
			//std::cout << "nums : " << nums[i] << std::endl;

			Min = (2 * Min + nums[i]) % MOD;
			Max = (Max + dp * nums[i] + nums[i]) % MOD;
			dp = (2 * dp + 1) % MOD;
		}

		s = Max - Min;
		if (s < 0) {
			s += MOD;
		}

		return s;
	}
};

#endif // __leet_code_891__