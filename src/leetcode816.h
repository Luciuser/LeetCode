/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-07 10:10:35
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode816.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-06 11:04:13
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 8ms, 65.47%, MEMORY 8.7MB and 94.24%
 */

#ifndef __leet_code_816__
#define __leet_code_816__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:

    bool isRightNumber(std::string str, int index) {
        if (str[0] == '0' && index != 1) {
            return false;
        }
        if (str[str.size() - 1] == '0' && index != str.size()) {
            return false;
        }

        return true;
    }

    std::vector<std::string> ambiguousCoordinates(std::string s) {
        
        std::vector<std::string> result;
        s = s.substr(1, s.size() - 2);
        // 逗号取在第 i-1 和 第 i 之间
        for (int i = 1; i < s.size(); i++) {
            std::string left = s.substr(0, i);
            std::string right = s.substr(i, s.size() - i);
            for (int j = 1; j <= left.size(); j++) {
                if (isRightNumber(left, j) == false) {
                    continue;
                }

                for (int k = 1; k <= right.size(); k++) {
                    if (isRightNumber(right, k)) {
                        std::string temp = "(";
                        if (j == left.size()) {
                            temp += left;
                        }
                        else {
                            std::string left_temp = left;
                            left_temp.insert(j, 1, '.');
                            temp += left_temp;
                        }
                        temp += ",";
                        if (k == right.size()) {
                            temp += right;
                        }
                        else {
                            std::string right_temp = right;
                            right_temp.insert(k, 1, '.');
                            temp += right_temp;
                        }
                        temp += ")";
                        result.push_back(temp);
                    }
                }
            }
        }

        return result;
    }
};

#endif // __leet_code_816__