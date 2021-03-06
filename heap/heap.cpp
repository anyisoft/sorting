// heap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

void adjust_heap(int *heap, int root, int len)
{
	int done;
	int j;
	int temp;

	j = 2 * root;
	temp = heap[root];
	done = 0;

	while (j <= len && !done) {
		if (j < len) {
			if (heap[j] < heap[j + 1]) {
				j++;
			}
		}

		if (temp >= heap[j]) {
			done = 1;
		}
		else {
			heap[j / 2] = heap[j];
			j = 2 * j;
		}
	}
	heap[j/2] = temp;
}

void heap(int *heap, int len)
{
	int i, j, temp;

	for (i = (len / 2); i >= 1; i--) {
		adjust_heap(heap, i, len);
	}
	printf("\nheap is: ");
	for (j = 1; j < 10; j++) {
		printf("[%d] ", heap[j]);
	}
	printf("\n");

	for (i = len - 1; i >= 1; i--) {
		temp = heap[1];
		heap[1] = heap[i+1];
		heap[i+1] = temp;

		adjust_heap(heap, 1, i);
		printf("\ncurrent: ");
		for (j = 1; j < 10; j++) {
			printf("[%d] ", heap[j]);
		}
	}
}

int main()
{
	int data[10] = { 0, 5, 6, 4, 8, 2, 3, 7, 1, 9 };
	int i;

	printf("binary tree: ");
	for (i = 1; i < 10; i++) {
		printf("[%d] ", data[i]);
	}

	heap(data, 9);

	printf("\n\nthe sorted: ");
	for (i = 1; i < 10; i++) {
		printf("[%d] ", data[i]);
	}
	printf("\n");
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
