// shell.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#define	MAX	20

void shell(char *string, int count)
{
	int pos;
	int offset;
	int i, j;
	char temp;

	offset = count / 2;
	while (offset != 0) {
		for (j = offset; j < count; j++) {
			temp = string[j];
			pos = j - offset;
			while (temp < string[pos] && pos >= 0 && j <= count) {
				string[pos + offset] = string[pos];
				pos = pos - offset;
			}
			string[pos + offset] = temp;
		}
		printf("current: [%s]\n", string);
		offset = offset / 2;
	}
}

/**
 * Shell 排序
 * 自定义每次处理的间隔量
 */
void shellV2(char *string, int count)
{
	//int offset_a[6] = { 11, 7, 5, 3, 2, 1 };
	int offset_a[6] = { 13, 8, 5, 3, 2, 1 };	// fibonacci serial
	int pos;
	int offset;
	int i, j;
	char temp;

	for (i = 0; i < 6; i++) {
		offset = offset_a[i];
		for (j = offset; j < count; j++) {
			temp = string[j];
			pos = j - offset;
			while (temp < string[pos] && pos >= 0 && j <= count) {
				string[pos + offset] = string[pos];
				pos = pos - offset;
			}
			string[pos + offset] = temp;
		}
		printf("current: [%s]\n", string);
		offset = offset / 2;
	}
}

int main()
{
	char string[MAX];
	int  count;

	printf("please inputh a string to sort ==> ");
	fgets(string, MAX, stdin);
	count = strlen(string);
	string[--count] = '\0';
	//shell(string, count);
	shellV2(string, count);
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
