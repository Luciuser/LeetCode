/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-06 10:54:27
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1678.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-06 10:57:36
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 42.04%
 */

#ifndef __leet_code_1678__
#define __leet_code_1678__

#include<string>

class Solution {
public:
    std::string interpret(std::string command) {
        std::string result = "";
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                result += 'G';
            }
            else if (command[i] == '(') {
                i++;
                if (command[i] == ')') {
                    result += 'o';
                }
                else {
                    result += "al";
                }
            }
        }

        return result;
    }
};

#endif // __leet_code_1678__