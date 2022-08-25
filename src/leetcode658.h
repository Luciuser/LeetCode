/*
 * @Author: Bingyang Jin
 * @Date: 2022-08-25 09:39:14
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1460.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2022-08-25 09:50:29
 * @Editor: Bingyang Jin
 * @Description: create SORT_METHOD, TIME 52ms, 22.20%, MEMORY 31.1MB and 17.34%
 */

 /*
 * @EditTime: 2022-08-25 10:14:32
 * @Editor: Bingyang Jin
 * @Description: create MIDDLE_METHOD, TIME 32ms, 71.38%, MEMORY 32.2MB and 8.08%
 */

 /*
 * @EditTime: 2022-08-25 10:26:39
 * @Editor: Bingyang Jin
 * @Description: create MIDDLE_METHOD, TIME 36ms, 50.35%, MEMORY 30.3MB and 68.54%
 */

#ifndef __leet_code_658__
#define __leet_code_658__

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

//#define SORT_METHOD // 使用c++标准库sort函数，时间复杂度O(nlogn)+O(n)+O(nlogn) = O(nlogn)，TIME 52ms, 22.20%, MEMORY 31.1MB and 17.34%
//#define MIDDLE_METHOD // 使用二分查找找到中间值，双指针左右递增，时间复杂度O(logn)+O(k) = O(logn+k)，TIME 32ms, 71.38%, MEMORY 32.2MB and 8.08%
#define MIDDLE_SIMPLE_METHOD // 官方二分查找+双指针法，更加简练，时间复杂度O(logn)+O(k) = O(logn+k)，TIME 36ms, 50.35%, MEMORY 30.3MB and 68.54%


#ifdef SORT_METHOD
class Solution {
public:
	std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
		std::sort(arr.begin(), arr.end(), [=](int a, int b) {
			int ax = abs(a - x);
			int bx = abs(b - x);
			if (ax == bx) {
				return a < b;
			}
			return ax < bx;
		});

		std::vector<int> result;
		for (int i = 0; i < k; i++) {
			result.push_back(arr[i]);
		}

		std::sort(result.begin(), result.end());

		return result;
	}
};
#endif // SORT_METHOD

#ifdef MIDDLE_METHOD
class Solution {
public:

	bool close(int a, int b, int x) {
		int ax = abs(a - x);
		int bx = abs(b - x);
		if (ax == bx) {
			return a < b;
		}
		return ax < bx;
	}

	std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
		std::vector<int>result;

		// 由于arr已经严格按照升序排列，因此可以采用二分法找到arr中第一个大于x的数
		auto middle = std::lower_bound(arr.begin(), arr.end(), x);
		auto iterLeft = middle - 1;
		auto iterRight = middle;

		if (iterRight == arr.begin()) {
			for (int i = 0; i < k; i++) {
				result.push_back(arr[i]);
			}
			return result;
		}

		std::vector<int>left;
		std::vector<int>right;
		while (k > 0) {
			if (iterRight == arr.end()) {
				for (int i = 0; i < k; i++) {
					left.push_back((*iterLeft));
					iterLeft--;
				}
				break;
			}
			if (iterLeft == arr.begin()) {

				bool isLeftClose = close((*iterLeft), (*iterRight), x);
				if (isLeftClose) {
					left.push_back((*iterLeft));
					k--;
					for (int i = 0; i < k; i++) {
						right.push_back((*iterRight));
						iterRight++;
					}
					break;
				}
				else {
					right.push_back((*iterRight));
					iterRight++;
					k--;
					continue;
				}
			}

			bool isLeftClose = close((*iterLeft), (*iterRight), x);
			if (isLeftClose) {
				left.push_back((*iterLeft));
				iterLeft--;
			}
			else {
				right.push_back((*iterRight));
				iterRight++;
			}
			k--;
		}

		for (int i = left.size() - 1; i >= 0; i--) {
			result.push_back(left[i]);
		}
		for (int i = 0; i < right.size(); i++) {
			result.push_back(right[i]);
		}

		return result;
	}
};
#endif // MIDDLE_METHOD

#ifdef MIDDLE_SIMPLE_METHOD
class Solution {
public:

	std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
		// 由于arr已经严格按照升序排列，因此可以采用二分法找到arr中第一个大于x的数
		int right = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
		int left = right - 1;

		while (k > 0) {
			if (left < 0) {
				right++;
			}
			else if (right >= arr.size()) {
				left--;
			}
			else if (x - arr[left] <= arr[right] - x) {
				left--;
			}
			else {
				right++;
			}
			k--;
		}

		return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);	// 第一个参数是vector.begin()，第二个参数是vector.end()
	}
};
#endif // MIDDLE_SIMPLE_METHOD


#endif // __leet_code_658__