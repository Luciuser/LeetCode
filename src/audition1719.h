/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-26 10:48:49
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition1719.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-26 10:55:22
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD, TIME 56ms, 5.96%, MEMORY 32.4MB and 5.10%
 */

 /*
 * @EditTime: 2022-09-26 11:37:34
 * @Editor: Bingyang Jin
 * @Description: create MATH_METHOD , TIME 36ms, 17.45%, MEMORY 21.8MB and 39.36%
 */

#ifndef __leet_code_audition_17_19__
#define __leet_code_audition_17_19__

#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_set>

//#define HASH_MAP_METHOD // ��ϣ����д洢��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��TIME 56ms, 5.96%, MEMORY 32.4MB and 5.10%
#define MATH_METHOD // ��ѧ����ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��TIME 36ms, 17.45%, MEMORY 21.8MB and 39.36%

#ifdef HASH_MAP_METHOD
class Solution {
public:
	std::vector<int> missingTwo(std::vector<int>& nums) {
		int n = nums.size();
		std::unordered_set<int> numberSet;
		for (int i = 0; i < n; i++) {
			numberSet.emplace(nums[i]);
		}

		std::vector<int> result;
		for (int i = 1; i <= n + 2; i++) {
			if (numberSet.count(i) == 0) {
				result.push_back(i);
			}
			if (result.size() == 2) {
				break;
			}
		}

		return result;
	}
};
#endif // HASH_MAP_METHOD

#ifdef MATH_METHOD
class Solution {
public:
	std::vector<int> missingTwo(std::vector<int>& nums) {
		int n = nums.size();
		int realSum = (n + 3)*(n + 2) / 2;
		int sum = std::accumulate(nums.begin(), nums.end(), 0);

		// ��ȱ�ٵ�������Ϊ a��b�������� a > b������У�
		// a+b = realSum - sum
		int a_add_b = realSum - sum;

		// ���� a > b���� a + b = a_add_b
		// �� 0 < b < a_add_b / 2 < a < a_add_b
		// �� bSum = 1+2+����+[a_add_b/2] ��aSum = [a_add_b/2 + 1]+[a_add_b/2 + 2]+����+[a_add_b - 1]
		// ���� aRealSum - bRealSum + a - b = aSum - bSum
		// a - b = aSum - aRealSum + bRealSum - bSum
		int left, right, end = a_add_b - 1;
		if (a_add_b % 2 == 0) {
			left = a_add_b / 2 - 1;
			right = a_add_b / 2 + 1;
		}
		else {
			left = a_add_b / 2;
			right = a_add_b / 2 + 1;
		}
		if (a_add_b - 1 > (n + 2)) {
			end = n + 2;
		}
		int aSum = (right + end) * (-right + end + 1) / 2;
		int bSum = (1 + left) * (1 + left - 1) / 2;
		int aRealSum = 0, bRealSum = 0;
		for (int i = 0; i < n; i++) {
			if (1 <= nums[i] && nums[i] <= left) {
				bRealSum += nums[i];
			}
			else if (right <= nums[i] && nums[i] <= end) {
				aRealSum += nums[i];
			}
		}
		int a_sub_b = aSum - aRealSum + bRealSum - bSum;

		std::vector<int> result;
		result.push_back((a_add_b + a_sub_b) / 2);
		result.push_back((a_add_b - a_sub_b) / 2);

		return result;
	}
};
#endif // MATH_METHOD

#endif // __leet_code_audition_17_19__