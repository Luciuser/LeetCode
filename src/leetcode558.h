/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-30 19:30:15
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode558.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-30 19:45:16
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 20ms, 66.20%, MEMORY 14.2MB and 97.18%
 */

#ifndef __leet_code_558__
#define __leet_code_558__

#include<iostream>

// Definition for a QuadTree node.
class Node {
public:
	 bool val;
	 bool isLeaf;
	 Node* topLeft;
	 Node* topRight;
	 Node* bottomLeft;
	 Node* bottomRight;

	 Node() {
		 val = false;
		 isLeaf = false;
		 topLeft = NULL;
		 topRight = NULL;
		 bottomLeft = NULL;
		 bottomRight = NULL;
	 }

	 Node(bool _val, bool _isLeaf) {
		 val = _val;
		 isLeaf = _isLeaf;
		 topLeft = NULL;
		 topRight = NULL;
		 bottomLeft = NULL;
		 bottomRight = NULL;
	 }

	 Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
		 val = _val;
		 isLeaf = _isLeaf;
		 topLeft = _topLeft;
		 topRight = _topRight;
		 bottomLeft = _bottomLeft;
		 bottomRight = _bottomRight;
	 }
 };
 

class Solution {
public:
	Node* intersect(Node* quadTree1, Node* quadTree2) {

		if (quadTree1->isLeaf == true) {
			if (quadTree2->isLeaf == true) {
				quadTree1->val = quadTree1->val || quadTree2->val;
				return quadTree1;
			}
			else {
				if (quadTree1->val == true) {
					return quadTree1;
				}
				else {
					return quadTree2;
				}
			}
		}
		else{
			if (quadTree2->isLeaf == true) {
				if (quadTree2->val == true) {
					return quadTree2;
				}
				else {
					return quadTree1;
				}
			}
			else {
				quadTree1->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
				quadTree1->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
				quadTree1->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
				quadTree1->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
				if (quadTree1->topLeft->isLeaf == true && quadTree1->topRight->isLeaf == true
					&& quadTree1->bottomLeft->isLeaf == true && quadTree1->bottomRight->isLeaf == true) {
					if (quadTree1->topLeft->val == true && quadTree1->topRight->val == true
						&& quadTree1->bottomLeft->val == true && quadTree1->bottomRight->val == true) {
						quadTree1->isLeaf = true;
						quadTree1->val = true;
						quadTree1->topLeft = NULL;
						quadTree1->topRight = NULL;
						quadTree1->bottomLeft = NULL;
						quadTree1->bottomRight = NULL;
					}
					else if (quadTree1->topLeft->val == false && quadTree1->topRight->val == false
						&& quadTree1->bottomLeft->val == false && quadTree1->bottomRight->val == false) {
						quadTree1->isLeaf = true;
						quadTree1->val = false;
						quadTree1->topLeft = NULL;
						quadTree1->topRight = NULL;
						quadTree1->bottomLeft = NULL;
						quadTree1->bottomRight = NULL;
					}
				}
				return quadTree1;
			}
		}

	}
};

#endif // __leet_code_558__