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
 * @Description: create NORMAL_METHOD��TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
 */

 /*
 * @EditTime: 2022-09-11 14:12:07
 * @Editor: Bingyang Jin
 * @Description: create NORMAL_METHOD2��TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
 */

#ifndef __leet_code_857__
#define __leet_code_857__

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>

//#define NORMAL_METHOD // ̰��+���ȶ��У�TIME 368ms, 5.32%, MEMORY 26.3MB and 6.39%
//#define NORMAL_METHOD2 // ̰��+���ȶ��У��Ż��˴洢���ٶȣ�TIME 400ms, 5.32%, MEMORY 31MB and 5.32%
#define LEETCODE_METHOD // ̰��+���ȶ��У�ѧϰ�ٷ���д����TIME 844ms, 5.32%, MEMORY 391.4MB and 5.32%

#ifdef LEETCODE_METHOD
class Solution {
public:
	double mincostToHireWorkers(std::vector<int>& quality, std::vector<int>& wage, int k) {
		// ����ѡ��� a1��a2��������ak �� k ���ˣ��乤������Ϊ q1��q2��������qk���������������Ϊ w1��w2��������wk
		// Ϊ��֤ k ���˵Ĺ��������� a1:a2:����:ak ���Ҿ���������������ʣ��������һ������ ratio������ ri = wi / qi��ȡ ri ����һ����Ϊ��׼����������
		// �������֧���Ĺ��� F = A*B������ A = (a1+a2+����+ak)��B = max(r1, r2, ����, rk)

		// ����н��������ı�����������O(nlogn)
		std::vector<int> ratio;
		for (int i = 0; i < quality.size(); i++) {
			ratio.push_back(i);
		}
		std::sort(ratio.begin(), ratio.end(), [=](int a, int b) {
			return quality[a] * wage[b] > quality[b] * wage[a];
		});

		// ��С������ÿ�� ratio�������һ���飬��֤�����ڲ����ڸ���� ratio
		double result = std::numeric_limits<double>::max();
		
		std::priority_queue<int, std::vector<int>, std::less<int>> que;
		double qualitySum = 0;
		for (int i = 0; i < k; i++) {
			qualitySum += quality[ratio[i]];
			que.push(quality[ratio[i]]);
		}
		result = 1.0 * wage[ratio[k - 1]] / quality[ratio[k - 1]] * qualitySum;
		for (int i = k; i < quality.size(); i++) {
			// ��һ����һ��
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
		// ����ѡ��� a1��a2��������ak �� k ���ˣ��乤������Ϊ q1��q2��������qk���������������Ϊ w1��w2��������wk
		// Ϊ��֤ k ���˵Ĺ��������� a1:a2:����:ak ���Ҿ���������������ʣ��������һ������ ratio������ ri = wi / qi��ȡ ri ����һ����Ϊ��׼����������
		// �������֧���Ĺ��� F = A*B������ A = (a1+a2+����+ak)��B = max(r1, r2, ����, rk)

		// ����н��������ı�����������O(nlogn)
		std::map<double, std::vector<int>> people; // ratio-->index
		for (int i = 0; i < quality.size(); i++) {
			double ratio = 1.0 * wage[i] / quality[i];
			people[ratio].push_back(i);
		}

		// ��С������ÿ�� ratio�������һ���飬��֤�����ڲ����ڸ���� ratio
		double result = std::numeric_limits<double>::max();

		std::map<int, int, std::greater<>> qualityStack;
		int qualitySum = 0;
		int kNum = 0;
		for (auto iter = people.begin(); iter != people.end(); iter++) {
			for (int i = 0; i < (*iter).second.size(); i++) {
				int index = (*iter).second[i];
				if (kNum < k) {
					// ���� k ����ֱ������
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
					// �պ�k��������һ�μ���
					double ratioMax = (*iter).first;
					double sum = ratioMax * qualitySum;
					if (result > sum) {
						result = sum;
					}
					kNum++;
				}
				else if(kNum > k) {
					// ɾһ������һ��
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
		// ����ѡ��� a1��a2��������ak �� k ���ˣ��乤������Ϊ q1��q2��������qk���������������Ϊ w1��w2��������wk
		// Ϊ��֤ k ���˵Ĺ��������� a1:a2:����:ak ���Ҿ���������������ʣ��������һ������ ratio������ ri = wi / qi��ȡ ri ����һ����Ϊ��׼����������
		// �������֧���Ĺ��� F = A*B������ A = (a1+a2+����+ak)��B = max(r1, r2, ����, rk)

		// ����н��������ı�����O(n)
		std::vector<People*> peopleRatio;
		//std::vector<People*> peopleQuality;
		for (int i = 0; i < quality.size(); i++) {
			People* tempPeople = new People(i, quality[i], wage[i]);
			peopleRatio.push_back(tempPeople);
			//peopleQuality.push_back(tempPeople);
		}

		// ����O(nlogn)
		std::sort(peopleRatio.begin(), peopleRatio.end(), [=](People* a, People *b) {
			return a->ratio < b->ratio;
		});
		//std::sort(peopleQuality.begin(), peopleQuality.end(), [=](People* a, People *b) {
		//	return a->quality > b->quality;
		//});

		// ��С������ÿ�� ratio�������һ���飬��֤�����ڲ����ڸ���� ratio
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
				// ɾһ������һ��
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