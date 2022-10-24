/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-24 00:07:07
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode915.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-24 00:26:12
 * @Editor: Bingyang Jin
 * @Description: create HASH_MAP_METHOD, TIME 372ms, 5.05%, MEMORY 120.3MB and 5.05%
 */

 /*
 * @EditTime: 2022-10-24 10:51:02
 * @Editor: Bingyang Jin
 * @Description: create ERGODIC_METHOD, TIME 116ms, 84.97%, MEMORY 92MB and 81.76%
 */

//#define HASH_MAP_METHOD // 哈希表映射，TIME 372ms, 5.05%, MEMORY 120.3MB and 5.05%
#define ERGODIC_METHOD // 一次遍历，TIME 116ms, 84.97%, MEMORY 92MB and 81.76%

#ifndef __leet_code_915__
#define __leet_code_915__

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#ifdef HASH_MAP_METHOD
class Solution {
public:
	int partitionDisjoint(std::vector<int>& nums) {

		// 红黑树，O(nlogn)
		std::map<int, int>order;
		for (int i = 0; i < nums.size(); i++) {
			order[nums[i]]++;
		}

		// 遍历，O(n)
		auto iter = order.begin();
		int leftMax = -1;
		int rightMin = (*iter).first;
		int cut = 0;
		for (; cut < nums.size(); cut++) {
			// 更新左边数组
			if (nums[cut] > leftMax) {
				leftMax = nums[cut];
			}
			// 更新右边数组
			order[nums[cut]]--;
			while ((*iter).second == 0) {
				iter++;
			}
			rightMin = (*iter).first;
			// 判断是否成立
			if (leftMax <= rightMin) {
				break;
			}

		}

		return cut + 1;
	}
};
#endif // HASH_MAP_METHOD


#ifdef ERGODIC_METHOD
class Solution {
public:
	int partitionDisjoint(std::vector<int>& nums) {

		int max = nums[0];
		int crtMax = nums[0];
		int cut = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > max) {
				max = nums[i];
			}
			
			if (nums[i] < crtMax) {
				cut = i + 1;
				crtMax = max;
			}
		}

		return cut;
	}
};
#endif // ERGODIC_METHOD

#endif // __leet_code_915__