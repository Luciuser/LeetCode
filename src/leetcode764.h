/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-09 10:29:31
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode764.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-09 14:17:35
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 828ms, 10.47%, MEMORY 34MB and 45.02%
 */

#ifndef __leet_code_764__
#define __leet_code_764__

#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:

    struct Hash_pair {
        template<class T1, class T2>
        size_t operator()(const std::pair<T1, T2>& p) const {
            return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
        }
    };

    void print(std::vector<std::vector<int>>& a) {
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                std::cout.width(5);
                std::cout << a[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        return;
    }

    int orderOfLargestPlusSign(int n, std::vector<std::vector<int>>& mines) {
        
        // ��̬�滮
        // �� dp[i][j][k] ��ʾ�� i �е� j ���� k �������������� 1 ������
        // �� result[i][j] ��ʾ�� i �� �� j �����γɵļӺ�
        // ���� result[i][j] = min(dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]);
        // ��������ֵΪ max(result[i][j])

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        std::unordered_set<std::pair<int, int>, Hash_pair> zero;
        for (int i = 0; i < mines.size(); i++) {
            zero.emplace(std::make_pair(mines[i][0], mines[i][1]));
        }

        for (int i = 0; i < n; i++) {
            // �������Ҽ���
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (zero.count(std::make_pair(i, j)) == 0) {
                    count++;
                }
                else {
                    count = 0;
                }
                dp[i][j] = count;
            }
            print(dp);
            count = 0;
            // �����������
            for (int j = n - 1; j >=0; j--) {
                if (zero.count(std::make_pair(i, j)) == 0) {
                    count++;
                }
                else {
                    count = 0;
                }
                if (count < dp[i][j]) {
                    dp[i][j] = count;
                }
            }
            print(dp);
        }

        for (int j = 0; j < n; j++) {
            // �������¼���
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (zero.count(std::make_pair(i, j)) == 0) {
                    count++;
                }
                else {
                    count = 0;
                }
                if (count < dp[i][j]) {
                    dp[i][j] = count;
                }
            }
            print(dp);
            count = 0;
            // �������ϼ���
            for (int i = n - 1; i >= 0; i--) {
                if (zero.count(std::make_pair(i, j)) == 0) {
                    count++; 
                }
                else {
                    count = 0;
                }
                if (count < dp[i][j]) {
                    dp[i][j] = count;
                }
            }
            print(dp);
        }

        // Ѱ�����ֵ
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (max < dp[i][j]) {
                    max = dp[i][j];
                }
            }
        }

        return max;
    }
};


#endif // __leet_code_764__