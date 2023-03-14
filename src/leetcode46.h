/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-14 20:28:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode46.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-14 20:52:08
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 66.84%, MEMORY 7.4MB and 82.14%
 */

#ifndef __leet_code_46_h__
#define __leet_code_46_h__

#include<iostream>
#include<algorithm>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {

        int n = nums.size();
        int sum = 1;
        while (n >= 1) {
            sum *= n;
            n--;
        }
        n = nums.size();

        std::sort(nums.begin(), nums.end(), [=](int a, int b) {
            return a < b;
        });

        std::vector<std::vector<int>> result;
        result.emplace_back(nums);
        // 针对每一个排列，去寻找下一个排列
        while (true) {
            if (result.size() == sum) {
                break;
            }
            int before = nums[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] > before) {
                    before = nums[i];
                }
                else {
                    int j = i + 1;
                    while (j < n) {
                        if (nums[j] <= nums[i]) {
                            j--;
                            break;
                        }
                        j++;
                    }
                    if (j >= n) {
                        j--;
                    }
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;

                    j = i + 1;
                    int k = n - 1;
                    while (j < k) {
                        int temp = nums[j];
                        nums[j] = nums[k];
                        nums[k] = temp;
                        k--;
                        j++;
                    }
                    result.emplace_back(nums);
                    break;
                }
            }
        }

        return result;

    }
};

#endif // __leet_code_46_h__