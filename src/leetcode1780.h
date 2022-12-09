/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-09 09:38:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1780.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-08 10:51:41
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 0ms, 100.00%, MEMORY 5.8MB and 68.69%
 */

#ifndef __leet_code_1780__
#define __leet_code_1780__

class Solution {
public:

    bool dfs(int n, int time) {
        if (n == 1) {
            return true;
        }
        int sum = 1;
        for (int i = 1; i <= time; i++) {
            sum *= 3;
            if (sum >= n) {
                if (sum == n) {
                    return true;
                }
                sum /= 3;
                int temp = n - sum;
                if (temp >= sum) {
                    return false;
                }

                return dfs(temp, i - 1);
            }
        }

        return false;
    }

    bool checkPowersOfThree(int n) {
        return dfs(n, 15);
    }
};

#endif // __leet_code_1780__