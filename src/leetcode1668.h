/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-03 12:10:55
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1668.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-03 12:41:09
 * @Editor: Bingyang Jin
 * @Description: create STRING_FIND_METHOD, TIME 0ms, 100.00%, MEMORY 6.3MB and 7.88%
 */

#ifndef __leet_code_1668__
#define __leet_code_1668__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

//#define STRING_FIND_METHOD // 使用 c++ string 提供的 find 函数，TIME 0ms, 100.00%, MEMORY 6.3MB and 7.88%
#define DYNAMIC_PROGRAMMING_METHOD // 动态规划，TIME 0ms, 100.00%, MEMORY 6.3MB and 7.88%

#ifdef STRING_FIND_METHOD
class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {

        //std::vector<size_t> position;
        std::unordered_map<size_t, int> position;
        auto index = sequence.find(word);
        if (index == std::string::npos) {
            return 0;
        }
        while (index != std::string::npos) {
            position[index] = 1;
            index = sequence.find(word, index + 1);
        }

        int k = 0;
        int temp = 0;
        int n = word.size();
        for (auto iter = position.begin(); iter != position.end(); iter++) {
            if ((*iter).second == 1) {
                temp = 1;
                int add = n;
                while (true) {
                    if (position.count((*iter).first + add) == 0) {
                        break;
                    }
                    else {
                        temp++;
                        add += n;
                        position[(*iter).first + add] = 0;
                    }
                }
                k = k < temp ? temp : k;
            }
        }

        return k;
    }
};
#endif // STRING_FIND_METHOD

#ifdef DYNAMIC_PROGRAMMING_METHOD
class Solution {
public:
    int maxRepeating(std::string sequence, std::string word) {

        int max = 0;
        int n = sequence.size();
        int m = word.size();
        std::vector<int> dp(n, 0);
        for (int i = m - 1; i < n; i++) {
            bool isRight = true;
            for (int j = 0; j < m; j++) {
                if (sequence[i - m + 1 + j] != word[j]) {
                    isRight = false;
                    break;
                }
            }
            if (isRight) {
                dp[i] = i - m >= 0 ? dp[i - m] + 1 : 1;
                max = dp[i] > max ? dp[i] : max;
            }
        }

        return max;
    }
};
#endif // STRING_FIND_METHOD


#endif // __leet_code_1668__