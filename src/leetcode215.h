#ifndef __leet_code_215__
#define __leet_code_215__

#include<iostream>
#include<vector>
#include<algorithm>

//#define SORT_RETURN_METHOD // 先通过快速排序排好，再直接返回第 size()-k 个数
#define SORT_CHOOSE_METHOD // 重写快排算法，在快排尚未执行完毕时就返回第 k 个最大的数

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
				// 已经全部遍历一遍了
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

			// 第i个数大于x，第j个数小于x
			int temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
};
#endif // SORT_CHOOSE_METHOD

#endif //__leet_code_215__