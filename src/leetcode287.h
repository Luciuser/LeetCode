/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-04 16:11:59
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode287.h
 * @Description: create the file
 */

#ifndef __leet_code_287__
#define __leet_code_287__

 // ��ĿҪ�󣺲����޸��������nums��ͬʱ�ռ临�Ӷ�ΪO(1)

#include<iostream>
#include<vector>

//#define VIOLENT_METHOD // �����ⷨ����ʱ

#ifdef VIOLENT_METHOD
class Solution {
public:
	int findDuplicate(std::vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] == nums[j]) {
					return nums[i];
				}
			}
		}
		return -1;
	}
};
#endif // VIOLENT_METHOD

#endif // __leet_code_287__