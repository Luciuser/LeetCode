/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-08 11:36:20
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode777.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-08 09:55:00
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 64ms, 26.06%, MEMORY 29.5MB and 13.56%
 */

#ifndef __leet_code_777__
#define __leet_code_777__

#include<iostream>
#include<vector>
#include<string>
#include<assert.h>

class Solution {
public:
    bool canTransform(std::string start, std::string end) {
        // 检测 L、R、X 的数量是否相等
        int L_n = 0, R_n = 0, X_n = 0;
        for (int i = 0; i < start.size(); i++) {
            switch (start[i])
            {
            case 'L': L_n++; break;
            case 'R': R_n++; break;
            case 'X': X_n++; break;
            default:
                assert(false);
            }
        }
        int L_temp = 0, R_temp = 0, X_temp = 0;
        for (int i = 0; i < end.size(); i++) {
            switch (end[i])
            {
            case 'L': L_temp++; break;
            case 'R': R_temp++; break;
            case 'X': X_temp++; break;
            default:
                assert(false);
            }
        }
        if (L_temp != L_n || R_temp != R_n || X_temp != X_n) {
            return false;
        }

        //if (X_n == 0) {
        //    for (int i = 0; i < start.size(); i++) {
        //        if(start[])
        //    }
        //}

        // 建立一个数组，存储 end 每两个 X 之间 R 和 L 的数量
        std::vector<int> end_R(X_n + 1, 0);
        std::vector<int> end_L(X_n + 1, 0);
        int position = 0;
        for (int i = 0; i < end.size(); i++) {
            switch (end[i])
            {
            case 'L': end_L[position]++; break;
            case 'R': end_R[position]++; break;
            case 'X': position++; break;
            default:
                assert(false);
            }
        }
        
        // 建立一个数组，存储 end 每两个 X 之间能够获得的 R 和 L 的数量
        int temp = 0;
        position = 0;
        for (int i = 0; i < start.size(); i++) {
            switch (start[i])
            {
            case 'L': break;
            case 'R': temp++; break;
            case 'X': {
                if (temp >= end_R[position]) {
                    temp -= end_R[position];
                    position++;
                }
                else {
                    return false;
                }
                break;
            }
            default:
                assert(false);
            }
        }
        temp = 0;
        position = X_n;
        for (int i = start.size() - 1; i >= 0; i--) {
            switch (start[i])
            {
            case 'L': temp++; break;
            case 'R': break;
            case 'X': {
                if (temp >= end_L[position]) {
                    temp -= end_L[position];
                    position--;
                }
                else {
                    return false;
                }
                break;
            }
            default:
                assert(false);
            }
        }

        return true;
    }
};

#endif //__leet_code_777__