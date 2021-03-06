// bubble.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void output_vector(std::vector<T> vec)
{
	std::vector<T>::iterator iter = vec.begin();
	std::vector<T>::iterator end = vec.end();
	for (; iter!=end; iter++) {
		std::cout << *iter << ' ';
	}
	std::cout << std::endl;
}

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

void bubble(int *pia, int count)
{
	int i, j, temp;

	for (j = count; j > 1; j--) {
		for (i = 0; i < j - 1; i++) {
			if (pia[i + 1] < pia[i]) {
				temp = pia[i + 1];
				pia[i + 1] = pia[i];
				pia[i] = temp;
			}
		}
		printf("temp result: ");
		output_int_array(pia, count);
	}
}

void bubbleV2(int *pia, int count)
{
	int i, temp, done;

	done = 0;
	while (!done) {
		done = 1;
		for (i = 0; i < count - 1; i++) {
			if (pia[i+1] < pia[i]) {
				temp = pia[i + 1];
				pia[i + 1] = pia[i];
				pia[i] = temp;
				done = 0;
			}
		}

		if (!done) {
			printf("temp result: ");
			output_int_array(pia, count);
		}
	}
}

template<typename T>
void bubbleV2(T *pa, int count)
{
	T temp;
	int i, done;

	done = 0;
	while (!done) {
		done = 1;
		for (i = 0; i < count - 1; i++) {
			if (pa[i + 1] < pa[i]) {
				temp = pa[i + 1];
				pa[i + 1] = pa[i];
				pa[i] = temp;
				done = 0;
			}
		}

		if (!done) {
			printf("temp result: ");
			output_array<double>(pa, count);
		}
	}
}

int main()
{
	double da[10] = { 33.35, 48.50, 88.90, 9.92, 87.89, 32.34, 10.12, 42.44, 100.01, 56.58 };
	//int ia[10] = { 33, 48, 88, 9, 87, 32, 10, 42, 99, 56 };
	int  count;

	std::vector<double> vd = { 33.36, 48.51, 88.91, 9.93, 87.9, 32.35, 10.13, 42.45, 100.02, 56.59 };

	//bubble(ia, 10);
	//bubbleV2(ia, 10);
	//bubbleV2<double>(da, 10);
	//std::sort(std::begin(vd), std::end(vd));
	std::sort(std::begin(vd), std::end(vd), std::greater<>());
	
	printf("the final result: ");
	//output_int_array(ia, 10);
	//output_array(da, 10);
	output_vector(vd);
	//std::copy(std::begin(vd), std::end(vd), std::ostream_iterator<double> {std::cout, " "});
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
