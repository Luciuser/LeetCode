/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-18 12:31:29
 * @FilePath: /src/leetcode749.h
  * @Description: create old way which does not matter
 */
 /*
  * @EditTime: 2022-07-18 16:44:54
  * @Editor: Bingyang Jin
  * @Description: create VIOLENCE_DFS_METHOD, time 32ms, memory 15.8MB
  */

#ifndef __leet_code_749__
#define __leet_code_749__

#include<iostream>
#include<vector>
#include<set>
#include<map>

//#define OLD_WAYS
#define VIOLENCE_DFS_METHOD

#ifdef OLD_WAYS
class Virus {
public:
	Virus() {
		index = 0;
		virusNum = 0;
		infectNum = 0;
		buildWallNum = 0;
		position.clear();
		infectPosition.clear();
	}

	// �Զ���set�ȽϺ���
	bool operator<(Virus const &ref)const {
		return position.size() < ref.position.size();
	}
	bool operator<=(Virus const &ref)const {
		return position.size() <= ref.position.size();
	}
	bool operator>(Virus const &ref)const {
		return position.size() > ref.position.size();
	}
	bool operator>=(Virus const &ref)const {
		return position.size() >= ref.position.size();
	}
	bool operator==(Virus const &ref)const {
		return position.size() == ref.position.size();
	}

	int index;			// ����������ţ���-1��ʼ����-����
	int virusNum;	// ������ռ��������������ɾȥ
	int infectNum;	// ������һ��Ҫ��Ⱦ�����򣬿���ɾȥ
	int buildWallNum;	// ��Ը����򹹽��ķ���ǽ������

	std::vector<std::pair<int, int>> position;	// ������������
	std::vector<std::pair<int, int>> infectPosition;	// ������һ��Ҫ��Ⱦ������

};

class Solution {
public:

	// dfs�����У�Ѱ����/��/��/��direction=0/1/2/3��ʱ��i ����ֵ
	int new_i(int i, int direction) {
		switch (direction)
		{
		case 0:return i - 1;
		case 1:return i;
		case 2:return i + 1;
		case 3:return i;
		default:
			break;
		}
		return -1;
	}
	// dfs�����У�Ѱ����/��/��/��direction=0/1/2/3��ʱ��j ����ֵ
	int new_j(int j, int direction) {
		switch (direction)
		{
		case 0:return j;
		case 1:return j + 1;
		case 2:return j;
		case 3:return j - 1;
		default:
			break;
		}
		return -1;
	}

	int findVirus(std::vector<std::vector<int>>& isInfected, Virus & virus, int i, int j) {
		for (int direction = 0; direction < 4; direction++) {
			int crtI = new_i(i, direction);
			int crtJ = new_j(j, direction);
			if (crtI < 0 || crtI >= m || crtJ < 0 || crtJ >= n) {
				continue;
			}

			// Ѱ����/��/��/��ĵ�Ԫ��
			if (isInfected[crtI][crtJ] == 1) {
				// �в���
				virus.position.push_back(std::pair<int, int>(crtI, crtJ));
				isInfected[crtI][crtJ] = index;
				findVirus(isInfected, virus, crtI, crtJ);
			}
			else if (isInfected[crtI][crtJ] == 0) {
				// ��Ҫ�����ķ���ǽ+1
				virus.buildWallNum++;
				// û�в���
				bool find = false;
				for (int k = 0; k < virus.infectPosition.size(); k++) {
					if (virus.infectPosition[k].first == crtI && virus.infectPosition[k].second == crtJ) {
						find = true;
						break;
					}
				}
				if (find == false) {
					virus.infectPosition.push_back(std::pair<int, int>(crtI, crtJ));
				}
			}

		}
		return 0;
	}

	// ������������һ��
	int virusGen(std::vector<std::vector<int>>& isInfected, Virus & virus) {
		int index = virus.index;
		for (int i = 0; i < virus.infectPosition.size(); i++) {
			isInfected[virus.infectPosition[i].first][virus.infectPosition[i].second] = index;
		}
	}

	int containVirus(std::vector<std::vector<int>>& isInfected) {
		m = isInfected.size();
		n = isInfected[0].size();

		// ������¼ǽ�Ķ�άvector O(m*n)
		for (int i = 0; i < m + 1; i++) {
			std::vector<int> temp;
			for (int j = 0; j < n; j++) {
				temp.push_back(0);
			}
			wallUpDown.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			std::vector<int> temp;
			for (int j = 0; j < n + 1; j++) {
				temp.push_back(0);
			}
			wallLeftRight.push_back(temp);
		}

		// ������¼��������set O(m*n)
		index = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (isInfected[i][j] == 1) {
					// ��������ڲ�������ʼ�������������������
					Virus newVirus;
					// ��ǰ��Ԫ��ֵ
					newVirus.index = index;
					newVirus.position.push_back(std::pair<int, int>(i, j));
					isInfected[i][j] = index;
					findVirus(isInfected, newVirus, i, j);
					//virus.emplace(newVirus);
					virus.push_back(newVirus);

					virusSolve[index] = 0;
					index--;
				}
			}
		}

		int sum = 0;

		// ÿ�ζ�һ������������ǽ
		while (true) {

			if (virus.size() == 0) {
				break;
			}
			int max = 0;
			for (int i = 0; i < virus.size(); i++) {
				if (virus[i].infectPosition.size() > virus[max].infectPosition.size()) {
					max = i;
				}
			}
			sum += virus[max].buildWallNum;
			virus[max].infectPosition.clear();
			virusSolve[virus[max].index] = 1;
			virus.erase(virus.begin() + max);

			// ���в������ⳤһ��
			for (int i = 0; i < virus.size(); i++) {
				virusGen(isInfected, virus[i]);
			}
		}
		return sum;
	}

private:
	int m = 0;		// ����ĸ߶�
	int n = 0;		// ����Ŀ��
	std::vector<std::vector<int>> wallUpDown; // ÿ���������µ�ǽ
	std::vector<std::vector<int>> wallLeftRight; // ÿ���������ҵ�ǽ
	std::vector<Virus> virus;	// �洢����������
	std::map<int, int> virusSolve;	// ���ݲ��������id���жϸò��ֲ����Ƿ��Ѿ�������ǽ��������0��δ����������1���Ѿ�������

	int index = 0;		// dfs �����У�ÿһƬ�������õ����

};
#endif // OLD_WAYS

#ifdef VIOLENCE_DFS_METHOD
class Virus {
public:
	Virus() {
		buildWallNum = 0;
		position.clear();
		infectPosition.clear();
	}

	// �Զ���set�ȽϺ���
	bool operator<(Virus const &ref)const {
		return position.size() < ref.position.size();
	}
	bool operator<=(Virus const &ref)const {
		return position.size() <= ref.position.size();
	}
	bool operator>(Virus const &ref)const {
		return position.size() > ref.position.size();
	}
	bool operator>=(Virus const &ref)const {
		return position.size() >= ref.position.size();
	}
	bool operator==(Virus const &ref)const {
		return position.size() == ref.position.size();
	}

	int buildWallNum;	// ��Ը����򹹽��ķ���ǽ������

	std::vector<std::pair<int, int>> position;	// ������������
	std::vector<std::pair<int, int>> infectPosition;	// ������һ��Ҫ��Ⱦ������

};

class Solution {
public:

	// dfs�����У�Ѱ����/��/��/��direction=0/1/2/3��ʱ��i ����ֵ
	int new_i(int i, int direction) {
		switch (direction)
		{
		case 0:return i - 1;
		case 1:return i;
		case 2:return i + 1;
		case 3:return i;
		default:
			break;
		}
		return -1;
	}
	// dfs�����У�Ѱ����/��/��/��direction=0/1/2/3��ʱ��j ����ֵ
	int new_j(int j, int direction) {
		switch (direction)
		{
		case 0:return j;
		case 1:return j + 1;
		case 2:return j;
		case 3:return j - 1;
		default:
			break;
		}
		return -1;
	}

	int findVirus(std::vector<std::vector<int>>& isInfected, Virus & virus, int i, int j) {
		for (int direction = 0; direction < 4; direction++) {
			int crtI = new_i(i, direction);
			int crtJ = new_j(j, direction);
			if (crtI < 0 || crtI >= m || crtJ < 0 || crtJ >= n) {
				continue;
			}

			// Ѱ����/��/��/��ĵ�Ԫ��
			if (isInfected[crtI][crtJ] == 1) {
				// �в���
				//isInfected[crtI][crtJ] = index;
				if (dfsFind[crtI][crtJ] == 1) {
					// �Ѿ���������
					continue;
				}
				virus.position.push_back(std::pair<int, int>(crtI, crtJ));
				dfsFind[crtI][crtJ] = 1;
				findVirus(isInfected, virus, crtI, crtJ);
			}
			else if (isInfected[crtI][crtJ] == 0) {
				// ��Ҫ�����ķ���ǽ+1
				virus.buildWallNum++;
				isEmpty = false;
				// û�в���
				bool find = false;
				for (int k = 0; k < virus.infectPosition.size(); k++) {
					if (virus.infectPosition[k].first == crtI && virus.infectPosition[k].second == crtJ) {
						find = true;
						break;
					}
				}
				if (find == false) {
					virus.infectPosition.push_back(std::pair<int, int>(crtI, crtJ));
				}
			}

		}
		return 0;
	}

	int containVirus(std::vector<std::vector<int>>& isInfected) {
		m = isInfected.size();
		n = isInfected[0].size();

		// ������¼ǽ�Ķ�άvector O(m*n)
		for (int i = 0; i < m + 1; i++) {
			std::vector<int> temp;
			for (int j = 0; j < n; j++) {
				temp.push_back(0);
			}
			wallUpDown.push_back(temp);
		}
		for (int i = 0; i < m; i++) {
			std::vector<int> temp;
			for (int j = 0; j < n + 1; j++) {
				temp.push_back(0);
			}
			wallLeftRight.push_back(temp);
		}

		int sum = 0;
		// ÿ�ζ�һ������������ǽ
		while (true) {

			dfsFind.clear();
			for (int mi = 0; mi < m; mi++) {
				std::vector<int> temp;
				for (int ni = 0; ni < n; ni++) {
					temp.push_back(0);
				}
				dfsFind.push_back(temp);
			}

			// ������¼��������set O(m*n)
			isEmpty = true;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (isInfected[i][j] == 1 && dfsFind[i][j] == 0) {
						// ��������ڲ�������ʼ�������������������
						Virus newVirus;
						// ��ǰ��Ԫ��ֵ

						newVirus.position.push_back(std::pair<int, int>(i, j));
						dfsFind[i][j] = 1;
						// ��ʼ dfs ����
						findVirus(isInfected, newVirus, i, j);

						virus.push_back(newVirus);
					}
				}
			}

			if (virus.size() == 0) {
				// �Ѿ�û�в���
				break;
			}
			if (isEmpty == true) {
				// ȫͼ���ǲ���
				break;
			}
			int max = 0;
			for (int i = 0; i < virus.size(); i++) {
				if (virus[i].infectPosition.size() > virus[max].infectPosition.size()) {
					max = i;
				}
			}
			if (virus[max].buildWallNum == 0) {
				// �����Ѿ��޷��ٳ�
				break;
			}
			sum += virus[max].buildWallNum;

			// �������Ĳ��������������������ⳤһ��
			for (int i = 0; i < virus.size(); i++) {
				if (max == i) {
					for (int j = 0; j < virus[i].position.size(); j++) {
						int pi = virus[i].position[j].first;
						int pj = virus[i].position[j].second;

						isInfected[pi][pj] = -1;
					}
				}
				else {
					for (int j = 0; j < virus[i].infectPosition.size(); j++) {
						int pi = virus[i].infectPosition[j].first;
						int pj = virus[i].infectPosition[j].second;

						isInfected[pi][pj] = 1;
					}
				}
			}
			virus.clear();
		}

		return sum;
	}

private:
	int m = 0;		// ����ĸ߶�
	int n = 0;		// ����Ŀ��
	std::vector<std::vector<int>> wallUpDown; // ÿ���������µ�ǽ
	std::vector<std::vector<int>> wallLeftRight; // ÿ���������ҵ�ǽ
	std::vector<Virus> virus;	// �洢����������
	std::vector<std::vector<int>> dfsFind;	// dfs �Ƿ��Ѿ���������0��δ����������1���Ѿ�������

	bool isEmpty = true; // �Ƿ�ȫͼ�Ѿ��Ҳ����õĵ�Ԫ
};
#endif // VIOLENCE_DFS_METHOD

#endif // __leet_code_749__