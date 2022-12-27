/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-26 00:18:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode862.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-26 16:14:15
 * @Editor: Bingyang Jin
 * @Description: create PREFIX_DEQUE_METHOD, TIME 224ms, 24.05%, MEMORY 102.4MB and 32.32%
 */

#ifndef __leet_code_862__
#define __leet_code_862__

#include<iostream>
#include<vector>
#include<deque>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {
		// ��ǰ׺�� S[i][j] = a[i] + a[i+1] + ���� + a[j-2] + a[j-1]������ j - i ����֮��
		// ����Ŀ����Ϊ���е� S[i][j] = k �У�j - i ��С��һ��
		// �ɼ���ǰ׺�� S[0][i] = a[0] + a[1] + ���� + a[j-2] + a[j-1]���� S[i][j] = S[0][j] - S[0][i] = k   ==>   S[0][i] = S[0][j] - k
		// �ɴ������ұ��� S[0][j]�������� S[0][i] ���� S[0][i] = S[0][j] - k������һ����������Ľ⣬��ʱ�ж� min �� j-i ����
		//	֮�� S[0][j] ���� map �У�Ϊ��֤ j-i ��С��ÿ�ο�ֱ���滻 map �е������������Ϊ���ֵ����


	// ����ǰ׺�ͣ�O(n)
		std::vector<int> prefix(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}

		// һ�α���
		bool find = false;
		int min = std::numeric_limits<int>::max();
		std::unordered_map<int, int> prefixIndex; // ǰ׺�ͳ����ڵڼ���������
		for (int i = 0; i < prefix.size(); i++) {
			int destination = prefix[i] - k;
			if (prefixIndex.count(destination) != 0) {
				int j = prefixIndex[destination];
				find = true;
				if (i - j < min) {
					min = i - j;
				}
			}
			prefixIndex[prefix[i]] = i;
		}

		if (find) {
			return min;
		}

		return -1;
	}
};

#endif // __leet_code_862__