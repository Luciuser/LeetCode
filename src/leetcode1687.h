/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-07 13:08:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1687.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-07 10:55:06
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, out of time
 */

 /*
 * @EditTime: 2022-12-08 10:33:30
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_PRIORITY_QUEUE_METHOD, TIME 416ms, 51.00%, MEMORY 151.9MB and 8.00%
 */

#ifndef __leet_code_1687__
#define __leet_code_1687__

#include<iostream>
#include<vector>
#include<stack>
#include<deque>

//#define DYNAMIC_PROGRAMMING_METHOD // 动态规划法，超时
#define DYNAMIC_PROGRAMMING_PRIORITY_QUEUE_METHOD // 动态规划+最小优先级队列，TIME 416ms, 51.00%, MEMORY 151.9MB and 8.00%

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {
public:
    int boxDelivering(std::vector<std::vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {

        int n = boxes.size();

        // 计算前缀和
        std::vector<int> neg(n, 0);
        for (int i = 1; i < n; i++) {
            if (boxes[i][0] == boxes[i - 1][0]) {
                neg[i] = neg[i - 1];
            }
            else {
                neg[i] = neg[i - 1] + 1;
            }
        }

        // 动态规划，可参见官方题解思路
        std::vector<int> dp(n + 1, 0); // dp[i] 表示前 i 个箱子的最小行程数，因此所求为 dp[n]
        dp[1] = neg[0] + 2;
        for (int i = 2; i <= n; i++) {
            int min = std::numeric_limits<int>::max();
            int sum = 0;
            int weight = 0;
            for (int j = 0; j < i; j++) {
                sum++;
                weight += boxes[i - j - 1][1];
                if (sum > maxBoxes || weight > maxWeight) {
                    break;
                }
                int temp = dp[i - j - 1] + neg[i - 1] - neg[i - j - 1] + 2;
                if (temp < min) {
                    min = temp;
                }
            }
            dp[i] = min;
        }

        return dp[n];
    }
};
#endif // DYNAMIC_PROGRAMMING_METHOD

#ifdef DYNAMIC_PROGRAMMING_PRIORITY_QUEUE_METHOD
class Solution {
public:
    int boxDelivering(std::vector<std::vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {

        int n = boxes.size();
        std::vector<int> p(n + 1), w(n + 1), neg(n + 1);
        std::vector<long long> W(n + 1);
        for (int i = 1; i <= n; ++i) {
            p[i] = boxes[i - 1][0];
            w[i] = boxes[i - 1][1];
            if (i > 1) {
                neg[i] = neg[i - 1] + (p[i - 1] != p[i]);
            }
            W[i] = W[i - 1] + w[i];
        }

        std::deque<int> opt = { 0 };
        std::vector<int> f(n + 1), g(n + 1);

        for (int i = 1; i <= n; ++i) {
            while (i - opt.front() > maxBoxes || W[i] - W[opt.front()] > maxWeight) {
                opt.pop_front();
            }

            f[i] = g[opt.front()] + neg[i] + 2;

            if (i != n) {
                g[i] = f[i] - neg[i + 1];
                while (!opt.empty() && g[i] <= g[opt.back()]) {
                    opt.pop_back();
                }
                opt.push_back(i);
            }
        }

        return f[n];


    }
};
#endif // DYNAMIC_PROGRAMMING_PRIORITY_QUEUE_METHOD


#endif // __leet_code_1687__