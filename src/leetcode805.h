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

    // ���� -1����ǰ�����ƽ��ֵС��Ҫ��ֵ
    // ���� 0����ǰ�����ƽ��ֵ����Ҫ��ֵ
    // ���� 1����ǰ�����ƽ��ֵ����Ҫ��ֵ
    int average_equal() {
        // �ж� sum_a/na ? sum/n �����⸡��������жϣ����Ը�Ϊ sum_a * n ? sum * na
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

        // ���м�֦�жϣ����� nums �������Ǵ�С�������ÿ���� array_a �����һ��ֵ�������ƽ��ֵ
        // ��֦���ǣ�����ǰ array_a ��ƽ��ֵ�Ѿ�������ƽ��ֵ��ȣ�ֱ�ӷ��� true�������������ƽ��ֵ��ֱ�ӷ��� false
        int success = average_equal();
        if ( success == 0) {
            return true;
        }
        else if (success == 1) {
            return false;
        }

        // �ݹ飬�жϸ����Ƿ���Էŵ� array_a ��
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

        // ���մ�С�����˳�򹹽�
        std::sort(nums.begin(), nums.end(), [=](int a, int b) {
            return a < b;
        });

        array_a.emplace(nums[0]);
        sum_a += nums[0];
        return dfs(nums, 1);
    }

private:
    // a ����ѡ�������
    std::stack<int> array_a;

    // a ������ܺ�
    int sum_a = 0;

    // ��ֵ�������ָ���
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
//        // �����������ˣ��жϴ�ʱ�Ƿ�ɹ�
//        if (remain.size() == 0) {
//            return average_a == average_b;
//        }
//
//        // ���м�֦�жϣ����� remain �������Ǵ�С���������ÿ���� array_a �� array_b �����һ��ֵ�������ƽ��ֵ
//        // ��֦���ǣ���ʹ����ʣ�������ͳһ����ƽ��ֵ��С��һ���к󣬸���ƽ��ֵ��Ȼ��С����ֱ���˳�
//        if ( (average_a < average_b && 1.0 * (sum - nb * average_b) / (n - nb) < average_b )|| 
//            (average_a > average_b && 1.0 * (sum - na * average_a) / (n - na) < average_a)
//            ) {
//            return false;
//        }
//
//        // �ݹ飬��ǰ�������Էŵ� array_a��Ҳ���Էŵ� arry_b ��
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
//        // ���մ�С�����˳�򹹽�
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
//    // �������鼰ʣ��������
//    std::stack<int> array_a;
//    std::stack<int> array_b;
//    std::stack<int> remain;
//
//    // a��b ��������ܺ�
//    int sum_a = 0;
//    int sum_b = 0;
//
//    // ��ֵ�������ָ���
//    int n = 0;
//    int sum = 0;
//
//    int time = 0;
//};

#endif // __leet_code_805__