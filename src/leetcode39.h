/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-10 13:24:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode39.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-10 14:05:27
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 16ms, 23.18%, MEMORY 41.6MB and 42.92%
 */

#ifndef __leet_code_39_h__
#define __leet_code_39_h__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        // 遍历剪枝，从大到小进行排序
        std::sort(candidates.begin(), candidates.end(), [](int a, int b) {
            return a > b;
        });

        std::vector<std::vector<int>> result;
        for (int i = 0; i < target; i++) {
            int temp = i * candidates[0];
            if (temp > target) {
                break;
            }
            else if (temp == target) {
                std::vector<int> method(i, candidates[0]);
                result.emplace_back(method);
                break;
            }
            else {
                std::vector<std::vector<int>> before = combinationSum(candidates, 1, target - temp);
                for (int j = 0; j < before.size(); j++) {
                    for (int k = 0; k < i; k++) {
                        before[j].emplace_back(candidates[0]);
                    }
                    result.emplace_back(before[j]);
                }
            }
        }

        return result;
    }

private:
    // 对于已经排好序的目标，从第 index 个开始，确定和为 target 的种类
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int index, int target) {
        std::vector<std::vector<int>> result;
        if (index >= candidates.size()) {
            return result;
        }
        for (int i = 0; i < target; i++) {
            int temp = i * candidates[index];
            if (temp > target) {
                break;
            }
            else if (temp == target) {
                std::vector<int> method(i, candidates[index]);
                result.emplace_back(method);
                break;
            }
            else {
                std::vector<std::vector<int>> before = combinationSum(candidates, index + 1, target - temp);
                for (int j = 0; j < before.size(); j++) {
                    for (int k = 0; k < i; k++) {
                        before[j].emplace_back(candidates[index]);
                    }
                    result.emplace_back(before[j]);
                }
            }
        }

        return result;
    }
};

#endif // __leet_code_39_h__