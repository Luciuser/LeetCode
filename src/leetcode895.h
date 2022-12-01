/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-30 00:11:49
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode895.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-30 10:05:24
 * @Editor: Bingyang Jin
 * @Description: create MAP_SET_METHOD, TIME 1200ms, 5.06%, MEMORY 100.5MB and 19.31%
 */

 /*
 * @EditTime: 2022-11-30 10:20:30
 * @Editor: Bingyang Jin
 * @Description: create HASH_STACK_METHOD, TIME 196ms, 72.87%, MEMORY 97.7MB and 43.90%
 */

#ifndef __leet_code_895__
#define __leet_code_895__

#include<iostream>
#include<unordered_map>
#include<set>
#include<stack>

//#define MAP_SET_METHOD // 用 map 和 set 分别进行存储和排序，push 和 pop 均为 O(logn)，TIME 1200ms, 5.06%, MEMORY 100.5MB and 19.31%
#define HASH_STACK_METHOD // 用 map 映射一个 stack，push 和 pop 均为 O(1)，TIME 196ms, 72.87%, MEMORY 97.7MB and 43.90%

#ifdef MAP_SET_METHOD
class FreqStack {
public:
    FreqStack() {
        number2time.clear();
        number_time.clear();
    }

    void push(int val) {
        auto iter = number_time.find(std::pair<int, int>(val, number2time[val]));
        if (iter != number_time.end()) {
            number_time.erase(iter);
        }
        number2time[val]++;
        number_time.emplace(std::pair<int, int>(val, number2time[val]));

        freqVec.push_back(val);
    }

    int pop() {
        auto max_time_pair = number_time.begin();
        int times = (*max_time_pair).second;

        int n = freqVec.size();
        for (int i = 0; i < n; i++) {
            if (freqVec[n - i - 1] != -1) {
                int key = freqVec[n - i - 1];
                if (number2time[key] == times) {
                    // 找到了，进行删除
                    auto iter = number_time.find(std::pair<int, int>(key, times));
                    number_time.erase(iter);
                    number2time[key]--;
                    number_time.emplace(std::pair<int, int>(key, times - 1));
                    freqVec[n - i - 1] = -1;
                    return key;
                }
            }
        }

        return -1;
    }

private:

    template<typename T>
    struct PairCompareStruct
    {
        bool operator()(const std::pair<T, T>& a, const std::pair<T, T>& b) const {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            else {
                return a.first < b.first;
            }
        }
    };

    std::unordered_map<int, int> number2time; // 每个数字出现的频次
    std::set<std::pair<int, int>, PairCompareStruct<int>> number_time; // 每个数字及出现频次按规定排序

    std::vector<int> freqVec;
};
#endif // MAP_SET_METHOD

#ifdef HASH_STACK_METHOD
class FreqStack {
public:
    FreqStack() {
        number2time.clear();
        time2number.clear();
        maxTime = 0;
    }

    void push(int val) {
        number2time[val]++;
        int time = number2time[val];
        time2number[time].push(val);
        if (time > maxTime) {
            maxTime = time;
        }
    }

    int pop() {
        int number = time2number[maxTime].top();
        number2time[number]--;
        time2number[maxTime].pop();
        if (time2number[maxTime].size() == 0) {
            maxTime--;
        }
        return number;
    }

private:
    
    std::unordered_map<int, int> number2time;
    std::unordered_map<int, std::stack<int>> time2number;
    int maxTime;
};
#endif // HASH_STACK_METHOD

#endif // __leet_code_895__