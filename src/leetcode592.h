/*
 * @Author: Bingyang Jin
 * @Date: 2022-07-27 01:11:54
 * @FilePath: /src/leetcode592.h
  * @Description: create the file and the solution
 */

#ifndef __leet_code_592__
#define __leet_code_592__

#include<iostream>
#include<string>
#include<vector>

class Fraction
{
public:
	Fraction() { sign = 1; numerator = 0; denominator = 1; }
	int sign;	// 符号
	int numerator;	// 分子
	int denominator;	// 分母

	// 判断ab的最大公约数，同时a>b
	int findGreatestCommonDivisorWithSort(int a, int b) {
		return a % b == 0 ? b : findGreatestCommonDivisorWithSort(b, a%b);
	}

	// 判断ab的最大公约数
	int findGreatestCommonDivisor(int a, int b) {
		return a > b ? findGreatestCommonDivisorWithSort(a, b) : findGreatestCommonDivisorWithSort(b, a);
	}

	int findLowestCommonMultiple(int a, int b) {
		int greatestCommonDivisor = findGreatestCommonDivisor(a, b);
		return a * b / greatestCommonDivisor;
	}

	// 两个分式相加
	int Add(Fraction *b) {
		int product = findLowestCommonMultiple(this->denominator, b->denominator);
		int thisTemp = product / this->denominator;
		int bTemp = product / b->denominator;
		
		this->denominator = product;
		this->numerator = this->numerator * thisTemp;

		b->denominator = product;
		b->numerator = b->numerator * bTemp;

		this->numerator = this->numerator*this->sign + b->numerator*b->sign;
		this->sign = 1;
		if (this->numerator < 0) {
			this->sign = -1;
			this->numerator *= -1;
		}

		minimisation();

		return 0;
	}

	// 最简化分式
	int minimisation() {
		if (this->numerator == 0) {
			this->denominator = 1;
			this->sign = 1;
			return 0;
		}
		int greatestCommonDivisor = findGreatestCommonDivisor(this->numerator, this->denominator);
		if (greatestCommonDivisor != 1) {
			this->numerator /= greatestCommonDivisor;
			this->denominator /= greatestCommonDivisor;
		}
		
		return 0;
	}
};

class Solution {
public:



	std::string fractionAddition(std::string expression) {
		std::vector<Fraction*> fractions;

		Fraction *crtFraction = new Fraction();
		bool isNumerator = true;
		int temp = 0;
		for (int i = 0; i < expression.size(); i++) {

			if (i == 0) {
				if (expression[i] != '+' && expression[i] != '-') {
					crtFraction->sign = 1;
					temp = temp * 10 + expression[i] - '0';
				}
				else {
					crtFraction->sign = expression[i] == '+' ? 1 : -1;
				}
			}
			else {
				if ((expression[i] == '+' || expression[i] == '-')) {
					crtFraction->denominator = temp;
					fractions.push_back(crtFraction);
					crtFraction = new Fraction();
					crtFraction->sign = expression[i] == '+' ? 1 : -1;
					isNumerator = true;
					temp = 0;
				}
				else if (expression[i] == '/') {
					isNumerator = false;
					crtFraction->numerator = temp;
					temp = 0;
				}
				else {
					temp = temp * 10 + expression[i] - '0';
				}
			}
		}
		crtFraction->denominator = temp;
		fractions.push_back(crtFraction);

		std::string resultStr = "";
		for (int i = 1; i < fractions.size(); i++) {
			fractions[0]->Add(fractions[i]);
		}

		if (fractions[0]->sign == -1) {
			resultStr += "-";
		}
		
		resultStr += std::to_string(fractions[0]->numerator) + "/" + std::to_string(fractions[0]->denominator);

		return resultStr;

	}
};

#endif // __leet_code_592__