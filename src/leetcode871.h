/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-29 14:44:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode871.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-29 16:01:18
 * @Editor: Bingyang Jin
 * @Description: create GREEDY_METHOD, TIME 32ms, 42.00%, MEMORY 15.8MB and 32.17%
 */

#ifndef __leet_code_871__
#define __leet_code_871__

#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:

    int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& stations) {
        std::priority_queue<int, std::vector<int>> pq;
        int start = 0;
        int time = 0;
        for (int i = 0; i < stations.size(); i++) {
            // 判断能否直接达到目的地
            if (startFuel >= (target - start)) {
                return time;
            }

            // 判断能否达到下一个加油站
            if (stations[i][0] < target) {
                startFuel = startFuel - (stations[i][0] - start);

                // 如果不能到达下一个加油站，则需要在前面的加油站进行加油
                while (startFuel < 0) {
                    if (pq.size() == 0) {
                        // 前面的加油站全部加过了，直接返回 -1
                        return -1;
                    }
                    startFuel += pq.top();
                    pq.pop();
                    time++;
                }

                // 能到达下一个加油站
                pq.emplace(stations[i][1]);
                start = stations[i][0];
            }
            else {
                break;
            }
        }

        startFuel = startFuel - (target - start);

        // 如果不能到达目的地，则需要在前面的加油站进行加油
        while (startFuel < 0) {
            if (pq.size() == 0) {
                // 前面的加油站全部加过了，直接返回 -1
                return -1;
            }
            startFuel += pq.top();
            pq.pop();
            time++;
        }

        return time;

    }
};

#endif // __leet_code_871__