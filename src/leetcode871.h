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
            // �ж��ܷ�ֱ�ӴﵽĿ�ĵ�
            if (startFuel >= (target - start)) {
                return time;
            }

            // �ж��ܷ�ﵽ��һ������վ
            if (stations[i][0] < target) {
                startFuel = startFuel - (stations[i][0] - start);

                // ������ܵ�����һ������վ������Ҫ��ǰ��ļ���վ���м���
                while (startFuel < 0) {
                    if (pq.size() == 0) {
                        // ǰ��ļ���վȫ���ӹ��ˣ�ֱ�ӷ��� -1
                        return -1;
                    }
                    startFuel += pq.top();
                    pq.pop();
                    time++;
                }

                // �ܵ�����һ������վ
                pq.emplace(stations[i][1]);
                start = stations[i][0];
            }
            else {
                break;
            }
        }

        startFuel = startFuel - (target - start);

        // ������ܵ���Ŀ�ĵأ�����Ҫ��ǰ��ļ���վ���м���
        while (startFuel < 0) {
            if (pq.size() == 0) {
                // ǰ��ļ���վȫ���ӹ��ˣ�ֱ�ӷ��� -1
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