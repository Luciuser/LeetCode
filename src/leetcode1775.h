/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-07 10:09:50
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1775.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-07 10:55:06
 * @Editor: Bingyang Jin
 * @Description: create VOILENCE_METHOD, TIME 136ms, 41.22%, MEMORY 111.1MB and 40.54%
 */

#ifndef __leet_code_1775__
#define __leet_code_1775__

#include<iostream>
#include<vector>
#include<unordered_map>
#include<numeric>

class Solution {
public:
    int minOperations(std::vector<int>& nums1, std::vector<int>& nums2) {
        // a 的和要比 b 的和小
        std::unordered_map<int, int>a;
        std::unordered_map<int, int>b;

        int n1 = nums1.size();
        int n2 = nums2.size();
        if (!(n1 * 1 <= n2 * 6 && n1 * 6 >= n2 * 1)) {
            return -1;
        }
        
        int s1 = std::accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = std::accumulate(nums2.begin(), nums2.end(), 0);

        if (s1 < s2) {
            for (int i = 0; i < nums1.size(); i++) {
                a[nums1[i]]++;
            }
            for (int i = 0; i < nums2.size(); i++) {
                b[nums2[i]]++;
            }
        }
        else if(s1 > s2){
            for (int i = 0; i < nums1.size(); i++) {
                b[nums1[i]]++;
            }
            for (int i = 0; i < nums2.size(); i++) {
                a[nums2[i]]++;
            }
            int temp = s1;
            s1 = s2;
            s2 = temp;
        }
        else {
            return 0;
        }

        // 进行 123 和 654 的转换
        int result = 0;
        for (int i = 0; i < 5; i++) {
            int changeMax = b[6 - i] + a[1 + i];
            if (s1 + (5 - i) * changeMax >= s2) {
                int temp = (s2 - s1) / (5 - i);
                if ((s2 - s1) % (5 - i) != 0) {
                    temp++;
                }
                result += temp;
                break;
            }
            s1 += (5 - i) * changeMax;
            result += changeMax;
        }

        return result;
    }
};

#endif // __leet_code_1775__