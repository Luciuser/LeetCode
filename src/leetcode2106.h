/*
 * @Author: Bingyang Jin
 * @Date: 2023-05-04 08:48:56
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2106.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-05-04 16:13:10
 * @Editor: Bingyang Jin
 * @Description: create DICHOTOMY_METHOD��TIME 344ms, 63.79%, MEMORY 121MB and 47.41%
 */

#ifndef __leet_code_2106__
#define __leet_code_2106__

#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<vector>

class Solution {
public:
    int maxTotalFruits(std::vector<std::vector<int>>& fruits, int startPos, int k) {
        //std::unordered_map<int, int> position_amount; // ÿ��λ������Ӧ�Ĺ��Ӹ���
        std::vector<int> position(fruits.size()); // λ�����У����ڶ��ֲ���
        std::vector<int> prefix(fruits.size() + 1, 0); // ǰ׺�����飬��ʾǰ i ����ѡλ�õĹ�������
        int start_idx = fruits.size(); // ��ʼλ���� fruits[start_idx-1] �� fruits[start_idx] ֮��
        for (int i = 0; i < fruits.size(); i++) {
            position[i] = fruits[i][0];
            //position_amount[fruits[i][0]] = position_amount[fruits[i][1]];
            prefix[i + 1] = prefix[i] + fruits[i][1];
            if (fruits[i][0] > startPos && start_idx == fruits.size()) {
                start_idx = i;
            }
        }

        int sum = 0;
        // ��һ�ַ�������������ߣ�ÿ��������ݮ�����ҷ��������ޣ��������ֵ
        for (int i = start_idx - 1; i >= 0; i--) {
            int left = fruits[i][0];
            if (startPos - left > k) {
                break;
            }
            int temp = left + (k - (startPos - left));
            int right = startPos > temp ? startPos : temp;

            // left �� fruits ���Ӧ�� id �� i������� right �� fruits ���Ӧ�� id
            int right_idx = std::upper_bound(position.begin() + i, position.end(), right) - position.begin();

            int current_sum = prefix[right_idx] - prefix[i];
            if (sum < current_sum) {
                sum = current_sum;
            }
        }
        // �ڶ��ַ����������Ҳ��ߣ�ÿ��������ݮ�������������ޣ��������ֵ
        for (int i = start_idx; i < fruits.size(); i++) {
            int right = fruits[i][0];
            if (right - startPos > k) {
                break;
            }
            int temp = right - (k - (right - startPos));
            int left = startPos < temp ? startPos : temp;

            // right �� fruits ���Ӧ�� id �� i������� left �� fruits ���Ӧ�� id
            int left_idx = std::lower_bound(position.begin(), position.begin() + i, left) - position.begin();

            int current_sum = prefix[i + 1] - prefix[left_idx];
            if (sum < current_sum) {
                sum = current_sum;
            }
        }

        return sum;
    }
};

#endif // __leet_code_2106__