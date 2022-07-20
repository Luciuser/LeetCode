#ifndef __leet_code_675__
#define __leet_code_675__

#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>

//#define SORT_STACK_METHODS // �Ƚ����е�����С����������ÿ��Ѱ�� begin �� end �ľ��롣Ѱ�ҷ���ͨ��ջ�� bfs �������У������bfsд����dfs �ᳬʱ��
#define SORT_GREEDY_METHODS // �Ƚ����е�����С����������ÿ��Ѱ�� begin �� end �ľ��롣Ѱ�ҷ���ͨ��ջ�� bfs �������С�

#ifdef SORT_STACK_METHODS
class Solution {
public:

	struct Room
	{
		int i;
		int j;
		int value;
		int length;
	};

	int getLengthFromAtoB(std::vector<std::vector<int>>& forest, int beginI, int beginJ, int endI, int endJ) {

		// װ�����ݽṹ O( m*n )
		std::vector<std::vector<Room>> rooms;
		for (int i = 0; i < forest.size(); i++) {
			std::vector<Room> roomColumn;
			for (int j = 0; j < forest[i].size(); j++) {
				Room crtRoom;
				crtRoom.i = i;
				crtRoom.j = j;
				crtRoom.value = forest[i][j];
				crtRoom.length = -1;
				roomColumn.push_back(crtRoom);
			}
			rooms.push_back(roomColumn);
		}

		rooms[beginI][beginJ].length = 0;
		std::stack<Room> roomStack; // ���ڼ�¼DFS��ǰ����
		roomStack.push(rooms[beginI][beginJ]);

		// װ�����ݽṹ O( m*n )
		while (roomStack.size() != 0) {
			Room crtRoom = roomStack.top();
			roomStack.pop();

			int crtI = crtRoom.i;
			int crtJ = crtRoom.j;

			// ������
			if (crtRoom.i >= 1) {
				if (rooms[crtI - 1][crtJ].value != 0) {
					if (rooms[crtI - 1][crtJ].length == -1 || rooms[crtI - 1][crtJ].length > rooms[crtI][crtJ].length + 1) {
						rooms[crtI - 1][crtJ].length = rooms[crtI][crtJ].length + 1;
						roomStack.push(rooms[crtI - 1][crtJ]);
					}
				}
			}
			// ������
			if (crtRoom.i < rooms.size() - 1) {
				if (rooms[crtI + 1][crtJ].value != 0) {
					if (rooms[crtI + 1][crtJ].length == -1 || rooms[crtI + 1][crtJ].length > rooms[crtI][crtJ].length + 1) {
						rooms[crtI + 1][crtJ].length = rooms[crtI][crtJ].length + 1;
						roomStack.push(rooms[crtI + 1][crtJ]);
					}
				}
			}
			// ������
			if (crtRoom.j >= 1) {
				if (rooms[crtI][crtJ - 1].value != 0) {
					if (rooms[crtI][crtJ - 1].length == -1 || rooms[crtI][crtJ - 1].length > rooms[crtI][crtJ].length + 1) {
						rooms[crtI][crtJ - 1].length = rooms[crtI][crtJ].length + 1;
						roomStack.push(rooms[crtI][crtJ - 1]);
					}
				}
			}
			// ������
			//std::cout << crtRoom.j << " " << rooms[0].size() - 1 << std::endl;
			if (crtRoom.j < rooms[0].size() - 1) {
				if (rooms[crtI][crtJ + 1].value != 0) {
					if (rooms[crtI][crtJ + 1].length == -1 || rooms[crtI][crtJ + 1].length > rooms[crtI][crtJ].length + 1) {
						rooms[crtI][crtJ + 1].length = rooms[crtI][crtJ].length + 1;
						roomStack.push(rooms[crtI][crtJ + 1]);
					}
				}
			}
		}

		return rooms[endI][endJ].length;
	}

	int cutOffTree(std::vector<std::vector<int>>& forest) {

		// �ҵ������յ� O(m*n)
		std::vector<Room> roomSort;
		for (int i = 0; i < forest.size(); i++) {
			for (int j = 0; j < forest[i].size(); j++) {
				Room crtRoom;
				crtRoom.i = i;
				crtRoom.j = j;
				crtRoom.value = forest[i][j];
				roomSort.push_back(crtRoom);
			}
		}

		// ���� O(m*n * log(m*n))
		std::sort(roomSort.begin(), roomSort.end(), [=](Room a, Room b) {return a.value < b.value; });

		int beginI = 0; // ��ʼ�ĸ���
		int beginJ = 0;
		int endI; // �����ĸ���
		int endJ;
		int sum = 0; // �ܺ�

		// ��ÿһ�ε�ֵ O(m*n)
		for (int i = 0; i < roomSort.size(); i++) {
			if (roomSort[i].value != 0) {
				endI = roomSort[i].i;
				endJ = roomSort[i].j;

				int length = getLengthFromAtoB(forest, beginI, beginJ, endI, endJ);

				if (length == -1) {
					// �޷�����
					return -1;
				}
				sum += length;
				beginI = endI;
				beginJ = endJ;
			}
		}

		return sum;

	}
};
#endif // SORT_STACK_METHODS

#ifdef SORT_GREEDY_METHODS
class Solution {
public:

	struct Room
	{
		int i;
		int j;
		int value;
		int length;
	};

	int getLengthFromAtoB(std::vector<std::vector<int>>& forest, int beginI, int beginJ, int endI, int endJ) {

		std::vector<std::vector<bool>> visited(forest.size(), std::vector<bool>(forest[0].size(), false));
		std::queue<std::pair<int, int>> rooms;
		rooms.emplace(beginI, beginJ);
		int step = 0;

		// װ�����ݽṹ O( m*n )
		while (!	rooms.empty()) {

			int size = rooms.size();
			for (int i = 0; i < size; i++) {
				std::pair<int, int> temp = rooms.front();
				int crtI = temp.first;
				int crtJ = temp.second;
				rooms.pop();
				if (crtI == endI & crtJ == endJ) {
					return step;
				}

				// ������
				if (crtI >= 1) {
					if (visited[crtI - 1][crtJ] == false && forest[crtI - 1][crtJ] != 0) {
						visited[crtI - 1][crtJ] = true;
						rooms.emplace(crtI - 1, crtJ);
					}
				}
				// ������
				if (crtI < forest.size() - 1) {
					if (visited[crtI + 1][crtJ] == false && forest[crtI + 1][crtJ] != 0) {
						visited[crtI + 1][crtJ] = true;
						rooms.emplace(crtI + 1, crtJ);
					}
				}
				// ������
				if (crtJ >= 1) {
					if (visited[crtI][crtJ - 1] == false && forest[crtI][crtJ - 1] != 0) {
						visited[crtI][crtJ - 1] = true;
						rooms.emplace(crtI, crtJ - 1);
					}
				}
				// ������
				if (crtJ < forest[0].size() - 1) {
					if (visited[crtI][crtJ + 1] == false && forest[crtI][crtJ + 1] != 0) {
						visited[crtI][crtJ + 1] = true;
						rooms.emplace(crtI, crtJ + 1);
					}
				}
			}
			step++;
		}

		return -1;
	}

	int cutOffTree(std::vector<std::vector<int>>& forest) {

		// �ҵ������յ� O(m*n)
		std::vector<Room> roomSort;
		for (int i = 0; i < forest.size(); i++) {
			for (int j = 0; j < forest[i].size(); j++) {
				Room crtRoom;
				crtRoom.i = i;
				crtRoom.j = j;
				crtRoom.value = forest[i][j];
				roomSort.push_back(crtRoom);
			}
		}

		// ���� O(m*n * log(m*n))
		std::sort(roomSort.begin(), roomSort.end(), [=](Room a, Room b) {return a.value < b.value; });

		int beginI = 0; // ��ʼ�ĸ���
		int beginJ = 0;
		int endI; // �����ĸ���
		int endJ;
		int sum = 0; // �ܺ�

		// ��ÿһ�ε�ֵ O(m*n)
		for (int i = 0; i < roomSort.size(); i++) {
			if (roomSort[i].value >= 2) {
				endI = roomSort[i].i;
				endJ = roomSort[i].j;

				int length = getLengthFromAtoB(forest, beginI, beginJ, endI, endJ);

				if (length == -1) {
					// �޷�����
					return -1;
				}
				sum += length;
				beginI = endI;
				beginJ = endJ;
			}
		}

		return sum;

	}
};
#endif // SORT_GREEDY_METHODS




#endif