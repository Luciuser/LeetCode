#ifndef __leet_code_215__
#define __leet_code_215__

#include<iostream>
#include<vector>
#include<algorithm>

//#define SORT_RETURN_METHOD // ��ͨ�����������źã���ֱ�ӷ��ص� size()-k ����
#define SORT_CHOOSE_METHOD // ��д�����㷨���ڿ�����δִ�����ʱ�ͷ��ص� k ��������

#ifdef SORT_RETURN_METHOD
class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		std::sort(nums.begin(), nums.end(), [=](int a, int b) ->bool {return a < b; });

		return nums[nums.size() - k];
	}
};
#endif // SORT_RETURN_METHOD

#ifdef SORT_CHOOSE_METHOD
class Solution {
public:
	int findKthLargest(std::vector<int>& nums, int k) {
		int x = 0;
		int left = 0;
		int right = nums.size() - 1;
		int i = left;
		int j = right;
		while (true) {
			if (i >= j) {
				int temp = nums[x];
				nums[x] = nums[j];
				nums[j] = temp;
				// �Ѿ�ȫ������һ����
				if (k == nums.size() - j) {
					return nums[j];
				}
				else if (k < nums.size() - j) {
					x = i;
					j = right;
					left = i;
				}
				else if (k > nums.size() - j) {
					x = left;
					i = left;
					right = j - 1;
					j--;
				}
			}

			while (nums[i] <= nums[x] || nums[j] > nums[x]) {
				if (i > j) {
					break;
				}
				if (nums[i] <= nums[x]) {
					i++;
				}
				if (nums[j] > nums[x]) {
					j--;
				}

				if (i == nums.size() - 1) {
					break;
				}
				if (j == 0) {
					break;
				}
			}

			if (i > j) {
				continue;
			}

			// ��i��������x����j����С��x
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
};
#endif // SORT_CHOOSE_METHOD

#endif //__leet_code_215__