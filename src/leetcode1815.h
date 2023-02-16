/*
 * @Author: Bingyang Jin
 * @Date: 2023-01-21 10:26:13
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1815.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-02-16 14:51:16
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGRAMMING_METHOD, TIME 460ms, 29.95%, MEMORY 54.7MB and 24.64%
 */

#ifndef __leet_code_1815_h__
#define __leet_code_1815_h__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	int maxHappyGroups(int batchSize, std::vector<int>& groups) {
		
		// ����ⷽ����״̬ѹ��+���ڹ�ϣ��ļ��仯����+��̬�滮
		
		// ����Ŀ������״̬ѹ��
		// ״̬ѹ��������ȡģ���Ϊ [1, batchSize-1]��ÿ�������Ƶ�ʲ�����30������ 5 λ��ʾ�����ƿ���һ�� 64 λ����ʾ
		// ���Ҳ࿪ʼ���Ҳ� 5 λ��ʾ
		long long mask = 0;
		int a0 = 0;
		for (int i = 0; i < groups.size(); i++) {
			int mod = groups[i] % batchSize;
			if (mod == 0) {
				a0++;
			}
			else {
				addOneWithMod(mask, mod);
			}
		}

		// ��ֵ��ʼ��
		batch_size_ = batchSize;
		record_[0] = 0;

		return dfs(mask) + a0;

	}

private:
	// ����״̬ѹ�� mask ���ԣ�ģΪ i ��Ƶ��+1
	void addOneWithMod(long long &mask, const int i) {
		long long target = 1;
		mask += target << (5 * (i - 1));
	}

	// ����״̬ѹ�� mask ���ԣ����ģΪ i  ��Ƶ��
	int getFrequenceWithMod(const long long &mask, const int i) {
		return (mask >> (i - 1) * 5) & 31;
	}

	// ����״̬ѹ�� mask ���ԣ����ö��ģΪ i  ʱ��ǰһ�� mask ֵ
	long long getBeforeMaskWithMod(const long long &mask, const int i) {
		long long target = 1;
		return mask - (target << (5 * (i - 1)));
	}

	int getSumFromMask(const long long &mask) {
		int result = 0;
		for (int i = 1; i < batch_size_; i++) {
			result += i * getFrequenceWithMod(mask, i);
		}
		return result;
	}

	// ����һ��״̬ѹ�����mask��ȥö������ֵ���ж�̬�滮
	// ���� mask ��״̬ѹ�������sum �Ǹ�״̬�µ�������
	int dfs(const long long &mask) {
		// ���仯����
		if (record_.count(mask) != 0) {
			return record_[mask];
		}

		// ���ݶ�̬�滮�����������п���ת�ƹ����������ʼö��
		int min = 0;
		for (int i = 1; i < batch_size_; i++) {
			if (getFrequenceWithMod(mask, i) >= 1) {
				int temp = dfs(getBeforeMaskWithMod(mask, i));
				if (getSumFromMask(mask) % batch_size_ == i % batch_size_) {
					temp++;
				}
				if (temp > min) {
					min = temp;
				}
			}
		}

		record_[mask] = min;
		return min;
	}

	int batch_size_;
	std::unordered_map<long long, int> record_;
};

#endif // __leet_code_1815_h__