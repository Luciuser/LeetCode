/*
 * @Author: Bingyang Jin
 * @Date: 2023-05-04 08:48:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2106.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-05-04 16:13:10
 * @Editor: Bingyang Jin
 * @Description: create DICHOTOMY_METHOD，TIME 344ms, 63.79%, MEMORY 121MB and 47.41%
 */

#ifndef __leet_code_2106__
#define __leet_code_2106__

#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        //std::unordered_map<int, int> position_amount; // 每个位置所对应的果子个数
        std::vector<int> position(fruits.size()); // 位置序列，用于二分查找
        std::vector<int> prefix(fruits.size() + 1, 0); // 前缀和数组，表示前 i 个可选位置的果子总数
        int start_idx = fruits.size(); // 初始位置在 fruits[start_idx-1] 到 fruits[start_idx] 之间
        for (int i = 0; i < fruits.size(); i++) {
            position[i] = fruits[i][0];
            //position_amount[fruits[i][0]] = position_amount[fruits[i][1]];
            prefix[i + 1] = prefix[i] + fruits[i][1];
            if (fruits[i][0] > startPos && start_idx == fruits.size()) {
                start_idx = i;
            }
        }

        int sum = 0;
        // 第一种方案，先向左侧走，每次遇到草莓后向右反走至极限，计算最大值
        for (int i = start_idx - 1; i >= 0; i--) {
            int left = fruits[i][0];
            if (startPos - left > k) {
                break;
            }
            int temp = left + (k - (startPos - left));
            int right = startPos > temp ? startPos : temp;

            // left 在 fruits 里对应的 id 是 i，需求解 right 在 fruits 里对应的 id
            int right_idx = std::upper_bound(position.begin() + i, position.end(), right) - position.begin();

            int current_sum = prefix[right_idx] - prefix[i];
            if (sum < current_sum) {
                sum = current_sum;
            }
        }
        // 第二种方案，先向右侧走，每次遇到草莓后向左反走至极限，计算最大值
        for (int i = start_idx; i < fruits.size(); i++) {
            int right = fruits[i][0];
            if (right - startPos > k) {
                break;
            }
            int temp = right - (k - (right - startPos));
            int left = startPos < temp ? startPos : temp;

            // right 在 fruits 里对应的 id 是 i，需求解 left 在 fruits 里对应的 id
            int left_idx = std::lower_bound(position.begin(), position.begin() + i, left) - position.begin();

            int current_sum = prefix[i + 1] - prefix[left_idx];
            if (sum < current_sum) {
                sum = current_sum;
            }
        }

        return sum;
    }
};

#endif // __leet_code_2106__