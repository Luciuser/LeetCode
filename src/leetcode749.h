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

	// 自定义set比较函数
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

	int index;			// 病毒区域序号，从-1开始，到-无穷
	int virusNum;	// 病毒所占区域总数，可以删去
	int infectNum;	// 病毒下一次要感染的区域，可以删去
	int buildWallNum;	// 针对该区域构建的防火墙的数量

	std::vector<std::pair<int, int>> position;	// 病毒所在区域
	std::vector<std::pair<int, int>> infectPosition;	// 病毒下一次要感染的区域

};

class Solution {
public:

	// dfs过程中，寻找上/右/下/左（direction=0/1/2/3）时，i 的新值
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
	// dfs过程中，寻找上/右/下/左（direction=0/1/2/3）时，j 的新值
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

			// 寻找上/右/下/左的单元格
			if (isInfected[crtI][crtJ] == 1) {
				// 有病毒
				virus.position.push_back(std::pair<int, int>(crtI, crtJ));
				isInfected[crtI][crtJ] = index;
				findVirus(isInfected, virus, crtI, crtJ);
			}
			else if (isInfected[crtI][crtJ] == 0) {
				// 需要构建的防火墙+1
				virus.buildWallNum++;
				// 没有病毒
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

	// 病毒向外增长一层
	int virusGen(std::vector<std::vector<int>>& isInfected, Virus & virus) {
		int index = virus.index;
		for (int i = 0; i < virus.infectPosition.size(); i++) {
			isInfected[virus.infectPosition[i].first][virus.infectPosition[i].second] = index;
		}
	}

	int containVirus(std::vector<std::vector<int>>& isInfected) {
		m = isInfected.size();
		n = isInfected[0].size();

		// 创建记录墙的二维vector O(m*n)
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

		// 创建记录病毒区域set O(m*n)
		index = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (isInfected[i][j] == 1) {
					// 该区域存在病毒，开始深度优先搜索遍历病毒
					Virus newVirus;
					// 当前单元格赋值
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

		// 每次对一个区域建立防火墙
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

			// 所有病毒向外长一层
			for (int i = 0; i < virus.size(); i++) {
				virusGen(isInfected, virus[i]);
			}
		}
		return sum;
	}

private:
	int m = 0;		// 区域的高度
	int n = 0;		// 区域的宽度
	std::vector<std::vector<int>> wallUpDown; // 每个格子上下的墙
	std::vector<std::vector<int>> wallLeftRight; // 每个格子左右的墙
	std::vector<Virus> virus;	// 存储病毒的序列
	std::map<int, int> virusSolve;	// 根据病毒区域的id，判断该部分病毒是否已经被防火墙关起来，0则未被关起来，1则已经关起来

	int index = 0;		// dfs 过程中，每一片病毒共用的序号

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

	// 自定义set比较函数
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

	int buildWallNum;	// 针对该区域构建的防火墙的数量

	std::vector<std::pair<int, int>> position;	// 病毒所在区域
	std::vector<std::pair<int, int>> infectPosition;	// 病毒下一次要感染的区域

};

class Solution {
public:

	// dfs过程中，寻找上/右/下/左（direction=0/1/2/3）时，i 的新值
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
	// dfs过程中，寻找上/右/下/左（direction=0/1/2/3）时，j 的新值
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

			// 寻找上/右/下/左的单元格
			if (isInfected[crtI][crtJ] == 1) {
				// 有病毒
				//isInfected[crtI][crtJ] = index;
				if (dfsFind[crtI][crtJ] == 1) {
					// 已经遍历过了
					continue;
				}
				virus.position.push_back(std::pair<int, int>(crtI, crtJ));
				dfsFind[crtI][crtJ] = 1;
				findVirus(isInfected, virus, crtI, crtJ);
			}
			else if (isInfected[crtI][crtJ] == 0) {
				// 需要构建的防火墙+1
				virus.buildWallNum++;
				isEmpty = false;
				// 没有病毒
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

		// 创建记录墙的二维vector O(m*n)
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
		// 每次对一个区域建立防火墙
		while (true) {

			dfsFind.clear();
			for (int mi = 0; mi < m; mi++) {
				std::vector<int> temp;
				for (int ni = 0; ni < n; ni++) {
					temp.push_back(0);
				}
				dfsFind.push_back(temp);
			}

			// 创建记录病毒区域set O(m*n)
			isEmpty = true;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (isInfected[i][j] == 1 && dfsFind[i][j] == 0) {
						// 该区域存在病毒，开始深度优先搜索遍历病毒
						Virus newVirus;
						// 当前单元格赋值

						newVirus.position.push_back(std::pair<int, int>(i, j));
						dfsFind[i][j] = 1;
						// 开始 dfs 遍历
						findVirus(isInfected, newVirus, i, j);

						virus.push_back(newVirus);
					}
				}
			}

			if (virus.size() == 0) {
				// 已经没有病毒
				break;
			}
			if (isEmpty == true) {
				// 全图都是病毒
				break;
			}
			int max = 0;
			for (int i = 0; i < virus.size(); i++) {
				if (virus[i].infectPosition.size() > virus[max].infectPosition.size()) {
					max = i;
				}
			}
			if (virus[max].buildWallNum == 0) {
				// 病毒已经无法再长
				break;
			}
			sum += virus[max].buildWallNum;

			// 被隔绝的病毒不长，其他病毒向外长一层
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
	int m = 0;		// 区域的高度
	int n = 0;		// 区域的宽度
	std::vector<std::vector<int>> wallUpDown; // 每个格子上下的墙
	std::vector<std::vector<int>> wallLeftRight; // 每个格子左右的墙
	std::vector<Virus> virus;	// 存储病毒的序列
	std::vector<std::vector<int>> dfsFind;	// dfs 是否已经遍历到，0则未被关起来，1则已经关起来

	bool isEmpty = true; // 是否全图已经找不到好的单元
};
#endif // VIOLENCE_DFS_METHOD

#endif // __leet_code_749__