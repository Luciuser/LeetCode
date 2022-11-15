/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-014 10:40:30
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode805.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-08 09:55:00
 * @Editor: Bingyang Jin
 * @Description: create HASH_METHOD, TIME 64ms, 26.06%, MEMORY 29.5MB and 13.56%
 */

#ifndef __leet_code_805__
#define __leet_code_805__

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

class Solution {
public:

    // 返回 -1，当前分组的平均值小于要求值
    // 返回 0，当前分组的平均值等于要求值
    // 返回 1，当前分组的平均值大于要求值
    int average_equal() {
        // 判断 sum_a/na ? sum/n ，避免浮点数相等判断，可以改为 sum_a * n ? sum * na
        int left = sum_a * n;
        int right = sum * array_a.size();
        if (left == right) {
            return 0;
        } 
        else if (left < right) {
            return -1;
        }
        else {
            return 1;
        }
    }

    bool dfs(std::vector<int>& nums, int index) {

        int na = array_a.size();
        if (na == n) {
            return false;
        }

        if (index == n) {
            return average_equal() == 0;
        }

        // 进行剪枝判断，由于 nums 的数字是从小到大，因此每次往 array_a 中添加一个值都会提高平均值
        // 剪枝则是，若当前 array_a 的平均值已经与需求平均值相等，直接返回 true，如果大于需求平均值，直接返回 false
        int success = average_equal();
        if ( success == 0) {
            return true;
        }
        else if (success == 1) {
            return false;
        }

        // 递归，判断该数是否可以放到 array_a 中
        int current = nums[index];

        array_a.push(current);
        sum_a += current;
        if (dfs(nums, index+1)) {
            return true;
        }
        sum_a -= current;
        array_a.pop();

        if (dfs(nums, index + 1)) {
            return true;
        }

        return false;
    }

    bool splitArraySameAverage(std::vector<int>& nums) {

        sum = 0;
        n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // 按照从小到大的顺序构建
        std::sort(nums.begin(), nums.end(), [=](int a, int b) {
            return a < b;
        });

        array_a.emplace(nums[0]);
        sum_a += nums[0];
        return dfs(nums, 1);
    }

private:
    // a 数组选择的数字
    std::stack<int> array_a;

    // a 数组的总和
    int sum_a = 0;

    // 总值和总数字个数
    int n = 0;
    int sum = 0;
};

//class Solution {
//public:
//
//    void print() {
//        std::cout << "time is: " << time << std::endl;
//        time++;
//        std::cout << "a size is: " << array_a.size() << std::endl;
//        std::cout << "b size is: " << array_b.size() << std::endl;
//        std::cout << "remain size is: " << remain.size() << std::endl;
//        
//        std::cout << "a: ";
//        std::stack<int> temp_a = array_a;
//        while (!temp_a.empty()) {
//            int temp = temp_a.top();
//            temp_a.pop();
//            std::cout << temp << " ";
//        }
//        std::cout << std::endl;
//        std::cout << "b: ";
//        std::stack<int> temp_b = array_b;
//        while (!temp_b.empty()) {
//            int temp = temp_b.top();
//            temp_b.pop();
//            std::cout << temp << " ";
//        }
//        std::cout << std::endl;
//
//
//    }
//
//    bool dfs() {
//
//        //print();
//
//        int na = array_a.size();
//        int nb = array_b.size();
//        double average_a = na == 0? 0: sum_a * 1.0 / na;
//        double average_b = nb == 0? 0: sum_b * 1.0 / nb;
//
//        // 所有数放完了，判断此时是否成功
//        if (remain.size() == 0) {
//            return average_a == average_b;
//        }
//
//        // 进行剪枝判断，由于 remain 的数字是从小到到，因此每次往 array_a 或 array_b 中添加一个值都会提高平均值
//        // 剪枝则是，即使所有剩余的数都统一塞到平均值更小的一组中后，该组平均值依然更小，则直接退出
//        if ( (average_a < average_b && 1.0 * (sum - nb * average_b) / (n - nb) < average_b )|| 
//            (average_a > average_b && 1.0 * (sum - na * average_a) / (n - na) < average_a)
//            ) {
//            return false;
//        }
//
//        // 递归，当前该数可以放到 array_a，也可以放到 arry_b 中
//        int current = remain.top();
//        remain.pop();
//
//        array_a.push(current);
//        sum_a += current;
//        if (dfs()) {
//            return true;
//        }
//        sum_a -= current;
//        array_a.pop();
//        
//        array_b.push(current);
//        sum_b+=current;
//        if (dfs()) {
//            return true;
//        }
//        sum_b -= current;
//        array_b.pop();
//
//        remain.push(current);
//
//        return false;
//    }
//
//    bool splitArraySameAverage(std::vector<int>& nums) {
//        
//        sum = 0;
//        n = nums.size();
//        for (int i = 0; i < n; i++) {
//            sum += nums[i];
//        }
//
//        // 按照从小到大的顺序构建
//        std::sort(nums.begin(), nums.end(), [=](int a, int b) {
//            return a > b;
//        });
//
//        for (int i = 0; i < n; i++) {
//            remain.push(nums[i]);
//        }
//
//        return dfs();
//    }
//
//private:
//    // 两个数组及剩余数数组
//    std::stack<int> array_a;
//    std::stack<int> array_b;
//    std::stack<int> remain;
//
//    // a、b 两数组的总和
//    int sum_a = 0;
//    int sum_b = 0;
//
//    // 总值和总数字个数
//    int n = 0;
//    int sum = 0;
//
//    int time = 0;
//};

#endif // __leet_code_805__