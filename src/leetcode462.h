#ifndef __leet_code_462__
#define __leet_code_462__

#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
	int minMoves2(std::vector<int>& nums) {
		// �� nums ����󣬶���a0��a1�������ƶ���a0-a1֮��һ�㣬���貽����ͬ����Ϊa1-a0�������ƶ����ⲿһ�㣬���貽������
		// �����С�ƶ�������Ѱ�� nums ����λ�������������ƶ�����λ������
		int result = 0;

		std::sort(nums.begin(), nums.end(), [=](int a, int b)->bool {
			return a < b;
		});

		int i = 0;
		int j = nums.size() - 1;
		while (true) {
			if (i >= j) {
				break;
			}
			result += nums[j] - nums[i];
			i++;
			j--;
		}

		return result;
	}
	
};

#endif // !__leet_code_462__