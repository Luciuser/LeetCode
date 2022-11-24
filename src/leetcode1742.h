/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-23 00:15:33
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1742.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-23 00:25:56
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 32ms, 27.63%, MEMORY 6MB and 30.26%
 */

 /*
 * @EditTime: 2022-11-23 12:08:26
 * @Editor: Bingyang Jin
 * @Description: create SUM_METHOD, TIME 36ms, 20.09%, MEMORY 6.1MB and 19.65%
 */

#ifndef __leet_code_1742__
#define __leet_code_1742__

#include<iostream>
#include<string>
#include<unordered_map>

//#define VIOLENCE_METHOD // 暴力遍历，TIME 32ms, 27.63%, MEMORY 6MB and 30.26%
#define SUM_METHOD // 和处理法，TIME 36ms, 20.09%, MEMORY 6.1MB and 19.65%

#ifdef VIOLENCE_METHOD
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        std::unordered_map<int, int> boxes;
        int result = 0;
        for (int i = 0; i < highLimit - lowLimit + 1; i++) {
            int sum = 0;
            int temp = lowLimit + i;
            while (temp >= 10) {
                sum += temp % 10;
                temp /= 10;
            }
            sum += temp;

            boxes[sum]++;
            if (boxes[sum] > result) {
                result = boxes[sum];
            }

        }

        return result;
    }
};
#endif // VIOLENCE_METHOD

#ifdef SUM_METHOD
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {

        std::string low = std::to_string(lowLimit);
        int n = low.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += low[i] - '0';
        }

        std::unordered_map<int, int> boxes;
        int result = 0;
        for (int i = 0; i < highLimit - lowLimit + 1; i++) {
            boxes[sum]++;
            if (boxes[sum] > result) {
                result = boxes[sum];
            }
            n = low.size();
            for (int j = n - 1; j >= 0; j--) {
                if (low[j] == '9') {
                    if (j == 0) {
                        low[j] = '0';
                        low = "1" + low;
                        sum -= 9;
                        sum += 1;
                        break;
                    }
                    else {
                        low[j] = '0';
                        sum -= 9;
                        continue;
                    }
                }
                else {
                    low[j] ++;
                    sum++;
                    break;
                }
            }

        }

        return result;
    }
};
#endif // SUM_METHOD

#endif // __leet_code_1742__