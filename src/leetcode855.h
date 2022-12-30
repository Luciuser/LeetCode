/*
 * @Author: Bingyang Jin
 * @Date: 2022-12-30 08:58:04
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode855.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-12-30 14:49:19
 * @Editor: Bingyang Jin
 * @Description: create PRIORITY_QUEUE_METHOD, TIME 44ms, 97.40%, MEMORY 21.9MB and 14.93%
 */

#ifndef __leet_code_855__
#define __leet_code_855__

#include<iostream>
#include<unordered_map>
#include<queue>

class ExamRoom {
public:
	ExamRoom(int n) {
		seat_num = n;
	}

	int seat() {
		if (target.size() == 0) {
			valid.clear();
			left.clear();
			right.clear();

			target.emplace(std::pair<int, int>(-seat_num, seat_num)); // ȡ -2 Ϊ��༫�޵�
			valid[-seat_num] = 0;
			valid[0] = -1;
			right[-seat_num] = seat_num; // ȡ seat_num Ϊ�Ҳ༫�޵�
		}
		auto currentPair = target.top();
		target.pop();
		// �����Ѿ�ɾ�����ļ������λ��
		while (true){
			// ��ǰ current �Ѿ���ɾȥ
			if (currentPair.first + currentPair.second != valid[currentPair.first]) {
				currentPair = target.top();
				target.pop();
				continue;
			}
			else if(currentPair.first + currentPair.second==0 && valid[0] != -1){
				currentPair = target.top();
				target.pop();
				continue;
			}
			break;
		}

		// �ҵ��öε������Ҳඥ�㣬���õ�Ŀ�궥��
		int leftPoint = currentPair.first;
		int rightPoint = right[leftPoint];
		int currentTarget = currentPair.first + currentPair.second;

		// ������һ���� leftPoint �� currentTarget Ϊ���λ�ã��� [leftPoint, currentTarget] �� [currentTarget, rightPoint] ����������Ĳ��λ��
		int point1 = getMidPoint(leftPoint, currentTarget);
		int point2 = getMidPoint(currentTarget, rightPoint);

		// �������ȶ��к���Ӧ map
		if (leftPoint < 0 && rightPoint == seat_num) {
			target.emplace(std::pair<int, int>(currentTarget, seat_num - 1));
			point2 = seat_num - 1;
		}
		else {
			if (leftPoint >= 0) {
				target.emplace(std::pair<int, int>(leftPoint, point1 - leftPoint));
			}
			if (rightPoint < seat_num) {
				target.emplace(std::pair<int, int>(currentTarget, point2 - currentTarget));
			}
		}
		valid[leftPoint] = point1;
		valid[currentTarget] = point2;
		right[leftPoint] = currentTarget;
		left[currentTarget] = leftPoint;
		right[currentTarget] = rightPoint;
		left[rightPoint] = currentTarget;

		return currentTarget;
	}

	void leave(int p) {

		// �ҵ��� n ����ඥ����Ҳඥ��
		int leftPoint = left[p];
		int rightPoint = right[p];

		// ���ĵ� p ����Ч��
		valid[p] = -1;

		// �����µĲ����
		int mid = getMidPoint(leftPoint, rightPoint);
		if (leftPoint < 0) {
			mid = 0;
			leftPoint = mid - rightPoint;
		}
		else if (rightPoint == seat_num) {
			mid = seat_num - 1;
		}
		target.emplace(std::pair<int, int>(leftPoint, mid - leftPoint));
		valid[leftPoint] = mid;

		// ���� left �� right �� map
		left[rightPoint] = leftPoint;
		right[leftPoint] = rightPoint;

	}

private:

	int getMidPoint(int left, int right){
		return (left + right) / 2;
	}

	struct pair_cmp {
		bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
			if (a.second != b.second) {
				return a.second < b.second;
			}
			else {
				return a.first > b.first;
			}
		}
	};

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, pair_cmp> target; // ÿ�����λ�ã�������Ӧ��Ŀ�����λ�þ����Ŀ��λ�õĳ���
	std::unordered_map<int, int> valid; // ÿ����������Ӧ��Ŀ�����λ�ã������ж� target ��ǰ���Ž���Ƿ���Ч
	std::unordered_map<int, int>left;	// ÿ��������Ӧ������
	std::unordered_map<int, int>right; // ÿ��������Ӧ���Ҳ��
	int seat_num;
};

#endif // 