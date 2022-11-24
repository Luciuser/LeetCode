/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-24 09:16:32
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode795.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-24 09:43:01
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 60ms, 45.85%, MEMORY 51.1MB and 33.52%
 */

#ifndef __leet_code_795__
#define __leet_code_795__

#include<iostream>
#include<vector>

class Solution {
public:
    int numSubarrayBoundedMax(std::vector<int>& nums, int left, int right) {
        // �� n = nums.size()
        // �������������� left <= nums[i] <= right�����������������������Ϊ (n+1)*n/2
        // ������ nums[i] > right���������鲻�ܰ��� nums[i]����˿ɴ������з֣��ֱ����
        // ������ nums[i] < left���������鲻�ܵ������� nums[i]���ɼ�¼�������� nums[i] �������飬��ɾ��

        int n = nums.size();
        int sum = 0; // ���������
        int length = 0; // ��ǰ�����鳤��
        int small_length = 0; // С�� left ��������ĳ���
        for (int i = 0; i < n; i++) {
            if (nums[i] < left) {
                small_length++;
                length++;
            }
            else if (nums[i] > right) {
                sum += (length + 1) * length / 2;
                length = 0;
                sum -= (small_length + 1) * small_length / 2;;
                small_length = 0;
            }
            else {
                length++;
                sum -= (small_length + 1) * small_length / 2;;
                small_length = 0;
            }
        }
        sum += (length + 1) * length / 2;
        length = 0;
        sum -= (small_length + 1) * small_length / 2;;
        small_length = 0;

        return sum;
    }
};

#endif // __leet_code_795__