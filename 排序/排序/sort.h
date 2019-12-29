#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
void InsertSort(int* arr, int n)//升序
{
	for (int i = 0; i < n - 1; i++)//多趟插入排序（设第一个数为有序数组，从第二个数开始向有序数组里插入）
	{
		//单趟（相当于向一个已经有序的数组中插入一个数）
		int end = i;
		int temp = arr[i + 1];
		while (end >= 0)
		{
			if (temp < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = temp;
	}
}
void ShallSort(int* arr, int n)//先预排序，再进行插入排序
//随着循环，gap越来越小，最后为1的时候就是插入排序
{
	for (int gap = n / 3; gap > 0; gap = gap/3 +1)//为什么不能加1....
	{
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int temp = arr[end + gap];
			while (end >= 0)
			{
				if (temp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
					break;
			}
			arr[end + gap] = temp;
		}
	}	
}
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	int min_index = 0;
	int max_index = 0;
	for (size_t i = 0; i < (n-1)/2; i++)
	{
		begin = i;
		end = n - i - 1;
		while (begin < end)
		{
			if (arr[begin] < arr[min_index])
			{
				min_index = begin;
			}
			if (arr[begin] > arr[max_index])
			{
				max_index = begin;
			}
			begin++;
		}
		swap(&arr[i], &arr[min_index]);
		swap(&arr[n - i - 1], &arr[max_index]);
	}
}
int partone1(int* arr, int left, int right)//左右指针法
{
	int key = arr[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && arr[left] <= key)
			left++;
		while (left < right && arr[right] >= key)
			right--;
		if (left < right)
		{
			swap(&arr[left], &arr[right]);
		}
	}
	swap(&arr[left], &arr[key_index]);
	return left;
}
void select_mid(int* arr, int left, int right)//将中间值换到right的位置上去
{
	int mid = left + (right - left) / 2;
	if (arr[mid] > arr[left] && arr[mid] < arr[right])
		swap(&arr[mid], &arr[right]);
	if (arr[mid] < arr[left] && arr[mid] > arr[right])
		swap(&arr[mid], &arr[right]);
	if (arr[left] > arr[right] && arr[left] < arr[mid])
		swap(&arr[left], &arr[right]);
	if (arr[left] < arr[right] && arr[left] > arr[mid])
		swap(&arr[left], &arr[right]);
}

int partone2(int* arr, int left, int right)//挖坑法
{
	int key = arr[right];
	while (left < right)
	{
		while (left < right && arr[left] < key)
		{
			left++;
		}
		arr[right] = arr[left];
		while (left < right && arr[right] > key)
		{
			right--;
		}
		arr[left] = arr[right];
	}
	arr[left] = key;
	return left;
}
int partSort3(int*arr, int left, int right)
{
	int key = arr[right];
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (arr[cur] < key && prev++ != cur)
		{
			swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	prev++;
	swap(&arr[prev], &arr[cur]);
	return prev;
}


void QuickSort(int* arr, int left, int right)
{
	select_mid(arr, left, right);//优化一：三个数取中间值，避免发生产生最坏的情况（时间复杂度为O(N^2)）
	int key = arr[right];
	if (left > right)
		return;
	if (right - left + 1 < 10)//二次优化：当所剩的区间很小的时候用插入排序。
	{
		InsertSort(arr + left, right - left + 1);
		return;
	}
	int key_index = partSort3(arr, left, right);
	if (left < key_index - 1);
		QuickSort(arr, left, key_index - 1);
	if (right > key_index + 1)
		QuickSort(arr, key_index + 1, right);
}

void Merge(int* arr, int left, int mid, int right, int* temp)
//比较两段区间中的元素，将较小的取下来放进临时数组temp中
//[left, mid] [mid+1, right]
//再将其放回原数组中
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
			temp[i++] = arr[begin1++];
		else
			temp[i++] = arr[begin2++];
	}
	//if (begin1 == end1)
	{
		while (begin2 <= end2)
		{
			temp[i++] = arr[begin2++];
		}
	}
	//if (begin2 == end2)
	{
		while (begin1 <= end1)
		{
			temp[i++] = arr[begin1++];
		}
	}
	memcpy(arr + left, temp + left, sizeof(int)*(right - left + 1));
}
void _Margesort(int* arr, int left, int right, int* temp)
{
	if (left == right)
		return;
	int mid = left + (right - left) / 2;
	_Margesort(arr, left, mid, temp);//使左边有序
	_Margesort(arr, mid + 1, right, temp);//使右边有序
	Merge(arr, left, mid, right, temp);//归并两个有序的序列
}
void MargeSort(int *arr,int n)
{
	int *temp = (int*)malloc(sizeof(int)* n);//开辟一个临时数组
	if (temp == NULL)
		return ;
	_Margesort(arr, 0, n - 1,temp);
	free(temp);
}

void Print(int* arr, int _size)
{
	int i = 0;
	for (i = 0; i < _size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test()
{

	int array[] = { 1, 9, 3, 0, 4, 2, 5, 7, 8 ,6};
	int size = sizeof(array) / sizeof(int);
	//InsertSort(array, size);
	//Print(array,size);
	//ShallSort(array, size);
	//Print(array, size);
	//SelectSort(array, size);
	//Print(array, size);
	//int x = partone1(array, 0, 9);
	QuickSort(array, 0, 9);
	Print(array, size);
	//MargeSort(array, size);
	//Print(array, size);
}