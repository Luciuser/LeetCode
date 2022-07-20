#ifndef __leet_code_324__
#define __leet_code_324__

#include<iostream>
#include<vector>
#include<algorithm>

#define SORT_CHOOSE // 先排序，再进行选择处理

#ifdef SORT_CHOOSE
class Solution {
public:
	void wiggleSort(std::vector<int>& nums) {
		std::vector<int> temp = nums;
		std::sort(temp.begin(), temp.end(), [=](int a, int b) { return a < b; });
		int j = 0;
		int k = nums.size() - 1;
		//int k = nums.size() / 2;
		if (nums.size() % 2 == 0) {
			j = nums.size() / 2 - 1;
			//k = nums.size() / 2;
		}
		else {
			j = nums.size() / 2;
			//k = nums.size() / 2 + 1;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i % 2 == 0) {
				nums[i] = temp[j];
				j--;
			}
			else {
				nums[i] = temp[k];
				//k++;
				k--;
			}
		}
	}
};
#endif // SORT_CHOOSE



#endif // __leet_code_324__