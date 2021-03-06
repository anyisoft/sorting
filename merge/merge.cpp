// merge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#define	MAX	20

void merge(char *dest, const char *src, int left, int middle, int right)
{
	int i, j, k;
	for (i = left, j = middle + 1, k=i; i <= middle && j <= right;) {
		if (src[i] < src[j]) {
			dest[k++] = src[i++];
		}
		else {
			dest[k++] = src[j++];
		}
	}

	while (i <= middle) {
		dest[k++] = src[i++];
	}

	while (j <= right) {
		dest[k++] = src[j++];
	}
}

void merge_sort(char *dest, const char *src, int left, int right)
{
	char presort[MAX];
	int m;

	memset(presort, 0, sizeof(presort));

	if (left < 0 || left > right) {
		return;
	}

	if (left == right) {
		dest[left] = src[left];
		return;
	}

	m = (left + right) / 2;

	merge_sort(presort, src, left, m);
	merge_sort(presort, src, m + 1, right);

	merge(dest, presort, left, m, right);
}

int main()
{
	char string[MAX];
	char result[MAX];
	int  count;

	memset(string, 0, sizeof(string));
	memset(result, 0, sizeof(result));

	printf("please inputh a string to sort ==> ");
	fgets(string, MAX, stdin);
	count = strlen(string);
	string[--count] = '\0';
	merge_sort(result, string, 0, count-1);
	printf("\nthe merge sorting algorithm's result: [%s]\n", result);
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
