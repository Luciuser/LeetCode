#ifndef __leet_code_174__
#define __leet_code_174__

#include<iostream>
#include<vector>

//#define POISITIVE_METHODS // ����̬�滮����Ҫ������ʿ�ߵ�ÿ��������ʱ����ʿ��ǰ������ֵ����Ҫ�ĳ�ʼ����ֵ��ͬʱ�յ�����·����Ӱ��
#define REVERSE_METHODS // ����̬�滮������ʿ�����ߵ����������ʱ����¼��ʿ��Ҫ�ĳ�ʼ����ֵ���ɣ������¼��ʿ�ĳ�ʼ����ֵ�������յ�ǰ��·����Ӱ��

#ifdef POISITIVE_METHODS
class Solution {
public:

	struct RoomTemp {
		std::vector<int> crtHealth; // ��ʿ��ʼ����ֵΪ0ʱ�������ߵ�ĳһ�������ϵ�����ֵ
		std::vector<int> result;// ��ʿҪ�ߵ�ĳһ��������ʱ�����ٵĳ�ʼ������ֵ
	};

	int min(int a, int b) {
		return a <= b ? a : b;
	}

	int max(int a, int b) {
		return a >= b ? a : b;
	}

	int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
		std::vector<std::vector<RoomTemp>> room;
		for (int i = 0; i < dungeon.size(); i++) {
			std::vector<RoomTemp> roomColumn;
			for (int j = 0; j < dungeon[i].size(); j++) {
				RoomTemp crtRoom;
				if (i == 0) {
					if (j == 0) {
						crtRoom.crtHealth.push_back(dungeon[0][0]);
						crtRoom.result.push_back(
							max(0, 0 - dungeon[0][0]));
					}
					else {
						crtRoom.crtHealth.push_back(roomColumn[j - 1].crtHealth[0] + dungeon[i][j]);
						crtRoom.result.push_back(
							max(roomColumn[j - 1].result[0], 0 - crtRoom.crtHealth[0]));
					}
				}
				else {
					if (j == 0) {
						crtRoom.crtHealth.push_back(room[i - 1][0].crtHealth[0] + dungeon[i][j]);
						crtRoom.result.push_back(
							max(room[i - 1][0].result[0], 0 - crtRoom.crtHealth[0]));
					}
					else {
						// ���п��ܵķ���
						int healthIndex = 0;
						for (int k = 0; k < roomColumn[j - 1].crtHealth.size(); k++) {
							crtRoom.crtHealth.push_back(roomColumn[j - 1].crtHealth[k] + dungeon[i][j]);
							crtRoom.result.push_back(
								max(roomColumn[j - 1].result[k], 0 - crtRoom.crtHealth[healthIndex]));
							healthIndex++;
						}
						for (int k = 0; k < room[i - 1][j].crtHealth.size(); k++) {
							crtRoom.crtHealth.push_back(room[i - 1][j].crtHealth[k] + dungeon[i][j]);
							crtRoom.result.push_back(
								max(room[i - 1][j].result[k], 0 - crtRoom.crtHealth[healthIndex]));
							healthIndex++;
						}

						// �Է������д���
						std::vector<bool> isDelete;
						for (int k = 0; k < crtRoom.crtHealth.size(); k++) {
							isDelete.push_back(false);
						}
						for (int k = 0; k < crtRoom.crtHealth.size(); k++) {
							if (isDelete[k] == true) {
								continue;
							}
							for (int m = 0; m < crtRoom.crtHealth.size(); m++) {
								if (isDelete[m] == true) {
									continue;
								}
								if (crtRoom.crtHealth[m]<crtRoom.crtHealth[k] && crtRoom.result[m]>crtRoom.result[k]) {
									isDelete[m] = true;
								}
							}
						}

						for (int k = 0; k < isDelete.size(); k++) {
							if (isDelete[k] == true) {
								isDelete.erase(isDelete.begin() + k);
								crtRoom.crtHealth.erase(crtRoom.crtHealth.begin() + k);
								crtRoom.result.erase(crtRoom.result.begin() + k);
								k--;
							}
						}

					}
				}
				//std::cout << "i " << i << "  j " << j << std::endl;
				//for (int k = 0; k < crtRoom.result.size(); k++) {
				//	std::cout << "    " << crtRoom.crtHealth[k] << " " << crtRoom.result[k] << std::endl;
				//}
				roomColumn.push_back(crtRoom);
			}

			room.push_back(roomColumn);
			roomColumn.clear();
		}

		RoomTemp lastRoom = room[dungeon.size() - 1][dungeon[0].size() - 1];
		int last = lastRoom.result[0];
		for (int i = 0; i < lastRoom.result.size(); i++) {
			//std::cout << lastRoom.result[i] << std::endl;
			if (lastRoom.result[i] < last) {
				last = lastRoom.result[i];
			}
		}

		return last + 1;
	}
};
#endif // POISITIVE_METHODS

#ifdef REVERSE_METHODS
class Solution {
public:
	int min(int a, int b) {
		return a < b ? a : b;
	}

	int max(int a, int b) {
		return a > b ? a : b;
	}

	int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
		std::vector<std::vector<int>> result;

		for (int i = 0; i < dungeon.size() ; i++) {
			std::vector<int> resultColumn;
			for (int j = 0; j < dungeon[i].size(); j++) {
				int di = dungeon.size() - i - 1;
				int dj = dungeon[di].size() - j - 1;

				if (i == 0) {
					if (j == 0) {
						resultColumn.push_back(
							min(dungeon[di][dj], 0)
							);
					}
					else {
						resultColumn.push_back(
							min(resultColumn[j - 1] + dungeon[di][dj], 0)
							);
					}
				}
				else {
					if (j == 0) {
						resultColumn.push_back(
							min( result[i - 1][j] + dungeon[di][dj], 0)
							);
					}
					else {
						resultColumn.push_back(
							min( max(resultColumn[j - 1], result[i - 1][j]) + dungeon[di][dj], 0)
						);
					}
				}
			}
			result.push_back(resultColumn);
		}

		//for (int i = 0; i < result.size(); i++) {
		//	for (int j = 0; j < result[i].size(); j++) {
		//		std::cout << result[i][j] << " ";
		//	}
		//	std::cout << std::endl;
		//}

		return 0 - result[result.size() - 1][result[0].size() - 1] + 1;
	}
};
#endif // REVERSE_METHODS



#endif