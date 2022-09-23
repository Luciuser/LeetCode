/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-20 08:55:05
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode698.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-20 10:16:10
 * @Editor: Bingyang Jin
 * @Description: create SYSTEM_PRUNE, TIME 36ms, 44.49%, MEMORY 17.6MB and 18.97%
 */

#ifndef __leet_code_854__
#define __leet_code_854__

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
//#include<pair>

class Solution {
public:

	class Node {
	public:
		Node(int _val) { this->val = _val; }
		Node(char c) { this->val = c - 'a'; }
		int val;
		std::vector<Node> next;
	};

	int kSimilarity(std::string s1, std::string s2) {

		int n = s1.size();
		std::vector<std::vector<int>> characterArray(6, std::vector<int>(6, 0)); // a-f 对 a-f 的映射次数
		//std::unordered_map<int, std::unordered_map<int, int>> characterMap; // a-f 对 a-f 的映射次数，每个都需要处理
		std::vector<Node> link; // 链接的顺序

		for (int i = 0; i < n; i++) {
			if (s1[i] != s2[i]) {
				characterArray[s1[i] - 'a'][s2[i] - 'a']++;
				//characterMap[s1[i] - 'a'][s2[i] - 'a']++;
			}
		}
		for (int i = 0; i < 6; i++) {
			Node crtNode(i);
			link.push_back(crtNode);
			for (int j = 0; j < 6; j++) {
				if (characterArray[i][j] > 0) {
					link[i].next.push_back(Node(j));
				}
			}
		}

		int result = 0;
		int swap = 1; // 每次最外层循环中，链接的节点需进行的交换次数
		while (true) {

			for (int i = 0; i < 6; i++) {
				Node *topNode = &(link[i]);
				int before = topNode->val;
				for (int j = 0; j < topNode->next.size(); j++) {
					// 链接迭代
					//Node *crtNode = &(topNode->next[i]);
					std::queue<Node*>q;
					q.emplace(&(topNode->next[i]));
					int crtDeep = 0;
					while (true) {
						if (q.size() == 0) {
							break;
						}
						Node *crtNode = q.front();
						q.pop();
						if (characterArray[before][crtNode->val] == 0) {
							// 链路断开
							break;
						}

						if (crtNode->next.size() == 0) {
							// 到环的底部
							bool isBreak = false;
							for (int k = 0; k < 6; k++) {
								if (characterArray[crtNode->val][k] > 0) {
									// 判断是否已经成环
									if (k == topNode->val) {
										// 已经成环，进行删除
										isBreak = true;
									}
									else {
										// 未成环，继续链接
										crtNode->next.push_back(Node(k));
									}
								}
							}
							continue;
						}
						else {
							for (int k = 0; k < crtNode->next.size(); k++) {
								q.emplace(&(crtNode->next[k]));
							}
						}
						crtDeep++;
					}
				}
			}

			// 是否跳出最外层循环
			bool isEnd = true;
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 6; j++) {
					if (characterArray[i][j] > 0) {
						isEnd = false;
						break;
					}
				}
				if (isEnd==false) {
					break;
				}
			}
			if (isEnd == true) {
				break;
			}
			swap++;
		}
			
		//for (auto iteri = characterMap.begin(); iteri != characterMap.end(); iteri++) {
		//	for (auto iterj = (*iteri).second.begin(); iterj != (*iteri).second.end(); iterj++) {
		//		Node crtNode((*iterj).first);
		//		link[(*iteri).first].push_back(crtNode);
		//	}
		//}

		//// 对每一个组合进行处理，先找循环节点为 2 的，再找为 3 的，最多为6，采用 bfs 方法
		//int result = 0;
		//while (true) {
		//	bool isEnd = true;
		//	for (auto iteri = characterMap.begin(); iteri != characterMap.end(); iteri++) {

		//		auto linkVec = link[(*iteri).first];
		//		for (int i = 0; i < linkVec.size(); i++) {
		//			Node* crtNode = &(linkVec[i]);
		//			if (characterMap[(*iteri).first][crtNode->val] == 0) {
		//				continue;
		//			}


		//			int before = linkVec[i][0];
		//			bool success = true;	// 该链接是否能走通
		//			for (int j = 1; j < linkVec[i].size(); j++) {
		//				int now = linkVec[i][j];
		//				if (characterMap[before][now] == 0) {
		//					success = false;
		//					break;
		//				}
		//			}
		//			if (success) {
		//				// 该链接能走通，在后面跟上新的链接
		//			}
		//		}



		//		for (auto iterj = (*iteri).second.begin(); iterj != (*iteri).second.end(); iterj++) {
		//			if ((*iterj).second == 0) {
		//				continue;
		//			}
		//			isEnd = false;

		//			

		//		}
		//	}
		//	if (isEnd) {
		//		break;
		//	}
		//}
		//
		//return result;


		//for (int maxDeep = 1; maxDeep < 6; maxDeep++) {
		//	for (int i = 0; i < 6; i++) {
		//		for (int j = 0; j < 6; j++) {
		//			if (characterMap[i][j] == 0) {
		//				continue;
		//			}


		//			int deep = 1; // 进行一次转换即可
		//			std::queue<int> q;
		//			std::queue<int> qNext;
		//			std::unordered_set<int> charOccur;
		//			q.emplace(j);
		//			charOccur.emplace(j);
		//			while (true) {
		//				if (q.size() == 0) {
		//					q = qNext;
		//					deep++;
		//					if (deep >= maxDeep) {
		//						break;
		//					}
		//					while (qNext.size() != 0) {
		//						qNext.pop();
		//					}
		//				}
		//				int crtNum = q.front();
		//				q.pop();
		//				while (characterMap[crtNum][i] > 0 || characterMap[i][j] > 0) {
		//					characterMap[crtNum][i]--;
		//					characterMap[i][j]--;
		//					result += deep;
		//				}
		//				if (characterMap[i][j] == 0) {
		//					break;
		//				}

		//				for (int k = 0; k < 6; k++) {
		//					if (characterMap[crtNum][k] > 0 && charOccur.count(k) == 0) {
		//						qNext.emplace(k);
		//						charOccur.emplace(k);
		//					}
		//				}
		//			}
		//		}
		//	}
		//}

		//return result;
	}
};

//class Solution {
//public:
//	int kSimilarity(std::string s1, std::string s2) {
//
//		int n = s1.size();
//		std::unordered_map<char, std::vector<char>> characterIndex;
//
//		for (int i = 0; i < n; i++) {
//			if (s1[i] != s2[i]) {
//				characterIndex[s1[i]].push_back(s2[2]);
//			}
//		}
//
//		// 对每一个组合进行处理，采用 bfs 方法
//		for (auto iter = characterIndex.begin(); iter != characterIndex.end(); iter++) {
//			char destination = (*iter).first;
//			for (int i = 0; i < (*iter).second.size(); i++) {
//				char crtCharacter = (*iter).second[i];
//				while (true) {
//					bool find = false;
//					std::queue<char> q;
//					std::unordered_set<char> characterOccur;
//					for (int j = 0; j < characterIndex[crtCharacter].size(); j++) {
//						char nextCharacter = characterIndex[crtCharacter][j];
//						if (nextCharacter == destination) {
//							find = true;
//							
//							break;
//						}
//						else
//						{
//							if (characterOccur.count(nextCharacter) == 0) {
//								q.emplace(nextCharacter);
//								characterOccur.
//							}
//						}
//					}
//				}
//			}
//
//
//			for (int i = 0; i < (*iter).second.size(); i++) {
//				char crtCharacter = (*iter).second[i];
//				if (characterOccur.count(crtCharacter) == 0) {
//					q.push(crtCharacter);
//					characterOccur.emplace(crtCharacter);
//				}
//			}
//			while (true) {
//				if (q.size() == 0) {
//					break;
//				}
//				char crtCharacter = q.front();
//				q.pop();
//			}
//
//		}
//
//
//		//// 由于仅有 a-f 六个小写字母，可以进行编码来判断 s1[i]->s2[i] 的情况，编码为 (s1[i] - 'a') * 6 + s2[i] - 'a'，来判断该组合出现的次数
//		//std::unordered_map<int, int> characterIndex;
//		//for (int i = 0; i < n; i++) {
//		//	if (s1[i] != s2[i]) {
//		//		int key = (s1[i] - 'a') * 6 + s2[i] - 'a';
//		//		characterIndex[key]++;
//		//	}
//		//}
//
//		//for (auto iter = characterIndex.begin(); iter != characterIndex.end(); iter++) {
//		//	int time = (*iter).second;
//		//	for (int i = 0; i < time; i++) {
//		//		// 对每一个组合进行处理，采用广度有限搜索的方法
//		//	}
//		//}
//
//		return 0;
//	}
//};

#endif // __leet_code_854__