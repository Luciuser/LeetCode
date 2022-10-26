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
#include<algorithm>

class Solution {
public:
	int shortestSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<long> preSumArr(n + 1);
        for (int i = 0; i < n; i++) {
            preSumArr[i + 1] = preSumArr[i] + nums[i];
        }
        int res = n + 1;
        std::deque<int> qu;
        for (int i = 0; i <= n; i++) {
            long curSum = preSumArr[i];
            while (!qu.empty() && curSum - preSumArr[qu.front()] >= k) {
                res = std::min(res, i - qu.front());
                qu.pop_front();
            }
            while (!qu.empty() && preSumArr[qu.back()] >= curSum) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return res < n + 1 ? res : -1;
	}
};

#endif // __leet_code_862__