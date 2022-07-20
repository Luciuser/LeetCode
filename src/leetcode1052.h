#ifndef __leet_code_1021__
#define __leet_code_1021__

#include<iostream>
#include<vector>

class Solution {
public:
	int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
		// ���Ž�ɷ�Ϊ�����֣��ϰ�ԭ��������ʱ������ͻ�(base) + �ϰ�ʹ�ü��ܺ�����������ͻ�(add)
		// ���� base �ǹ̶�ֵ���� add ��Ҫ������Ž��

		int base = 0;
		int add = 0;
		int temp = 0;
		
		int n = customers.size();
		std::vector<int> angryCustomers;

		for (int i = 0; i < n; i++) {
			if (i < minutes) {
				if (grumpy[i] == 0) {
					base += customers[i];
					angryCustomers.push_back(0);
				}
				else {
					temp += customers[i];
					add = temp;
					angryCustomers.push_back(customers[i]);
				}
			}
			else {
				if (grumpy[i] == 0) {
					base += customers[i];
					temp -= angryCustomers[0];
					angryCustomers.push_back(0);
				}
				else {
					temp += customers[i];
					temp -= angryCustomers[0];
					if (temp > add) {
						add = temp;
					}
					angryCustomers.push_back(customers[i]);
				}
				angryCustomers.erase(angryCustomers.begin());
			}
		}

		return base + add;
	}
};

#endif