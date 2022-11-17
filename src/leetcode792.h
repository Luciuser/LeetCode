/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-17 14:48:39
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode792.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-17 15:54:04
 * @Editor: Bingyang Jin
 * @Description: create NEXT_POSITION_METHOD, TIME 132ms, 22.09%, MEMORY 81.2MB and 48.47%
 */

 /*
 * @EditTime: 2022-11-17 16:09:32
 * @Editor: Bingyang Jin
 * @Description: create MULTIPLE_POINTER_METHOD, TIME 136ms, 80.00%, MEMORY 45.3MB and 71.34%
 */


#ifndef __leet_code_792__
#define __leet_code_792__

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>

//#define NEXT_POSITION_METHOD // 记录每个位置的后面第一次出现某个字符的索引，TIME 132ms, 22.09%, MEMORY 81.2MB and 48.47%
#define MULTIPLE_POINTER_METHOD // 多指针，TIME 136ms, 80.00%, MEMORY 45.3MB and 71.34%

#ifdef NEXT_POSITION_METHOD
class Solution {
public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
        std::unordered_map<char, int> character;
        std::vector<std::vector<int>> next(s.size() + 1, std::vector<int>(26, -1));
        for (int i = s.size() - 1; i >= 0; i--) {
            character[s[i]] = i;
            for (int j = 0; j < 26; j++) {
                if (character.count('a' + j) != 0) {
                    next[i][j] = character['a' + j];
                }
            }
        }

        int result = 0;
        for (int i = 0; i < words.size(); i++) {
            bool isRight = true;
            int temp = 0;
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                if (character.count(c) == 0) {
                    isRight = false;
                    break;
                }

                if (next[temp][c - 'a'] == -1) {
                    isRight = false;
                    break;
                }
                else {
                    temp = next[temp][c - 'a'] + 1;
                }

            }
            if (isRight) {
                result++;
            }
        }

        return result;
    }
};
#endif // NEXT_POSITION_METHOD

#ifdef MULTIPLE_POINTER_METHOD
class Solution {
public:
    int numMatchingSubseq(std::string s, std::vector<std::string>& words) {
        std::vector<std::queue<std::pair<int, int>>> q(26); // 当前需要做的每个指针，所指向第几个 words 的第几个字符，最开始的 vector 表示该字符
        for (int i = 0; i < words.size(); i++) {
            q[words[i][0] - 'a'].emplace(std::pair<int, int>(i, 0));
        }

        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            auto& qu = q[s[i] - 'a'];
            int size = qu.size();
            while (size > 0) {
                std::pair<int, int> temp = qu.front();
                qu.pop();
                int i = temp.first;
                int j = temp.second;
                if (j + 1 == words[i].size()) {
                    result++;
                }
                else {
                    j++;
                    char c = words[i][j];
                    q[c-'a'].emplace(std::pair<int, int>(i, j));
                }
                size--;
            }
        }

        return result;
    }
};
#endif // MULTIPLE_POINTER_METHOD


#endif // __leet_code_792__