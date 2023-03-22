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
        // 整体思路：打表，做出每个量级内重复正整数的个数，如下表 table 所示，具体而言，table[i] 表示在 [10^i, 10^(i+1)-1] 之间有多少个符合要求的正整数（例如 table[3]，即计算 [1000-9999] 之间有多少个符合要求的正整数）
        // 观察发现 [100-199] 和 [200-299] 之间重复正整数个数相同；容易证明 [a*(10^x), (a+1)*(10^x)-1] 与任意 [b*(10^x), (b+1)*(10^x)-1] 区间内重复正整数个数相同，且当 a != b 时，两区间内正整数均不相同
        // 根据上述发现，可以对表 table 进行维护，每一项除以 9，此时，table[i] 表示在 [1*10^i, 2*10^i-1] 之间有多少个符合要求的正整数（例如 table[3]，即计算 [1000-1999] 之间有多少个符合要求的正整数）
        // 对任意正整数 n，其数位从低到高可表示为 nums[i]，其中 i 为从低到高第几个数位
        // 根据 table，易得最终结果即为 (nums[i]-1) * table[i] 求和即可
        
        // 以下代码分两部分，第一部分为打表，第二部分为针对 n 进行计算

        // 第一部分：打表
        // 为进行打表，需要采用数位动态规划的方案，具体如下所述：
        // 设 dp[n][i] 表示当前剩余 n 个数字需要填充，且已经有 i 个不重复的数字
        // 考虑下一位进行填充时，有 i 种情况会出现重复数字，有 (10-i) 种情况不会出现重复数字
        // 对于前者，因为已经重复，那么后续数位可以自由填充，且由于前序数位已经确定，已经必不会重叠；对于后者，当 i 不为 10 时，可以进行递归计算
        // 综上所述，动态规划递推公式为：
        //              dp[n][i] = i * 10^(n-1) + (10-i) * dp[n-1][i+1]
        // 初始条件为：
        //              dp[0][i] = 0;

        // 动态规划
        std::vector < std::vector<int> > dp(10, std::vector<int>(11, 0));
        // 进行动态规划递推
        for (int n = 1; n <= 9; n++) {
            for (int i = 9; i >= 1; i--) {
                dp[n][i] = i * pow(10, n-1) + (10 - i) * dp[n - 1][i + 1];
                std::cout << "n  i  " << n << " " << i << " : " << dp[n][i]  << std::endl;
            }
        }
        // 打表
        std::vector<int> table(10, 0);
        table[1] = 9;
        for (int index = 2; index <= 9; index++) {
            table[index] = dp[index][1];
            std::cout << table[index] << std::endl;
        }

        // 第二部分，基于打好的表进行计算
        // 打好的表如下所示：
        std::vector<int> table = { 0, 1, 28, 496, 6976, 84880, 939520, 9818560, 99637120, 999637120 };
        int sum = 0;
        // 计算 n 的数位
        int length = 1;
        int temp = n;
        while (temp >= 10) {
            length++;
            temp /= 10;
        }

        for (int i = 0; i < length - 1; i++) {
            sum += table[i];
        }

        // 从右向左第 9 位进行计算
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