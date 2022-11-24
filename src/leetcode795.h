/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-24 09:16:32
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode795.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-24 09:43:01
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 60ms, 45.85%, MEMORY 51.1MB and 33.52%
 */

#ifndef __leet_code_795__
#define __leet_code_795__

#include<iostream>
#include<vector>

class Solution {
public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
        // 令 n = nums.size()
        // 若所有数均满足 left <= nums[i] <= right，则满足条件的子数组个数为 (n+1)*n/2
        // 若存在 nums[i] > right，则子数组不能包括 nums[i]，因此可从左右切分，分别计算
        // 若存在 nums[i] < left，则子数组不能单独包括 nums[i]，可记录单独包括 nums[i] 的子数组，并删除

        int n = nums.size();
        int sum = 0; // 总子数组和
        int length = 0; // 当前子数组长度
        int small_length = 0; // 小于 left 的子数组的长度
        for (int i = 0; i < n; i++) {
            if (nums[i] < left) {
                small_length++;
                length++;
            }
            else if (nums[i] > right) {
                sum += (length + 1) * length / 2;
                length = 0;
                sum -= (small_length + 1) * small_length / 2;;
                small_length = 0;
            }
            else {
                length++;
                sum -= (small_length + 1) * small_length / 2;;
                small_length = 0;
            }
        }
        sum += (length + 1) * length / 2;
        length = 0;
        sum -= (small_length + 1) * small_length / 2;;
        small_length = 0;

        return sum;
    }
};

#endif // __leet_code_795__