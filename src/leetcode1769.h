/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-02 00:16:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1769.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-02 00:24:43
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 4ms, 91.79%, MEMORY 8.6MB and 91.05%
 */

#ifndef __leet_code_1769__
#define __leet_code_1769__

#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        // ��̬�滮
        // �� dp[i] ��ʾ����С���ƶ����� i �������ܴ���
        // ��¼�� i ������� 1 �ĸ���Ϊ left[i]���ұ߰����Լ� 1 �ĸ���Ϊ right[i]
        // ��ô״̬ת�ƹ�ʽΪ��dp[i+1] = dp[i] - right[i] + left[i]
        // ����� i ������ 1���� left[i+1] = left[i] + 1; right[i] = right[i] - 1;
        // ����ֵ�� dp ����

        int left = 0;
        int right = 0;
        int sum = 0;
        for (int i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                right++;
                sum += i;
            }
        }

        std::vector<int> result(boxes.size());
        result[0] = sum;
        if (boxes[0] == '1') {
            right--;
            left++;
        }
        for (int i = 1; i < boxes.size(); i++) {
            // �޸� result
            result[i] = result[i - 1] - right + left;
            // ά�� right �� left
            if (boxes[i] == '1') {
                right--;
                left++;
            }
        }

        return result;
    }
};

#endif // __leet_code_1769__