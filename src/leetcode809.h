/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-25 00:09:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode809.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-25 00:35:33
 * @Editor: Bingyang Jin
 * @Description: create MULTIPLE_POINTER_METHOD, TIME 4ms, 87.07%, MEMORY 7.3MB and 77.55%
 */

#ifndef __leet_code_809__
#define __leet_code_809__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int expressiveWords(std::string s, std::vector<std::string>& words) {

        //int i = 0;
        s += '0';
        int n = s.size();
        std::vector<int> position(words.size(), 0);

        int before = 0;
        char c_before = s[0];
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c != c_before) {
                // 对某组字母，查看所有 words 是否能构成
                int length = i - before;

                for (int j = 0; j < words.size(); j++) {
                    if (position[j] == -1) {
                        // 该组已经无法组成，无需再搜索
                        continue;
                    }

                    int word_before = position[j];
                    for (; position[j] < words[j].size(); position[j]++) {
                        if (words[j][position[j]] != c_before) {
                            break;
                        }
                    }
                    int word_length = position[j] - word_before;
                    if (word_length == 0 || word_length > length) {
                        position[j] = -1;
                    }
                    if (word_length != length) {
                        if (length < 3) {
                            position[j] = -1;
                        }
                    }
                }

                before = i;
                c_before = c;
            }
        }

        int sum = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] != -1 && position[i] == words[i].size()) {
                sum++;
            }
        }

        return sum;
    }
};

#endif // __leet_code_809__