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
		
		// 由题解方案，状态压缩+基于哈希表的记忆化搜索+动态规划
		
		// 计算目标结果的状态压缩
		// 状态压缩即，其取模结果为 [1, batchSize-1]，每个结果的频率不超过30，可用 5 位表示，共计可用一个 64 位数表示
		// 从右侧开始，右侧 5 位表示
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

		// 类值初始化
		batch_size_ = batchSize;
		record_[0] = 0;

		return dfs(mask) + a0;

	}

private:
	// 对于状态压缩 mask 而言，模为 i 的频率+1
	void addOneWithMod(long long &mask, const int i) {
		long long target = 1;
		mask += target << (5 * (i - 1));
	}

	// 对于状态压缩 mask 而言，获得模为 i  的频率
	int getFrequenceWithMod(const long long &mask, const int i) {
		return (mask >> (i - 1) * 5) & 31;
	}

	// 对于状态压缩 mask 而言，获得枚举模为 i  时的前一个 mask 值
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

	// 基于一个状态压缩后的mask，去枚举所有值进行动态规划
	// 其中 mask 是状态压缩结果，sum 是该状态下的总人数
	int dfs(const long long &mask) {
		// 记忆化搜索
		if (record_.count(mask) != 0) {
			return record_[mask];
		}

		// 根据动态规划特征，从所有可以转移过来的情况开始枚举
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