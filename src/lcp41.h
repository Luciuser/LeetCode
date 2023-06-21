/*
 * @Author: Bingyang Jin
 * @Date: 2023-06-21 08:08:25
 * @Editor: Bingyang Jin
 * @FilePath: /src/lcp41.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-06-21 08:59:40
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD, TIME 4ms, 97.78%, MEMORY 10.7MB and 93.33%
 */

#ifndef __lcp_41_h__ 
#define __lcp_41_h__

#include<iostream>
#include<queue>
#include<string>
#include<vector>

class Solution {
public:
	int flipChess(std::vector<std::string>& chessboard) {

		int m = chessboard.size();
		int n = chessboard[0].size();

		// 记录白棋的位置
		std::vector<std::pair<int, int>> position;
		for (int i = 0; i < chessboard.size(); i++) {
			for (int j = 0; j < chessboard[i].size(); j++) {
				std::cout << chessboard[i][j] << std::endl;
				if (chessboard[i][j] == 'O') {
					position.push_back(std::pair<int, int>(i, j));
				}
			}
		}

		int max = 0;
		std::vector < std::vector<int> > mark(m, std::vector<int>(n, 0)); // 标志某个点是否放过黑棋
		// 对每一个白棋周围的8个位置，放一个黑棋，然后递归来分析最终翻转的棋子数量
		for (int i = 0; i < position.size(); i++) {
			for (int xi = -1; xi <= 1; xi++) {
				for (int yi = -1; yi <= 1; yi++) {
					// xi 表示x方向的变化，yi表示y方向的变化
					
					// 当前白棋位置不能放黑棋 
					if (xi == 0 && yi == 0) {
						continue;
					}

					// 当前白棋坐标
					int x = position[i].first;
					int y = position[i].second;

					// 要放的黑棋坐标
					int xb = x + xi;
					int yb = y + yi;

					// 黑棋坐标超出棋盘或者已有其他棋子，均不能放置
					if (xb < 0 || xb >= m || yb < 0 || yb >= n) {
						continue;
					}
					if (chessboard[xb][yb] != '.' || mark[xb][yb] != 0) {
						continue;
					}

					// 可以放置，尝试去迭代
					int sum = 0;
					std::queue<std::pair<int, int>> black_add;
					black_add.push(std::pair<int, int>(xb, yb));
					mark[xb][yb] = 1;

					std::vector<std::pair<int, int>>change_last;
					while (black_add.size() != 0){
						int xc = black_add.front().first;
						int yc = black_add.front().second;
						black_add.pop();

						// 在xc、yc处增加黑棋后，向八个方向前进，进而翻转一些白棋
						for (int xj = -1; xj <= 1; xj++) {
							for (int yj = -1; yj <= 1; yj++) {
								// xi 表示x方向的变化，yi表示y方向的变化
								if (xj == 0 && yj == 0) {
									continue;
								}
								int xt = xc + xj;
								int yt = yc + yj;

								std::vector<std::pair<int, int>> ready;
								while (true){
									if (xt < 0 || xt >= m || yt < 0 || yt >= n) {
										// 遍历位置超出棋盘，则这个方向遍历失败
										//ready.clear();
										break;
									}
									if (chessboard[xt][yt] == '.') {
										// 空棋盘，遍历停止，这个方向遍历失败
										//ready.clear();
										break;
									}
									else if (chessboard[xt][yt] == 'X') {
										// 遇见黑棋，遍历停止，将当前的 ready 列表全部翻转
										sum += ready.size();
										for (int t = 0; t < ready.size(); t++) {
											int new_x = ready[t].first;
											int new_y = ready[t].second;
											black_add.push(std::pair<int, int>(new_x, new_y));
											change_last.push_back(std::pair<int, int>(new_x, new_y));
											chessboard[new_x][new_y] = 'X';
										}
										break;
									}
									else if(chessboard[xt][yt] == 'O') {
										// 遇见白棋，加入翻转列表
										ready.push_back(std::pair<int, int>(xt, yt));
									}

									xt += xj;
									yt += yj;
								}



							}
						}
					}

					if (sum > max) {
						max = sum;
					}
					for (int i = 0; i < change_last.size(); i++) {
						int xch = change_last[i].first;
						int ych = change_last[i].second;
						chessboard[xch][ych] = 'O';
					}
				}
			}
		}
		return max;

	}
};

#endif // __lcp_41_h__