/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-23 10:33:13
 * @FilePath: /src/swordOfferII115.h
  * @Description: create the file and HASH_METHOD
 */

#ifndef __sword_offer_II_115__
#define __sword_offer_II_115__

#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
	bool sequenceReconstruction(std::vector<int>& nums, std::vector<std::vector<int>>& sequences) {

		if (nums.size() == 1 && sequences.size() == 1) {
			return true;
		}

		std::unordered_map<int, int>appear;
		std::unordered_map<int, int> seqs;

		int before = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int current = nums[i];
			seqs[before] = current;
			before = current;
		}
		seqs[before] = -1;

		for (int i = 0; i < sequences.size(); i++) {
			int before = sequences[i][0];
			for (int j = 1; j < sequences[i].size(); j++) {
				int current = sequences[i][j];
				if (current == seqs[before]) {
					appear[before] = 1;
				}
				before = current;
			}
		}

		if (appear.size() == nums.size() - 1) {
			return true;
		}
		return false;
	}
};

#endif // __sword_offer_II_115__