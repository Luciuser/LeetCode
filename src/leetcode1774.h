/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-04 00:07:10
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1774.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-04 11:00:21
 * @Editor: Bingyang Jin
 * @Description: create VOILENCE_METHOD, TIME 28ms, 60.89%, MEMORY 9.4MB and 91.58%
 */

#ifndef __leet_code_1774__
#define __leet_code_1774__

#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int closestCost(std::vector<int>& baseCosts, std::vector<int>& toppingCosts, int target) {

        int m = toppingCosts.size();
        std::vector<int> k(m, 0);
        int sum = 0;

        int result = baseCosts[0];
        while (true) {

            for (int i = 0; i < baseCosts.size(); i++) {
                int temp = sum + baseCosts[i];
                if (abs(target - temp) < abs(target - result)) {
                    result = temp;
                }
                else if (abs(target - temp) == abs(target - result)) {
                    if (temp < result) {
                        result = temp;
                    }
                }
            }

            k[0]++;
            sum += toppingCosts[0];
            int index = 0;
            while (true) {
                if (k[m - 1] == 3) {
                    break;
                }
                if (k[index] != 3) {
                    break;
                }

                sum -= (3 * toppingCosts[index]);
                k[index] = 0;
                index++;
                k[index]++;
                sum += toppingCosts[index];
            }

            if (k[m - 1] == 3) {
                break;
            }
        }

        return result;
    }
};

#endif // __leet_code_1774__