#ifndef __leet_code_762__
#define __leet_code_762__

class Solution {
public:
	int countPrimeSetBits(int left, int right) {

		int result = 0;
		for (int i = left; i <= right; i++) {
			int sum = 0;
			int temp = i;
			while (temp >= 2) {
				sum += (temp % 2);
				temp = temp / 2;
			}
			sum += temp;
			switch (sum)
			{
			case 2:
			case 3:
			case 5:
			case 7:
			case 11:
			case 13:
			case 17:
			case 19:
			case 23: result++;
			default:
				break;
			}
		}

		return result;
	}
};

#endif // __leet_code_762__