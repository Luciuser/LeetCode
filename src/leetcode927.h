/*
 * @Author: Bingyang Jin
 * @Date: 2022-10-06 10:14:37
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode927.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-10-06 11:26:13
 * @Editor: Bingyang Jin
 * @Description: create VALID_END_METHOD, TIME 40ms, 40.97%, MEMORY 37.9MB and 75.35%
 */

#ifndef __leet_code_927__
#define __leet_code_927__

#include<iostream>
#include<vector>

class Solution {
public:

	bool sameString(const std::vector<int>&arr, const int end_a, const int end_b, const int end_c) {
		int index = 0;
		int a_length = end_a + 1;
		int b_length = end_b - end_a;
		int c_length = end_c - end_b;

		int a = 0, b = 0, c = 0;

		while (true) {
			if (index + 1 > a_length && index + 1 > b_length && index + 1 > c_length) {
				break;
			}

			if (index + 1 > a_length) {
				a = 0;
			}
			else {
				a = arr[end_a - index];
			}

			if (index + 1 > b_length) {
				b = 0;
			}
			else {
				b = arr[end_b - index];
			}

			if (index + 1 > c_length) {
				c = 0;
			}
			else {
				c = arr[end_c - index];
			}

			index++;

			if (a == b && b == c) {
				continue;
			}
			else {
				return false;
			}
		}

		return true;
	}

	void turnRight(const std::vector<int>& arr, int &valid_b, int &valid_c, int & end_b, int &end_c) {
		// ���¼��� valid_b
		if (valid_b == 1 && arr[end_b] == 0) {
			// ����������ڶ��ξ�Ϊ0����ʱ���� end_b ���ı� valid_b
		}
		else {
			valid_b++;
		}

		// ���¼��� valid_c
		end_b++;
		if (arr[end_b] == 0) {
			// ����������� end_b ��һλΪ 0 ʱ��valid_c ����
		}
		else {
			// �� end_b ��һλΪ 1 ʱ���������¼��� valid_c
			valid_c--;
			int tempZero = end_b + 1;
			while (true) {
				if (tempZero > end_c) {
					// �����������Ȼû�г����µ� 1
					valid_c = 1;
					break;
				}
				if (arr[tempZero] == 1) {
					// �������µ�1
					break;
				}
				else {
					valid_c--;
				}
				tempZero++;
			}
		}
	}

	std::vector<int> threeEqualParts(std::vector<int>& arr) {

		// ��Ҫ������ͬ�������ε���Ч����һ��Ҫ��ͬ
		// �� end_a ����һλʱ��valid_a �����������һλ��valid_b ������߼���һλ��
		//			��ʱ��Ҫ�������� end_b ��ʹ�� valid_a �� valid_b ���ֲ���
		//					�� valid_a == valid_b ʱ��ȥ�ж� valid_c ����������������Ƿ�����ַ�����ȵ��ж�
		//					�� valid_a > valid_b ʱ������ end_b������ valid_b
		//					�� valid_a < valid_b ʱ������ end_b��valid_b ��Խ��Խ�󣬴�ʱ���ˣ���ʼ�������� end_a
		// �� valid_a > valid_b && valid_a > valid_c ʱ���Ѿ��޷���ͬ������ʧ�ܽ��

		// ���ε���Ч���֣�Ĭ�Ͼ�Ϊ1
		int valid_a = 1;
		int valid_b = 1;
		int valid_c = 1;
		// ��������ε���Ч����
		int temp = -1;
		for (int i = 2; i < arr.size(); i++) {
			if (arr[i] == 1) {
				temp = i;
				break;
			}
		}
		if (temp != -1) {
			valid_c = arr.size() - temp;
		}

		// ���εĽ���λ��
		int end_a = 0;
		int end_b = 1;
		int end_c = arr.size() - 1;

		while (true) {
			std::cout << end_a << " " << end_b << " " << end_c << std::endl;
			if (valid_a > valid_b && valid_a > valid_c) {
				return std::vector<int>(2, -1);
			}
			if (end_b == arr.size() - 1) {
				return std::vector<int>(2, -1);
			}

			if (valid_a == valid_b) {
				if (valid_b == valid_c) {
					// �����ַ����ж�
					if (sameString(arr, end_a, end_b, end_c)) {
						std::vector<int> result = { end_a, end_b + 1 };
						return result;
					}
					else {
						turnRight(arr, valid_a, valid_b, end_a, end_b);
					}
				}
				else if(valid_b < valid_c){
					// ��ʱ��һ�κ͵ڶ����п�����ͬ����һ��������β���ͬ����� end_b ��������
					turnRight(arr, valid_b, valid_c, end_b, end_c);
				}
				else {
					// ��ʱ���� end_b��valid_c ֻ���ø�С���޷����� valid_b == valid_c����� end_a ��������
					turnRight(arr, valid_a, valid_b, end_a, end_b);
				}
			}
			else if (valid_a < valid_b) {
				// end_a ��������
				turnRight(arr, valid_a, valid_b, end_a, end_b);
			}
			else {
				// end_b ��������
				turnRight(arr, valid_b, valid_c, end_b, end_c);
			}

		}

		return std::vector<int>(2, -1);
	}
};

#endif // __leet_code_927__