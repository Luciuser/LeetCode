/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-04 10:12:57
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1000.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-01 12:45:22
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 20ms, 82.01%, MEMORY 24MB and 87.77%
 */

#ifndef __leet_code_1000_h__
#define __leet_code_1000_h__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    int mergeStones(std::vector<int>& stones, int k) {
        
        del.resize(stones.size());
        for (int i = 0; i < stones.size(); i++) {
            del[i] = 0;
        }

        DFS(stones, k, 0);

        return can_do ? min : -1;
    }

private:
    int DFS(std::vector<int>& stones, int k, int result) {

        if (min < result) {
            return -1;
        }

        std::queue<int> idex;
        
        int right = 0;
        int sum = 0;
        for (; right < stones.size(); right++) {
            if (idex.size() == k) {
                break;
            }
            if (del[right] == 0) {
                sum += stones[right];
                idex.push(right);
                del[right] = 1;
            }
        }
        if (idex.size() == k) {
            while (right <= stones.size()) {
                int left = idex.front();
                idex.pop();
                int temp = stones[left];
                stones[left] = sum;
                del[left] = 0;

                if (DFS(stones, k, result + sum) != -1) {
                    min = min < result + sum ? min : result + sum;
                    can_do = true;
                }

                stones[left] = temp;
                right++;
                if (right < stones.size()) {
                    sum -= stones[left];
                    sum += stones[right];
                    del[right] = 1;
                    idex.push(right);
                }
            }
        }
        else if (idex.size() == 1) {
            return 0;
        }
        else {
            return -1;
        }

        return 0;
    }

    std::vector<int> del;
    bool can_do = false;
    int min = std::numeric_limits<int>::max();
};

#endif // __leet_code_1000_h__