#ifndef __leet_code_1728__
#define __leet_code_1728__

#include<iostream>
#include<algorithm>
#include<vector>

//#define COMPLICATE_METHODS // 复杂写法
#define SIMPLE_METHONDS // 简单写法

#ifdef COMPLICATE_METHODS
class Solution {
public:
	std::string dayOfTheWeek(int day, int month, int year) {
		// 考虑1970年1月1日是星期四

		// 年的贡献
		int sum = 4;
		for (int i = 1970; i < year; i++) {
			int yearSum = 0;
			if (i % 100 == 0) {
				if (i % 400 == 0) {
					yearSum = 366; // 闰年
				}
				else {
					yearSum = 365; // 平年
				}
			}
			else if (i % 4 == 0) {
				yearSum = 366; // 闰年
			}
			else {
				yearSum = 365; // 平年
			}

			sum = (sum + yearSum) % 7;
		}

		// 月的贡献
		int run;
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				run = 29; // 闰年
			}
			else {
				run = 28; // 平年
			}
		}
		else if (year % 4 == 0) {
			run = 29; // 闰年
		}
		else {
			run = 28; // 平年
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

		// 日的贡献
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
		/* 输入年份之前的年份的天数贡献 */
		int days = 365 * (year - 1971) + (year - 1969) / 4;
		/* 输入年份中，输入月份之前的月份的天数贡献 */
		for (int i = 0; i < month - 1; ++i) {
			days += monthDays[i];
		}
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && month >= 3) {
			days += 1;
		}
		/* 输入月份中的天数贡献 */
		days += day;
		return week[(days + 3) % 7];
	}
};
#endif // SIMPLE_METHONDS



#endif // !__leet_code_1728__