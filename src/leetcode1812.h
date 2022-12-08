/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-08 10:39:29
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1812.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-08 10:42:44
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.9MB and 14.21%
 */

#ifndef __leet_code_1812__
#define __leet_code_1812__

#include<iostream>
#include<string>

class Solution {
public:
    bool squareIsWhite(std::string coordinates) {
        int x = coordinates[0] - 'a' + 1;
        int y = coordinates[1] - '0';

        return (x + y) % 2 == 1;
    }
};

#endif // __leet_code_1812__