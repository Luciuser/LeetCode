/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-16 15:44:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode2488.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-15 16:27:03
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 92ms, 66.17%, MEMORY 48.5MB and 87.36%
 */

#ifndef __leet_code_2488_h__
#define __leet_code_2488_h__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int countSubarrays(std::vector<int>& nums, int k) {
        // �����Ҳ���ֵ��Ӧ��map
        std::unordered_map<int, int> right_frequence; // ��ʾ�� k �Ҳ��������У�left-right��Ƶ���ж�ߣ��� key Ϊ������˵����ӦƵ���������� k �Ҳ���������������֮��Ȼ
        int k_index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) {
                k_index = i;
                break;
            }
        }

        int left = 0, right = 0; // left ��ʾС�� k �����ĸ�����right ��ʾ���� k �����ĸ���
        right_frequence[0]++; // ֻ�� k �����
        for (int i = k_index + 1; i < nums.size(); i++) {
            nums[i] < k ? left++ : right++;
            right_frequence[left - right]++;
        }

        // �� k ��࿪ʼ���ӣ���������������
        int sum = 0;
        left = 0;
        right = 0;
        for (int i = k_index; i >= 0; i--) {
            if (i != k_index) {
                nums[i] < k ? left++ : right++;
            }
            // k �����������ж���
            int n = k_index - i;
            if (right_frequence.count(right - left) != 0) {
                sum += right_frequence[right - left];
            }
            if (right_frequence.count(right - left - 1) != 0) {
                sum += right_frequence[right - left - 1];
            }
        }

        return sum;
    }
};
#endif // __leet_code_2488_h__