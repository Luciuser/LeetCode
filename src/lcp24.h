/*
 * @Author: Bingyang Jin
 * @Date: 2024-02-01 09:42:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/lcp24.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2024-02-01 11:40:45
 * @Editor: Bingyang Jin
 * @Description: create ANSWER_METHOD, TIME 79ms, 100.00%, MEMORY 70.89MB and 22.22%
 */

#ifndef __lcp_24_h__ 
#define __lcp_24_h__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
	std::vector<int> numsGame(std::vector<int>& nums) {

		int n = nums.size();
		std::vector<int> result(n, 0);
		int MOD = 1000000007;

		// ������ݣ�
		// ����һ��ͨ������λ�õļӼ�����ʹ�� nums ���� nums[i] + 1 = nums[i+1] ʱ�������ս�� nums[0] = k������ nums[i] = k + i
		//                     ������ s[k] = sum(nums[i] - k - i) = sum((nums[i] - i) - k) = sum(x[i] - k)������ x[i] = nums[i] - i��
		//               ��˽� nums ���в����������� nums[0] = k��nums[i] + 1 = nums[i+1] ʱ�Ĳ����� s[k]����� x ���в�����ʹ�� x[i] = k �Ĳ�������ȫ��ͬ
		//               �ʽ��е�һ�λ��򣬶� nums ����Ԥ�������� x ���飬������ת��Ϊ������ͬ�������������
		for (int i = 0; i < n; i++) {
			nums[i] -= i;
		}
		// ����������ڻ��������� nums ���ԣ�ͨ������λ�õļӼ�����ʹ�� nums ���� nums[i] == k ʱ��
		//                     ������Ϊ s[k] = sum(nums[i] - k) 
		//               �� nums ����С�������򣬲���β��ȡһ������һ�ԣ���˹��ɸ�����ʽ�磺[a0, an-1]��[a1, an-2]��[a2, an-3]����
		//               ��Ȼ���� k ���� [a0, an-1] ʱ�Ĳ����� s[k] ҪС�� k ������ [a0, an-1] ʱ�Ĳ��������Һ�һ��������ǰһ������������䣬�����ε���
		//               �� nums ������Ϊż���������һ������Ϊ [az, az+1]����Ȼ�� k �������� [az, az+1] �Ĳ�������С���Ҹ������ڴ������
		//               �� nums ������Ϊ�����������һ������Ϊ [az]����Ȼ�� k == az ʱ�Ĳ�������С
		//               ��˹�����ͬ��������ʱ�����Ž⣬����ͬ����Ϊ��������λ�������ǵ� k Ϊ��������˿�ȡ k == az ʱ��ȡ�����Ž�

		// ͨ�������Ż����У���̬��� nums ����ǰ i λ����λ��
		// ��֤ left ����λ����࣬right ����λ���Ҳ࣬��ż������ʱ��left �� right �� size ��ͬ����������ʱ��left �� right ��һ������ȡ���Ž� k = left.top()��
		// ��ʱ left ��������Ҫ����� k �Ĳ�����Ϊ k*left.size() - left_sum��right ��������Ҫ����� k �Ĳ�����Ϊ right_sum - k*right.size()��
		// �� nums ������Ϊż��ʱ��left.size() == right.size()���ܲ����� s = right_sum - k*right.size() + k*left.size() - left_sum = right_sum - left_sum��
		// �� nums ������Ϊ����ʱ��left.size() == right.size() + 1��
		//       �ܲ����� s = right_sum - k*right.size() + k*left.size() - left_sum = right_sum - k*right.size() + k*right.size() + k - left_sum = right_sum - left_sum + left.top()��
		std::priority_queue<int, std::vector<int>> left;
		std::priority_queue<int, std::vector<int>, std::greater<int>> right;
		long long left_sum = 0;
		long long right_sum = 0;

		left.emplace(nums[0]);
		left_sum += nums[0];
		for (int i = 1; i < n; i++) {
			if (nums[i] < left.top()) {
				left.emplace(nums[i]);
				left_sum += nums[i];
			}
			else {
				right.emplace(nums[i]);
				right_sum += nums[i];
			}

			if (left.size() < right.size()) {
				int temp = right.top();
				right.pop();
				left.emplace(temp);
				left_sum += temp;
				right_sum -= temp;
			}
			else if (left.size() > right.size() + 1) {
				int temp = left.top();
				left.pop();
				right.emplace(temp);
				left_sum -= temp;
				right_sum += temp;
			}

			long long temp = ((i + 1) % 2 == 0) ? right_sum - left_sum : right_sum - left_sum + left.top();
			if (temp > MOD) {
				temp %= MOD;
			}

			result[i] = temp;
		}


		return result;
	}
};

#endif // __lcp_24_h__