/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-14 15:18:17
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1605.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-14 16:23:16
 * @Editor: Bingyang Jin
 * @Description: create VIOLENCE_METHOD, TIME 120ms, 5.00%, MEMORY 32.4MB and 97.00%
 */

 /*
 * @EditTime: 2023-03-14 16:23:16
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 44ms, 97.00%, MEMORY 32.5MB and 70.00%
 */

#ifndef __leet_code_1605_h__
#define __leet_code_1605_h__

#include<iostream>
#include<vector>

//#define VIOLENCE_METHOD // ��������TIME 120ms, 5.00%, MEMORY 32.4MB and 97.00%
#define GREEDY_METHOD // ̰�ķ���TIME 44ms, 97.00%, MEMORY 32.5MB and 70.00%

#ifdef VIOLENCE_METHOD
class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        // �㷨���Ƚ� rowSum д��ÿһ�еĵ�һ�У�Ȼ���ÿһ�п�ʼ���Ѷ���������������

        int m = rowSum.size();
        int n = colSum.size();
        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            result[i][0] = rowSum[i];
        }

        // ��ÿһ�п�ʼ����ƽ�
        int temp = 0; // ����һ�п�ʼ�ƽ�
        for (int i = 0; i < n - 1; i++) {
            long long sum = 0;
            bool is_find = false;
            for (int j = temp; j < m; j++) {
                if (is_find) {
                    result[j][i + 1] = result[j][i];
                    result[j][i] = 0;
                }
                else {
                    sum += result[j][i];
                    if (sum > colSum[i]) {
                        is_find = true;
                        temp = j;
                        result[j][i + 1] = sum - colSum[i];
                        result[j][i] -= result[j][i + 1];
                    }
                }
            }
        }

        return result;
    }
};
#endif // VIOLENCE_METHOD

#ifdef GREEDY_METHOD
class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        // �㷨���Ƚ� rowSum д��ÿһ�еĵ�һ�У�Ȼ���ÿһ�п�ʼ���Ѷ���������������

        int m = rowSum.size();
        int n = colSum.size();
        std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
        
        int i = 0, j = 0; // ��ָ�����ָ��

        while (i < m && j < n) {
            int min = rowSum[i] < colSum[j] ? rowSum[i] : colSum[j];
            result[i][j] = min;
            rowSum[i] -= min;
            colSum[j] -= min;
            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }

        return result;
    }
};
#endif // GREEDY_METHOD

#endif // __leet_code_42_h__