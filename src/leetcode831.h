/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-01 13:40:19
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode831.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-01 13:56:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.8MB and 93.85%
 */

#ifndef __leet_code_831_h__
#define __leet_code_831_h__

#include<iostream>
#include<string>

class Solution {
public:
    std::string maskPII(std::string s) {

        bool is_mail = false;
        if (('a' <= s[0] && s[0] <= 'z') || ('A' <= s[0] && s[0] <= 'Z')) {
            is_mail = true;
        }

        if (is_mail) {
            int position = s.find_first_of('@');
            if ('A' <= s[0] && s[0] <= 'Z') {
                s[0] = s[0] - 'A' + 'a';
            }
            if ('A' <= s[position-1] && s[position - 1] <= 'Z') {
                s[position - 1] = s[position - 1] - 'A' + 'a';
            }
            std::string result = "";
            result += s[0];
            result += "*****";
            result += s[position - 1];
            result += "@";
            for (int i = position + 1; i < s.size(); i++) {
                if ('A' <= s[i] && s[i] <= 'Z') {
                    s[i] = s[i] - 'A' + 'a';
                }
                result += s[i];
            }
            return result;
        }
        else {
            std::string numbers = "";
            for (int i = 0; i < s.size(); i++) {
                if ('0' <= s[i] && s[i] <= '9') {
                    numbers += s[i];
                }
            }
            int n = numbers.size();
            int temp = n - 10;
            std::string result = "";
            if (temp > 0) {
                result += "+";
                for (int i = 0; i < temp; i++) {
                    result += "*";
                }
                result += "-";
            }
            result += "***-***-";
            for (int i = n - 4; i < n; i++) {
                result += numbers[i];
            }
            return result;
        }

        return s;
    }
};

#endif // __leet_code_831_h__