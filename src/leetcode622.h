/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-02 10:19:09
 * @FilePath: /src/leetcode622.h
  * @Description: create the file and chain table method, TIME 20 ms, MEMORY 16.3 MB
 */

#ifndef __leet_code_622__
#define __leet_code_622__

#include<iostream>
#include<vector>
#include<map>

class Node {
public:

	Node() { value = -1; next = nullptr; }
	Node(const int value) { this->value = value;  next = nullptr; }
	Node(const int value, Node *next) { this->value = value; this->next = next; }

	int value;
	Node* next;
};

class MyCircularQueue {
public:
	MyCircularQueue(int k) {
		maxLength = k;
		crtLength = 0;
		top = nullptr;
		tail = nullptr;
	}

	bool enQueue(int value) {
		if (top == nullptr) {
			Node *crtNode = new Node(value);
			crtNode->next = crtNode;
			top = crtNode;
			tail = crtNode;
			crtLength++;
		}
		else {
			if (crtLength >= maxLength) {
				return false;
			}
			Node *crtNode = new Node(value, top);
			tail->next = crtNode;
			tail = crtNode;
			crtLength++;
		}
		return true;
	}

	bool deQueue() {
		if (top == nullptr) {
			return false;
		}
		else {
			Node *crtNode = top->next;
			if (crtNode == top) {
				delete top;
				top = nullptr;
				tail = nullptr;
			}
			else {
				delete top;
				tail->next = crtNode;
				top = crtNode;
			}
			crtLength--;
		}
		return true;
	}

	int Front() {
		if (top == nullptr) {
			return -1;
		}
		return top->value;
	}

	int Rear() {
		if (tail == nullptr) {
			return -1;
		}
		return tail->value;
	}

	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		return false;
	}

	bool isFull() {
		if (crtLength >= maxLength) {
			return true;
		}
		return false;
	}

private:
	int maxLength;
	int crtLength;
	Node* top;
	Node* tail;
};

#endif // __leet_code_622__