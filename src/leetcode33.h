/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-01 14:07:31
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode33.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-01 14:51:22
 * @Editor: Bingyang Jin
 * @Description: create BINARY_METHOD, TIME 8ms, 20.49%, MEMORY 10.8MB and 25.92%
 */

#ifndef __leet_code_33_h__
#define __leet_code_33_h__

#include<iostream>
#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        if (nums[left] == target) {
            return left;
        }
        else if (nums[right] == target) {
            return right;
        }

        if (n <= 2) {
            return -1;
        }
        if (nums[right] > nums[left]) {
            int position = std::lower_bound(nums.begin() + left, nums.begin() + right, target) - nums.begin();
            if (nums[position] == target) {
                return position;
            }
            else {
                return -1;
            }
        }

        while (true) {
            if (left + 1 == right) {
                break;
            }

            int middle = (left + right) / 2;
            if (nums[middle] < nums[left]) {
                // [left, middle] 是复杂数组，[middle, right] 是递增数组
                // 且存在 nums[middle] < nums[right] < nums[left]
                if (nums[middle] == target) {
                    return middle;
                }
                else if (target < nums[middle]) {
                    right = middle;
                }
                else if (nums[middle] < target && target < nums[right]) {
                    int position = std::lower_bound(nums.begin() + middle, nums.begin() + right, target) - nums.begin();
                    if (nums[position] == target) {
                        return position;
                    }
                    else {
                        break;
                    }
                }
                else if (nums[right] < target && target < nums[left]) {
                    break;
                }
                else {
                    right = middle;
                }

            }
            else {
                // [left, middle] 是递增数组，[middle, right] 是复杂数组
                // 且存在 nums[right] < nums[left] < nums[middle]
                if (nums[middle] == target) {
                    return middle;
                }
                else if (target < nums[right]) {
                    left = middle;
                }
                else if (nums[right] < target && target < nums[left]) {
                    break;
                }
                else if (nums[left] < target && target < nums[middle]) {
                    int position = std::lower_bound(nums.begin() + left, nums.begin() + middle, target) - nums.begin();
                    if (nums[position] == target) {
                        return position;
                    }
                    else {
                        break;
                    }
                }
                else {
                    left = middle;
                }
            }
        }

        return -1;
    }
};

#endif // __leet_code_33_h__