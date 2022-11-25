/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-25 10:01:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode768.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-25 10:33:19
 * @Editor: Bingyang Jin
 * @Description: create MAX_MIN_METHOD, TIME 12ms, 50.23%, MEMORY 12.1MB and 28.32%
 */

 /*
 * @EditTime: 2022-11-25 11:11:07
 * @Editor: Bingyang Jin
 * @Description: create MONOTONE_STACK_METHOD, TIME 8ms, 84.95%, MEMORY 11.9MB and 70.96%
 */

#ifndef __leet_code_768__
#define __leet_code_768__

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

//#define MAX_MIN_METHOD
#define MONOTONE_STACK_METHOD

#ifdef MAX_MIN_METHOD
class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {

        // 找到每个切口位置，左侧的最大值和右侧的最小值
        int n = arr.size();
        std::vector<int> max(n - 1, 0);
        std::vector<int> min(n - 1, 0);

        int temp = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > temp) {
                temp = arr[i];
            }
            max[i] = temp;
        }
        temp = std::numeric_limits<int>::max();
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] < temp) {
                temp = arr[i];
            }
            min[i - 1] = temp;
        }

        int sum = 1;
        for (int i = 0; i < n - 1; i++) {
            if (max[i] <= min[i]) {
                sum++;
            }
        }

        return sum;
    }
};
#endif // MAX_MIN_METHOD

#ifdef MONOTONE_STACK_METHOD
class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {

        std::stack<int> st;

        st.push(arr[0]);
        for (int i = 1; i < arr.size(); i++) {
            int max = arr[i];
            while (true) {
                if (st.size() == 0) {
                    st.push(max);
                    break;
                }
                int temp = st.top();
                if (arr[i] >= temp) {
                    st.push(max);
                    break;
                }
                else {
                    if (temp > max) {
                        max = temp;
                    }
                    st.pop();
                }
            }
        }

        return st.size();
    }
};
#endif // MONOTONE_STACK_METHOD

#endif // __leet_code_768__