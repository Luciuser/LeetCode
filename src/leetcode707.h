/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-23 13:57:02
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode707.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-22 15:00:34
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 44ms, 31.22%, MEMORY 19.4MB and 5.06%
 */

#ifndef __leet_code_707__
#define __leet_code_707__

class Node {
public:
	Node(int _value) { value = _value; next = nullptr; before = nullptr; }
	Node(int _value, Node *_before, Node* _next) { value = _value, before = _before; next = _next; }
	int value;
	Node *next;
	Node *before;
};

class MyLinkedList {
public:
	MyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	int get(int index) {
		Node *temp = head;
		while (index > 0) {
			if (temp == nullptr) {
				return -1;
			}
			index--;
			temp = temp->next;
		}
		if (temp == nullptr) {
			return -1;
		}
		else {
			return temp->value;
		}
	}

	void addAtHead(int val) {
		if (head == nullptr) {
			head = new Node(val);
			tail = head;
		}
		else {
			Node *newNode = new Node(val);
			newNode->next = head;
			head->before = newNode;
			head = newNode;
		}
	}

	void addAtTail(int val) {
		if (tail == nullptr) {
			tail = new Node(val);
			head = tail;
		}
		else {
			Node *newNode = new Node(val);
			newNode->before = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void addAtIndex(int index, int val) {
		if (index <= 0) {
			addAtHead(val);
			return;
		}
		Node *father = head;
		if (father == nullptr) {
			return;
		}
		Node *temp = father->next;
		while (index >= 2) {
			if (temp == nullptr) {
				return;
			}
			index--;
			father = temp;
			temp = temp->next;
		}

		Node *newNode = new Node(val);
		father->next = newNode;
		newNode->before = father;
		if (temp != nullptr) {
			temp->before = newNode;
			newNode->next = temp;
		}
		else {
			tail = newNode;
		}
		return;
	}

	void deleteAtIndex(int index) {
		if (index < 0) {
			return;
		}
		Node *temp = head;
		while (index > 0) {
			if (temp == nullptr) {
				return;
			}
			index--;
			temp = temp->next;
		}

		if (temp != nullptr) {
			Node *father = temp->before;
			Node *next = temp->next;
			if (father != nullptr) {
				father->next = next;
			}
			else {
				head = next;
			}
			if (next != nullptr) {
				next->before = father;
			}
			else {
				tail = father;
			}
			// delete[]temp;
		}

		return;
	}

private:
	Node *head;
	Node *tail;
};

#endif // __leet_code_707__