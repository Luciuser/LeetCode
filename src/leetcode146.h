/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-14 21:12:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode146.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-14 21:35:05
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 66.84%, MEMORY 7.4MB and 82.14%
 */

#ifndef __leet_code_146_h__
#define __leet_code_146_h__

#include<iostream>
#include<queue>
#include<unordered_map>

//#define NORMAL_METHOD, TIME 424ms, 29.00%, MEMORY 160.3MB and 95.00%
#define LINK_NODE_METHOD, TIME 396ms, 45.21%, MEMORY 161MB and 70.87%

#ifdef LINK_NODE_METHOD
class LRUCache {
public:
    LRUCache(int capacity) {
        top = new Node(-1, -1);
        tail = new Node(-2, -2);
        top->next = tail;
        tail->before = top;
        capacity_max_ = capacity;
        capacity_ = 0;
    }

    int get(int key) {
        if (key_node_.count(key) == 0) {
            return -1;
        }
        else {
            if (top->next != key_node_[key]) {
                // 将对应节点移动到头部
                key_node_[key]->before->next = key_node_[key]->next;
                key_node_[key]->next->before = key_node_[key]->before;

                top->next->before = key_node_[key];
                key_node_[key]->next = top->next;
                key_node_[key]->before = top;
                top->next = key_node_[key];
            }
            return key_node_[key]->value_;
        }
    }

    void put(int key, int value) {
        if (key_node_.count(key) == 0) {
            // 在头部增加一个新节点
            Node* new_node = new Node(key, value);
            key_node_[key] = new_node;
            top->next->before = new_node;
            new_node->next = top->next;
            new_node->before = top;
            top->next = new_node;

            capacity_++;
            if (capacity_ > capacity_max_) {
                capacity_--;
                // 删除尾部节点
                Node* del_node = tail->before;
                del_node->before->next = tail;
                tail->before = del_node->before;

                key_node_.erase(del_node->key_);
                delete del_node;
            }
        }
        else {
            key_node_[key]->value_ = value;

            if (top->next != key_node_[key]) {
                // 将对应节点移动到头部
                key_node_[key]->before->next = key_node_[key]->next;
                key_node_[key]->next->before = key_node_[key]->before;

                top->next->before = key_node_[key];
                key_node_[key]->next = top->next;
                key_node_[key]->before = top;
                top->next = key_node_[key];
            }
        }
    }
private:

    class Node {
    public:
        Node(int key, int value) {
            key_ = key;
            value_ = value;
            before = nullptr;
            next = nullptr;
        }

        int key_;
        int value_;
        Node* before;
        Node* next;
    };

    std::unordered_map<int, Node*> key_node_;
    Node* top;
    Node* tail;
    int capacity_max_;
    int capacity_;
};
#endif // LINK_NODE_METHOD

#ifdef NORMAL_METHOD
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_max_ = capacity;
        capacity_ = 0;
    }

    int get(int key) {
        if (key_value_.count(key) == 0) {
            return -1;
        }
        else {
            keys_.emplace(key);
            key_frequence[key]++;
            return key_value_[key];
        }
    }

    void put(int key, int value) {
        if (key_value_.count(key) == 0) {
            keys_.emplace(key);
            key_frequence[key]++;
            key_value_[key] = value;
            capacity_++;
            if (capacity_ > capacity_max_) {
                capacity_--;
                while (true) {
                    int top = keys_.front();
                    keys_.pop();
                    key_frequence[top]--;

                    if (key_frequence[top] == 0) {
                        key_value_.erase(top);
                        break;
                    }
                }
            }
        }
        else {
            keys_.emplace(key);
            key_frequence[key]++;
            key_value_[key] = value;
        }
    }
private:
    std::unordered_map<int, int> key_value_;
    std::unordered_map<int, int> key_frequence;
    std::queue<int> keys_;
    int capacity_max_;
    int capacity_;

};
#endif // NORMAL_METHOD

#endif // __leet_code_146_h__