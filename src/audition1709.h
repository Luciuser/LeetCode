/*
 * @Author: Bingyang Jin
 * @Date: 2022-09-28 13:51:52
 * @Editor: Bingyang Jin
 * @FilePath: /src/audition1709.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-09-28 16:46:09
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_METHOD, TIME 0ms, 100.00%, MEMORY 6.1MB and 40.58%
 */

#ifndef __leet_code_audition_17_09__
#define __leet_code_audition_17_09__

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

class Solution {
public:
	int getKthMagicNumber(int k) {

		int result = 1;
		std::vector<int> ugly;
		ugly.push_back(1);
		int index1 = 0, index2 = 0, index3 = 0;
		for (int i = 1; i < k; i++) {
			int temp = 0;
			if (ugly[index1] * 3 < ugly[index2] * 5) {
				if (ugly[index1] * 3 < ugly[index3] * 7) {
					temp = ugly[index1] * 3;
					index1++;
				}
				else if(ugly[index1] * 3 > ugly[index3] * 7){
					temp = ugly[index3] * 7;
					index3++;
				}
				else {
					temp = ugly[index1] * 3;
					index1++;
					index3++;
				}
			}
			else if(ugly[index1] * 3 > ugly[index2] * 5){
				if (ugly[index2] * 5 < ugly[index3] * 7) {
					temp = ugly[index2] * 5;
					index2++;
				}
				else if(ugly[index2] * 5 > ugly[index3] * 7){
					temp = ugly[index3] * 7;
					index3++;
				}
				else {
					temp = ugly[index2] * 5;
					index2++;
					index3++;
				}
			}
			else {
				if (ugly[index1] * 3 < ugly[index3] * 7) {
					temp = ugly[index1] * 3;
					index1++;
					index2++;
				}
				else if(ugly[index1] * 3 > ugly[index3] * 7){
					temp = ugly[index3] * 7;
					index3++;
				}
				else {
					temp = ugly[index1] * 3;
					index1++;
					index2++;
					index3++;
				}
			}
			ugly.push_back(temp);
			result = temp;
		}

		return result;
	}
};

#endif // __leet_code_audition_17_09__