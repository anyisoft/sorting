// quick.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#define	MAX	20

/**
 * quick sort use the middle element for partition
 * 从左扫描，如果比中间元素小就互换，直到中间
 * 从右扫描，如果比中间元素大就互换，直到中间
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
		
		while (i < mid_pos) {
			if (string[i] > string[mid_pos]) {
				temp = string[i];
				string[i] = string[mid_pos];
				string[mid_pos] = temp;
			}

			i++;
		}

		while (j > mid_pos) {
			if (string[j] < string[mid_pos]) {
				temp = string[j];
				string[j] = string[mid_pos];
				string[mid_pos] = temp;
			}

			j--;
		}

		printf("the quick sort result: ");
		for (k = left; k <= right; k++) {
			printf("%c", string[k]);
		}
		printf("\n");

		q_sort_mid(string, left, mid_pos);

		q_sort_mid(string, mid_pos + 1, right);
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

void quick(char *string, int n)
{
	//q_sort(string, 0, n - 1);
	q_sort_mid(string, 0, n - 1);
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
	printf("\nthe shell sorting algorithm's result: [%s]\n", string);
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
