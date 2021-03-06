// quick.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <stack>

#define	MAX	20

void q_sort(char *string, int left, int right);

int stack[MAX];
int top = -1;

int push(int value)
{
	if (top < MAX - 1) {
		stack[++top] = value;
	}
	else {
		return -1;
	}

	return 0;
}

int pop(int *pv)
{
	if (top < 0) {
		return -1;
	}

	*pv = stack[top--];

	return 0;
}

int empty()
{
	if (top < 0) {
		return 1;
	}

	return 0;
}

/**
 * quick sort use the middle element for partition
 * 看到更一般的做法是三数取中法，
 * 单纯取中值意义不大，直接转化为取首值
 */
void q_sort_mid(char *string, int left, int right)
{
	char partition;
	char temp;
	int  i, j, k, mid_pos;

	if (left < right) {
		i = left;
		j = right;
		mid_pos = (left + right) / 2;
		
		temp = string[left];
		string[left] = string[mid_pos];
		string[mid_pos] = temp;

		q_sort(string, left, right);
	}
}

void q_sort(char *string, int left, int right)
{
	char partition;
	char temp;
	int  i, j, k;

	if (left < right) {
		i = left;
		j = right + 1;
		partition = string[left];
		do {
			do {
				i++;
			} while (string[i] < partition);

			do {
				j--;
			} while (string[j] > partition);

			if (i < j) {
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		} while (i < j);
		
		temp = string[left];
		string[left] = string[j];
		string[j] = temp;

		printf("the quick sort result: ");
		for (k = left; k <= right; k++) {
			printf("%c", string[k]);
		}
		printf("\n");

		q_sort(string, left, j - 1);

		q_sort(string, j + 1, right);
	}
}

void q_sortV2(char *string, int left, int right)
{
	char partition;
	char temp;
	int  i, j, k;

	if (left < right) {
		i = left;
		j = right + 1;
		partition = string[left];
		do {
			do {
				j--;
			} while (i < j && string[j] >= partition);

			string[i] = string[j];

			do {
				i++;
			} while (i < j && string[i] <= partition);

			string[j] = string[i];
		} while (i < j);

		string[i] = partition;
		
		printf("the quick sort result: ");
		for (k = left; k <= right; k++) {
			printf("%c", string[k]);
		}
		printf("\n");

		q_sort(string, left, i - 1);

		q_sort(string, i + 1, right);
	}
}

int partition(char *string, int left, int right)
{
	int i = left;
	int j = right;
	char temp = string[i];

	while (i < j) {
		while (i < j && string[j] >= temp) {
			j--;
		}

		if (i < j) {
			string[i] = string[j];
		}

		while (i < j && string[i] <= temp) {
			i++;
		}

		if (i < j) {
			string[j] = string[i];
		}
	}

	string[i] = temp;

	return i;
}

void q_sortV3(char *string, int left, int right)
{
	int dp;

	if (left < right) {
		dp = partition(string, left, right);
		q_sortV3(string, left, dp - 1);
		q_sortV3(string, dp + 1, right);
	}
}


void q_sortV4(char *string, int left, int right)
{
	int dp;
	int current_left, current_right;
	int flag_right, flag_left;

	push(left);
	push(right);

	while (!empty()) {
		flag_right = pop(&current_right);
		flag_left  = pop(&current_left);
		if (flag_left > -1 && flag_right > -1) {
			dp = partition(string, current_left, current_right);

			if (dp > current_left) {
				push(current_left);
				push(dp - 1);
			}

			if (dp < current_right) {
				push(dp + 1);
				push(current_right);
			}
		}
	}
}

void q_sortV5(char *string, int left, int right)
{
	std::stack<int> s;
	int dp;
	int current_left, current_right;
	int flag_right, flag_left;

	s.push(left);
	s.push(right);
	
	while (!s.empty()) {
		current_right = s.top();
		s.pop();
		current_left = s.top();
		s.pop();
		
		dp = partition(string, current_left, current_right);

		if (dp > current_left) {
			s.push(current_left);
			s.push(dp - 1);
		}

		if (dp < current_right) {
			s.push(dp + 1);
			s.push(current_right);
		}
	}
}


void quick(char *string, int n)
{
	q_sort(string, 0, n - 1);
	//q_sortV2(string, 0, n - 1);
	//q_sortV3(string, 0, n - 1);
	//q_sortV4(string, 0, n - 1);
	//q_sortV5(string, 0, n - 1);
	//q_sort_mid(string, 0, n - 1);
	//q_sort_midV2(string, 0, n - 1);
}

int main()
{
	char string[MAX];
	int  count;

	printf("please inputh a string to sort ==> ");
	fgets(string, MAX, stdin);
	count = strlen(string);
	string[--count] = '\0';
	quick(string, count);
	printf("\nthe quick sorting algorithm's result: [%s]\n", string);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
