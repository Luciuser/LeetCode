/*
 * @Author: Bingyang Jin
 * @Date: 2023-04-01 14:07:31
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1039.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-04-01 14:51:22
 * @Editor: Bingyang Jin
 * @Description: create BINARY_METHOD, TIME 8ms, 20.49%, MEMORY 10.8MB and 25.92%
 */

#ifndef __leet_code_1039_h__
#define __leet_code_1039_h__

#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    int minScoreTriangulation(std::vector<int>& values) {
        
        // 建立链表和vec来存储每个点的上一个点和下一个点
        int n = values.size();
        std::vector<Node*>nodes(n, new Node());
        nodes[0]->value_ = values[0];
        nodes[0]->before_ = nodes[n-1];
        nodes[0]->next_ = nodes[1];
        nodes[n - 1]->value_ = values[n - 1];
        nodes[n - 1]->before_ = nodes[n - 2];
        nodes[n - 1]->next_ = nodes[0];
        for (int i = 1; i < n - 1; i++) {
            nodes[i]->value_ = values[i];
            nodes[i]->before_ = nodes[i - 1];
            nodes[i]->next_ = nodes[i];
        }
         
        // 贪心法，维护一个优先队列
        int deleteNum = 0; // 删除的点的数量
        std::priority_queue<Node*, std::vector<Node*>, NodeCompare> pq;

        //std::vector<int> max(n);
        //for (int i = 0; i < n; i++) {
        //    max[i] = i;
        //}
        //std::sort(max.begin(), max.end(), [&](int a, int b)) {
        //    return values[a] > values[b];
        //};


    }

private:
    class Node {
    public:
        Node() {
            value_ = -1;
        }
        Node(int value) {
            value_ = value;
        }
        int value_;
        Node* before_;
        Node* next_;
    };

    struct NodeCompare {
        bool operator()(const Node& a, const Node& b) const {
            if (a.value_ != b.value_) {
                return a.value_ > b.value_;
            }
            else {
                return a.before_->value_ * a.next_->value_ < b.before_->value_* b.next_->value_;
            }
        }
    };
};

#endif // __leet_code_1039_h__