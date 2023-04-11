/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-11 12:47:44
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1041.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-11 13:17:53
 * @Editor: Bingyang Jin
 * @Description: create FOUR_TIME_METHOD, TIME 0ms, 100.00%, MEMORY 6MB and 22.15%
 */

#ifndef __leet_code_1041_h__
#define __leet_code_1041_h__

#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool isRobotBounded(std::string instructions) {
        
        // �ظ�ִ������ı飬���ı�֮�ڣ������˳���һ�������򱱷�����ʱ�жϻ�����λ�ã����ɵõ����ս��
        // ��ʼ���
        int x = 0;
        int y = 0;
        int direction = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < instructions.size(); j++) {
                getNewPositionOrDircetion(instructions[j], x, y, direction);
            }
            if (direction == 0) {
                if (x == 0 && y == 0) {
                    return true;
                }
                break;
            }
        }
        
        return false;
    }

private:
    void getNewPositionOrDircetion(const char c, int &x, int &y, int& direction) {
        switch (c)
        {
        case 'G': {
            x += direction_type[direction][0];
            y += direction_type[direction][1];
            break;
        }
        case 'L': {
            direction--;
            if (direction < 0) {
                direction += 4;
            }
            break;
        }
        case 'R': {
            direction++;
            if (direction >= 4) {
                direction -= 4;
            }
            break;
        }
        default:
            break;
        }
    }

    std::vector<std::vector<int>> direction_type = { {0,1},{1,0},{0,-1},{-1,0} }; // ��-��-��-���ĸ�����ķ�������
};

#endif // __leet_code_1041_h__