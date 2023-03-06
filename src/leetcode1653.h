/*
 * @Author: Bingyang Jin
 * @Date: 2023-03-06 12:05:46
 * @Editor: Bingyang Jin
 * @FilePath: /src/leetcode1653.h
 * @Description: create the file
 */

 /*
 * @EditTime: 2023-03-05 12:29:20
 * @Editor: Bingyang Jin
 * @Description: create DYNAMIC_PROGTAMMING_METHOD, TIME 68ms, 80.39%, MEMORY 21.5MB and 81.37%
 */

#ifndef __leet_code_1653_h__ 
#define __leet_code_1653_h__

#include<iostream>
#include<string>

class Solution {
public:
	int minimumDeletions(std::string s) {
		// ��̬�滮
		// �� dp_a[i] ��ʾǰ i ����Ϊƽ�⣬����һ���ַ�Ϊ a ʱ��С��ɾ��������
		// �� dp_b[i] ��ʾǰ i ����Ϊƽ�⣬����һ���ַ�Ϊ b ʱ��С��ɾ��������
		// ��˶��ڵ� i ���ַ�����
		// ���� dp_a������ dp_a ֻ�ܸ�����һ���ַ�Ϊ a ���������˴�ʱ�е��ƹ�ʽΪ��
		//			dp_a[i] = dp_a[i-1],  if s[i] == 'a'
		//			dp_a[i] = dp_a[i-1] + 1,  if s[i] == 'b'	// ɾ���� i ����
		// ���� dp_b��dp_b �����������������ת�ƶ�������˴�ʱ�е��ƹ�ʽΪ��
		//			dp_b[i] = min(dp_a[i-1], dp_b[i-1] + 1),  if s[i] == 'a'
		//			dp_b[i] = min(dp_a[i-1], dp_b[i-1]),  if s[i] == 'b'

		int dp_a = 0;
		int dp_b = 0;
		// ��ʼ��
		if (s[0] == 'a') {
			dp_b = 1;
		}
		else if (s[0] == 'b') {
			dp_a = 1;
		}
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == 'a') {
				dp_b = dp_a < dp_b + 1 ? dp_a : dp_b + 1;
			}
			else if (s[i] == 'b') {
				dp_b = dp_a < dp_b ? dp_a : dp_b;
				dp_a++;
			}
		}

		return dp_a < dp_b ? dp_a : dp_b;
	}
};

#endif // __leet_code_1653_h__