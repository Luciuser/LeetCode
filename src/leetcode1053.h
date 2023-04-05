/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-03 11:18:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1053.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-01 12:45:22
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 20ms, 82.01%, MEMORY 24MB and 87.77%
 */

#ifndef __leet_code_1053_h__
#define __leet_code_1053_h__

#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    std::vector<int> prevPermOpt1(std::vector<int>& arr) {
        int n = arr.size();

        std::map<int, int> number_index; // 从右往左遍历时，每个数最新出现的位置

        int min = 1e5; // 当前出现的最小数字
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] > min) {
                // 进行交换，交换时选择所有小于 arr[i] 的数中最大的一个
                int j = i + 1;
                for (auto iter = number_index.begin(); iter != number_index.end(); iter++) {
                    if ((*iter).first >= arr[i]) {
                        iter--;
                        j = (*iter).second;
                        break;
                    }
                }

                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                break;
            }
            else {
                min = arr[i];
                number_index[arr[i]] = i;
            }
        }

        return arr;
    }
};

#endif // __leet_code_1053_h__