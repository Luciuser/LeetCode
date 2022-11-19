/*
 * @Author: Bingyang Jin
 * @Date: 2022-11-11 09:25:58
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode641.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-11-11 09:45:37
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 24ms, 73.12%, MEMORY 16.6MB and 10.32%
 */

#ifndef __leet_code_641__
#define __leet_code_641__

class Node {
public:
    Node(int val) {
        value = val;
        before = nullptr;
        next = nullptr;
    }

    int value = 0;
    Node* before;
    Node* next;
};

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        front = nullptr;
        last = nullptr;
        length = 0;
        lengthMax = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        Node* temp = new Node(value);
        if (isEmpty()) {
            front = temp;
            last = temp;
        }
        else {
            temp->next = front;
            front->before = temp;
            front = temp;
        }

        length++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        Node* temp = new Node(value);
        if (isEmpty()) {
            front = temp;
            last = temp;
        }
        else {
            last->next = temp;
            temp->before = last;
            last = temp;
        }
        length++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        length--;

        if (length == 0) {
            delete front;
            front = nullptr;
            last = nullptr;
        }
        else {
            Node* temp = front->next;
            delete front;
            front = temp;
        }

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        length--;

        if (length == 0) {
            delete last;
            front = nullptr;
            last = nullptr;
        }
        else {
            Node* temp = last->before;
            delete last;
            last = temp;
        }

        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return front->value;
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return last->value;
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == lengthMax;
    }

private:
    Node* front;
    Node* last;
    int length;
    int lengthMax;
};

#endif // __leet_code_641__