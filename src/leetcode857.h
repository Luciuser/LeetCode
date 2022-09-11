/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-11 10:50:40
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode857.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-11 12:39:21
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD，TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
 */

 /*
 * @EditTime: 2022-09-11 14:12:07
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD2，TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
 */

#ifndef __leet_code_857__
#define __leet_code_857__

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

//#define NORMAL_METHOD // 贪心+优先队列，TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
//#define NORMAL_METHOD2 // 贪心+优先队列，优化了存储和速度，TIME 400ms, 5.32%, MEMORY 31MB and 5.32%
#define LEETCODE_METHOD // 贪心+优先队列，学习官方的写法，TIME 844ms, 5.32%, MEMORY 391.4MB and 5.32%

#ifdef LEETCODE_METHOD
class Solution {
public:
	double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
		// 对于选择的 a1、a2、……、ak 这 k 个人，其工作质量为 q1、q2、……、qk，其最低期望工资为 w1、w2、……、wk
		// 为保证 k 个人的工资需满足 a1:a2:……:ak ，且均大于最低期望工资，则需计算一个比例 ratio，其中 ri = wi / qi，取 ri 最大的一个作为标准，即可满足
		// 因此最终支付的工资 F = A*B，其中 A = (a1+a2+……+ak)；B = max(r1, r2, ……, rk)

		// 计算薪酬和能力的比例，并排序，O(nlogn)
		std::vector<int> ratio;
		for (int i = 0; i < quality.size(); i++) {
			ratio.push_back(i);
		}
		std::sort(ratio.begin(), ratio.end(), [=](int a, int b) {
			return quality[a] * wage[b] > quality[b] * wage[a];
		});

		// 从小到大考虑每个 ratio，并组成一个组，保证该组内不存在更大的 ratio
		double result = std::numeric_limits<double>::max();
		
		std::priority_queue<int, std::vector<int>, std::less<int>> que;
		double qualitySum = 0;
		for (int i = 0; i < k; i++) {
			qualitySum += quality[ratio[i]];
			que.push(quality[ratio[i]]);
		}
		result = 1.0 * wage[ratio[k - 1]] / quality[ratio[k - 1]] * qualitySum;
		for (int i = k; i < quality.size(); i++) {
			// 减一个加一个
			qualitySum -= que.top();
			que.pop();

			qualitySum += quality[ratio[i]];
			que.push(quality[ratio[i]]);

			double sum = 1.0 * wage[ratio[i]] / quality[ratio[i]] * qualitySum;
			result = result > sum ? sum : result;
		}

		return result;
	}
};
#endif // LEETCODE_METHOD

#ifdef NORMAL_METHOD2
class Solution {
public:
	double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
		// 对于选择的 a1、a2、……、ak 这 k 个人，其工作质量为 q1、q2、……、qk，其最低期望工资为 w1、w2、……、wk
		// 为保证 k 个人的工资需满足 a1:a2:……:ak ，且均大于最低期望工资，则需计算一个比例 ratio，其中 ri = wi / qi，取 ri 最大的一个作为标准，即可满足
		// 因此最终支付的工资 F = A*B，其中 A = (a1+a2+……+ak)；B = max(r1, r2, ……, rk)

		// 计算薪酬和能力的比例，并排序，O(nlogn)
		std::map<double, std::vector<int>> people; // ratio-->index
		for (int i = 0; i < quality.size(); i++) {
			double ratio = 1.0 * wage[i] / quality[i];
			people[ratio].push_back(i);
		}

		// 从小到大考虑每个 ratio，并组成一个组，保证该组内不存在更大的 ratio
		double result = std::numeric_limits<double>::max();

		std::map<int, int, std::greater<>> qualityStack;
		int qualitySum = 0;
		int kNum = 0;
		for (auto iter = people.begin(); iter != people.end(); iter++) {
			for (int i = 0; i < (*iter).second.size(); i++) {
				int index = (*iter).second[i];
				if (kNum < k) {
					// 不够 k 个，直接增加
					if (qualityStack.count(quality[index]) == 0) {
						qualityStack[quality[index]] = 1;
					}
					else {
						qualityStack[quality[index]]++;
					}
					qualitySum += quality[index];
					kNum++;
				}

				if(kNum == k) {
					// 刚好k个，进行一次计算
					double ratioMax = (*iter).first;
					double sum = ratioMax * qualitySum;
					if (result > sum) {
						result = sum;
					}
					kNum++;
				}
				else if(kNum > k) {
					// 删一个，加一个
					for (auto iterQuality = qualityStack.begin(); iterQuality != qualityStack.end(); iterQuality++) {
						if ((*iterQuality).second > 0) {
							(*iterQuality).second--;
							qualitySum -= (*iterQuality).first;
							break;
						}
					}
					qualitySum += quality[index];
					if (qualityStack.count(quality[index]) == 0) {
						qualityStack[quality[index]] = 1;
					}
					else {
						qualityStack[quality[index]]++;
					}
					double ratioMax = (*iter).first;
					double sum = ratioMax * qualitySum;
					if (result > sum) {
						result = sum;
					}
				}

			}

		}
		return result;
	}
};
#endif // NORMAL_METHOD2

#ifdef NORMAL_METHOD
class Solution {
public:
	double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
		// 对于选择的 a1、a2、……、ak 这 k 个人，其工作质量为 q1、q2、……、qk，其最低期望工资为 w1、w2、……、wk
		// 为保证 k 个人的工资需满足 a1:a2:……:ak ，且均大于最低期望工资，则需计算一个比例 ratio，其中 ri = wi / qi，取 ri 最大的一个作为标准，即可满足
		// 因此最终支付的工资 F = A*B，其中 A = (a1+a2+……+ak)；B = max(r1, r2, ……, rk)

		// 计算薪酬和能力的比例，O(n)
		std::vector<People*> peopleRatio;
		//std::vector<People*> peopleQuality;
		for (int i = 0; i < quality.size(); i++) {
			People* tempPeople = new People(i, quality[i], wage[i]);
			peopleRatio.push_back(tempPeople);
			//peopleQuality.push_back(tempPeople);
		}

		// 排序，O(nlogn)
		std::sort(peopleRatio.begin(), peopleRatio.end(), [=](People* a, People *b) {
			return a->ratio < b->ratio;
		});
		//std::sort(peopleQuality.begin(), peopleQuality.end(), [=](People* a, People *b) {
		//	return a->quality > b->quality;
		//});

		// 从小到大考虑每个 ratio，并组成一个组，保证该组内不存在更大的 ratio
		double result = std::numeric_limits<double>::max();

		std::map<int, int, std::greater<>> qualityStack;
		int qualitySum = 0;
		for (int i = 0; i < k; i++) {
			if (qualityStack.count(peopleRatio[i]->quality) == 0) {
				qualityStack[peopleRatio[i]->quality] = 1;
			}
			else {
				qualityStack[peopleRatio[i]->quality]++;
			}
			qualitySum += peopleRatio[i]->quality;
		}
		for (int i = k - 1; i < quality.size(); i++) {
			if (i >= k) {
				// 删一个，加一个
				for (auto iter = qualityStack.begin(); iter != qualityStack.end(); iter++) {
					if ((*iter).second > 0) {
						(*iter).second--;
						qualitySum -= (*iter).first;
						break;
					}
				}
				qualitySum += peopleRatio[i]->quality;
				if (qualityStack.count(peopleRatio[i]->quality) == 0) {
					qualityStack[peopleRatio[i]->quality] = 1;
				}
				else {
					qualityStack[peopleRatio[i]->quality]++;
				}
			}
			double ratioMax = peopleRatio[i]->ratio;
			double sum = ratioMax * qualitySum;
			if (result > sum) {
				result = sum;
			}
		}

		return result;
	}

private:
	struct People
	{
		int index;
		int quality;
		int wage;
		double ratio;

		People(int i, int _quality, int _wage) {
			index = i;
			quality = _quality;
			wage = _wage;
			ratio = 1.0 * wage / quality;
		}
	};
};
#endif // NORMAL_METHOD

#endif // __leet_code_857__