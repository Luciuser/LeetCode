/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-26 00:18:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode862.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-25 09:48:15
 * @Editor: Bingyang Jin
 * @Description: create SINGLE_ERGODIC_METHOD, TIME 4ms, 43.49%, MEMORY 7.5MB and 93.74%
 */

#ifndef __leet_code_862__
#define __leet_code_862__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {

		// ��ǰ׺�� S[i][j] = a[i] + a[i+1] + ���� + a[j-2] + a[j-1]������ j - i ����֮��
		// ����Ŀ����Ϊ���е� S[i][j] = k �У�j - i ��С��һ��
		// �ɼ���ǰ׺�� S[0][i] = a[0] + a[1] + ���� + a[j-2] + a[j-1]���� S[i][j] = S[0][j] - S[0][i] = k   ==>   S[0][i] = S[0][j] - k

		// ����ǰ׺�ͣ�O(n)
		std::vector<int> prefix(nums.size() + 1, 0);
		for (int i = 0; i < nums.size(); i++) {
			prefix[i + 1] = prefix[i] + nums[i];
		}
		// ����ǰ׺�ͣ��� ���� i<j ͬʱ prefix[i] > prefix[j] ʱ������ֱ��ɾȥ prefix[i]
		// ��Ϊ������ĳ�� k���� i<j<k ʱ���������� prefix[k] - prefix[m] > k���� i ����ʱ��j һ������������ʱ k-j < k-i�������迼�ǵ� i ��ǰ׺��
		//int prefixSize = 0;
		std::vector<bool> isDelete(prefix.size(), false);
		int before = prefix[prefix.size() - 1];
		for (int i = 1; i + 1 < prefix.size(); i++) {
			int current = prefix[prefix.size() - i - 1];
			if (current > before) {
				isDelete[prefix.size() - i - 1] = true;
			}
			else {
				before = current;
			}
		}
		std::vector<int> order;
		for (int i = 0; i < prefix.size(); i++) {
			if (isDelete[i] == false) {
				order.push_back(prefix[i]);
				//prefix[prefixSize] = prefix[i];
				//prefixSize++;
			}
		}

		// ���ַ�һ�α���
		bool find = false;
		int min = std::numeric_limits<int>::max();

		for (int i = 0; i < prefix.size(); i++) {
			int destination = prefix[i] - k;
			int index = std::lower_bound(order.begin(), order.end(), destination, std::less<>()) - order.begin();
			if (index < i && i - index < min) {
				find = true;
				min = i - index;
			}
		}

		if (find) {
			return min;
		}

		return -1;
	}
};

#endif // __leet_code_862__