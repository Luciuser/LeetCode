/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-18 18:22:53
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1616.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 18:42:55
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 56ms, 56.25%, MEMORY 23.8MB and 36.61%
 */

#ifndef __leet_code_1616_h__
#define __leet_code_1616_h__

#include<iostream>
#include<string>

class Solution {
public:
    bool checkPalindromeFormation(std::string a, std::string b) {
        int n = a.size();
        // �����ж� a �� b �ǲ��ǻ����ַ���
        bool is_ab_success = true;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != a[n - i - 1]) {
                is_ab_success = false;
                break;
            }
        }
        if (is_ab_success) {
            return true;
        }
        is_ab_success = true;
        for (int i = 0; i < n / 2; i++) {
            if (b[i] != b[n - i - 1]) {
                is_ab_success = false;
                break;
            }
        }
        if (is_ab_success) {
            return true;
        }

        // ����ܷ���ϳ�
        // ��� apre + bsuff
        is_ab_success = true;
        for (int i = 0; i < n / 2; i++) {
            if (a[i] != b[n - i - 1]) {
                is_ab_success = false;
                // ��ʱ���ж� a �� b �� [i, n-i-1] �Ƿ��ǻ���
                bool is_temp = true;
                for (int j = i; j < n / 2; j++) {
                    if (a[j] != a[n - j - 1]) {
                        is_temp = false;
                        break;
                    }
                }
                if (is_temp) {
                    return true;
                }
                is_temp = true;
                for (int j = i; j < n / 2; j++) {
                    if (b[j] != b[n - j - 1]) {
                        is_temp = false;
                        break;
                    }
                }
                if (is_temp) {
                    return true;
                }
                break;
            }
        }
        if (is_ab_success) {
            return true;
        }

        // ��� bpre + asuff
        for (int i = 0; i < n / 2; i++) {
            if (b[i] != a[n - i - 1]) {
                // ��ʱ���ж� a �� b �� [i, n-i-1] �Ƿ��ǻ���
                bool is_temp = true;
                for (int j = i; j < n / 2; j++) {
                    if (a[j] != a[n - j - 1]) {
                        is_temp = false;
                        break;
                    }
                }
                if (is_temp) {
                    return true;
                }
                is_temp = true;
                for (int j = i; j < n / 2; j++) {
                    if (b[j] != b[n - j - 1]) {
                        is_temp = false;
                        break;
                    }
                }
                if (is_temp) {
                    return true;
                }
                return false;
            }
        }

        return true;
    }
};

#endif // __leet_code_2488_h__