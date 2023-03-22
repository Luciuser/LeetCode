/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-20 13:14:16
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1012.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-18 19:44:18
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 52ms, 57.80%, MEMORY 47.3MB and 22.19%
 */

#ifndef __leet_code_1012_h__
#define __leet_code_1012_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        // ����˼·���������ÿ���������ظ��������ĸ��������±� table ��ʾ��������ԣ�table[i] ��ʾ�� [10^i, 10^(i+1)-1] ֮���ж��ٸ�����Ҫ��������������� table[3]�������� [1000-9999] ֮���ж��ٸ�����Ҫ�����������
        // �۲췢�� [100-199] �� [200-299] ֮���ظ�������������ͬ������֤�� [a*(10^x), (a+1)*(10^x)-1] ������ [b*(10^x), (b+1)*(10^x)-1] �������ظ�������������ͬ���ҵ� a != b ʱ����������������������ͬ
        // �����������֣����ԶԱ� table ����ά����ÿһ����� 9����ʱ��table[i] ��ʾ�� [1*10^i, 2*10^i-1] ֮���ж��ٸ�����Ҫ��������������� table[3]�������� [1000-1999] ֮���ж��ٸ�����Ҫ�����������
        // ������������ n������λ�ӵ͵��߿ɱ�ʾΪ nums[i]������ i Ϊ�ӵ͵��ߵڼ�����λ
        // ���� table���׵����ս����Ϊ (nums[i]-1) * table[i] ��ͼ���
        
        // ���´���������֣���һ����Ϊ����ڶ�����Ϊ��� n ���м���

        // ��һ���֣����
        // Ϊ���д����Ҫ������λ��̬�滮�ķ�������������������
        // �� dp[n][i] ��ʾ��ǰʣ�� n ��������Ҫ��䣬���Ѿ��� i �����ظ�������
        // ������һλ�������ʱ���� i �����������ظ����֣��� (10-i) �������������ظ�����
        // ����ǰ�ߣ���Ϊ�Ѿ��ظ�����ô������λ����������䣬������ǰ����λ�Ѿ�ȷ�����Ѿ��ز����ص������ں��ߣ��� i ��Ϊ 10 ʱ�����Խ��еݹ����
        // ������������̬�滮���ƹ�ʽΪ��
        //              dp[n][i] = i * 10^(n-1) + (10-i) * dp[n-1][i+1]
        // ��ʼ����Ϊ��
        //              dp[0][i] = 0;

        // ��̬�滮
        std::vector < std::vector<int> > dp(10, std::vector<int>(11, 0));
        // ���ж�̬�滮����
        for (int n = 1; n <= 9; n++) {
            for (int i = 9; i >= 1; i--) {
                dp[n][i] = i * pow(10, n-1) + (10 - i) * dp[n - 1][i + 1];
                std::cout << "n  i  " << n << " " << i << " : " << dp[n][i]  << std::endl;
            }
        }
        // ���
        std::vector<int> table(10, 0);
        table[1] = 9;
        for (int index = 2; index <= 9; index++) {
            table[index] = dp[index][1];
            std::cout << table[index] << std::endl;
        }

        // �ڶ����֣����ڴ�õı���м���
        // ��õı�������ʾ��
        std::vector<int> table = { 0, 1, 28, 496, 6976, 84880, 939520, 9818560, 99637120, 999637120 };
        int sum = 0;
        // ���� n ����λ
        int length = 1;
        int temp = n;
        while (temp >= 10) {
            length++;
            temp /= 10;
        }

        for (int i = 0; i < length - 1; i++) {
            sum += table[i];
        }

        // ��������� 9 λ���м���
        for (int i = length; i >= 0; i--) {
            int number = pow(10, i);
            if (n >= 2 * number) {
                int temp = n / number;
                sum += (temp - 1) * table[i];
                n -= temp * number;
            }
        }

        return sum;
    }
};
#endif // __leet_code_1012_h__