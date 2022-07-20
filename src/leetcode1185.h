#ifndef __leet_code_1728__
#define __leet_code_1728__

#include<iostream>
#include<algorithm>
#include<vector>

//#define COMPLICATE_METHODS // ����д��
#define SIMPLE_METHONDS // ��д��

#ifdef COMPLICATE_METHODS
class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		// ����1970��1��1����������

		// ��Ĺ���
		int sum = 4;
		for (int i = 1970; i < year; i++) {
			int yearSum = 0;
			if (i % 100 == 0) {
				if (i % 400 == 0) {
					yearSum = 366; // ����
				}
				else {
					yearSum = 365; // ƽ��
				}
			}
			else if (i % 4 == 0) {
				yearSum = 366; // ����
			}
			else {
				yearSum = 365; // ƽ��
			}

			sum = (sum + yearSum) % 7;
		}

		// �µĹ���
		int run;
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				run = 29; // ����
			}
			else {
				run = 28; // ƽ��
			}
		}
		else if (year % 4 == 0) {
			run = 29; // ����
		}
		else {
			run = 28; // ƽ��
		}

		for (int i = 1; i < month; i++) {
			switch (i)
			{
			case 1: sum += 31; break;
			case 2: sum += run; break;
			case 3: sum += 31; break;
			case 4: sum += 30; break;
			case 5: sum += 31; break;
			case 6: sum += 30; break;
			case 7: sum += 31; break;
			case 8: sum += 31; break;
			case 9: sum += 30; break;
			case 10: sum += 31; break;
			case 11: sum += 30; break;
			case 12: sum += 31; break;
			default:
				break;
			}
		}

		// �յĹ���
		sum += day;
		sum--;
		sum = sum % 7;

		switch (sum)
		{
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
		default:
			break;
		}

		return "";
	}
};
#endif // COMPLICATE_METHODS

#ifdef SIMPLE_METHONDS
class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		std::vector<std::string> week = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
		std::vector<int> monthDays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
		/* �������֮ǰ����ݵ��������� */
		int days = 365 * (year - 1971) + (year - 1969) / 4;
		/* ��������У������·�֮ǰ���·ݵ��������� */
		for (int i = 0; i < month - 1; ++i) {
			days += monthDays[i];
		}
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
			days += 1;
		}
		/* �����·��е��������� */
		days += day;
		return week[(days + 3) % 7];
	}
};
#endif // SIMPLE_METHONDS



#endif // !__leet_code_1728__