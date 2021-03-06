// insertion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

template<typename T>
void output_array(T *pa, int count)
{
	for (int i = 0; i < count; i++) {
		std::cout << pa[i] << ' ';
	}
	std::cout << std::endl;
}

void output_int_array(int *pia, int count)
{
	for (int i = 0; i < count; i++) {
		printf("%d ", pia[i]);
	}
	printf("\n");
}

void insert(int *pia, int count)
{
	int i, j, temp;

	for (i = 1; i < count; i++) {
		temp = pia[i];
		j = i - 1;

		while (j >= 0 && temp < pia[j]) {
			pia[j + 1] = pia[j];
			j--;
		}
		pia[j + 1] = temp;
		printf("temp result: ");
		output_int_array(pia, count);
	}
}

template<typename T>
void insert(T *pa, int count)
{
	int i, j;
	T temp;

	for (i = 1; i < count; i++) {
		temp = pa[i];
		j = i - 1;

		//while (j >= 0 && temp < pa[j]) {
		while (j >= 0 && temp > pa[j]) {
			pa[j + 1] = pa[j];
			j--;
		}
		pa[j + 1] = temp;
		printf("temp result: ");
		output_array<T>(pa, count);
	}
}

int main()
{
	double da[10] = { 33.33, 48.48, 88.88, 9.9, 87.87, 32.32, 10.1, 42.42, 99.99, 56.56 };
	//int ia[10] = { 33, 48, 88, 9, 87, 32, 10, 42, 99, 56 };
	int  count;

	//insert(ia, 10);
	insert<double>(da, 10);

	printf("the final result: ");
	//output_int_array(ia, 10);
	output_array<double>(da, 10);
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
