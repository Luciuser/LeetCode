#ifndef __leet_code_427__
#define __leet_code_427__

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

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

	Node* construct(vector<vector<int>>& grid) {
		Node *crtNode = new Node();

		// decide whether all the 
		bool isSame = true;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size() - 1; j++) {
				// std::cout << grid[i][j] << std::endl;
				if (grid[i][j] != grid[i][j + 1]) {
					isSame = false;
					break;
				}
			}
			if (isSame == false) {
				break;
			}
		}
		if (isSame) {
			for (int i = 0; i < grid.size() - 1; i++) {
				if (grid[i][0] != grid[i + 1][0]) {
					isSame = false;
					break;
				}
			}
		}

		if (isSame) {
			// it is leaf node
			crtNode->isLeaf = true;
			crtNode->val = grid[0][0];
		}
		else {
			// it is NOT leaf nod
			crtNode->isLeaf = false;
			crtNode->val = grid[0][0];

			vector<vector<int>> topLeftGrid;
			vector<vector<int>> topRightGrid;
			vector<vector<int>> bottomLeftGrid;
			vector<vector<int>> bottomRightGrid;

			int gridN = grid.size();
			for (int i = 0; i < gridN; i++) {
				vector<int> tempLeft;
				vector<int> tempRight;
				for (int j = 0; j < gridN; j++) {
					if (j < gridN / 2) {
						tempLeft.push_back(grid[i][j]);
					}
					else {
						tempRight.push_back(grid[i][j]);
					}
				}
				if (i < gridN / 2) {
					topLeftGrid.push_back(tempLeft);
					topRightGrid.push_back(tempRight);
				}
				else {
					bottomLeftGrid.push_back(tempLeft);
					bottomRightGrid.push_back(tempRight);
				}
			}

			crtNode->topLeft = construct(topLeftGrid);
			crtNode->topRight = construct(topRightGrid);
			crtNode->bottomLeft = construct(bottomLeftGrid);
			crtNode->bottomRight = construct(bottomRightGrid);
		}

		return crtNode;
	}
};

#endif // !__leet_code_427__