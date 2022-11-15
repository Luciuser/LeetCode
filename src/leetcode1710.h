/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-15 10:02:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1710.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-15 10:24:06
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 44ms, 43.33%, MEMORY 15.6MB and 30.99%
 */

#ifndef __leet_code_1710__
#define __leet_code_1710__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {

        int n = boxTypes.size();
        std::vector<int> boxes(n);
        for (int i = 0; i < n; i++) {
            boxes[i] = i;
        }

        std::sort(boxes.begin(), boxes.end(), [&](int a, int b) {
            return boxTypes[a][1] > boxTypes[b][1];
        });

        int temp = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int index = boxes[i];
            if (temp + boxTypes[index][0] > truckSize) {
                int t = truckSize - temp;
                sum += t * boxTypes[index][1];
                break;
            }
            else if (temp + boxTypes[index][0] == truckSize) {
                sum += boxTypes[index][0] * boxTypes[index][1];
                break;
            }
            else {
                sum += boxTypes[index][0] * boxTypes[index][1];
                temp += boxTypes[index][0];
            }
        }

        return sum;
    }
};

#endif // __leet_code_1710__